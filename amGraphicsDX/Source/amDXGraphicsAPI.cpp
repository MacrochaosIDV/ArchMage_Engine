#include "amDXGraphicsAPI.h"
#include <amVertex.h>
#include <amMaterial.h>
#include <amMesh.h>

namespace amEngineSDK {

  D3D_DRIVER_TYPE  g_driverType = D3D_DRIVER_TYPE_NULL;
  D3D_FEATURE_LEVEL g_featureLevel = D3D_FEATURE_LEVEL_11_0;


  amDXGraphicsAPI::~amDXGraphicsAPI() {}

  void 
  amDXGraphicsAPI::createVertexBuffer(int32 nVertex, int32 vertexSize) {
    nVertex;
    vertexSize;
  }

  void 
  amDXGraphicsAPI::CleanupDevice() {

  }

  void 
  amDXGraphicsAPI::init(void* _hWnd) {
    
    initSystems(_hWnd);
    initContent();
  }

  //TODO: exchange this for draw()
  void 
  amDXGraphicsAPI::Render() {
    /**
    ************************
    *
    *  @TODO remove functionality from render
    *  @TODO make the different passes for differed rendering
    *  @TODO make RTVs for textures get set & used & passed
    *
    ************************
    */
    amVector4 color = amVector4(0.43f, 0.43f, 0.43f, 1.0f);

    m_pImmediateContext->clearRenderTargetView(m_pRenderTargetView, &color);
    m_pImmediateContext->clearDepthStencilView(m_pDepthStencilView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
    
    uint32 stride = sizeof(amVertex);
    uint32 offset = 0;

    m_pImmediateContext->setInputLayout(m_pVertexLayout);
    m_pImmediateContext->setVertexBuffer(m_pDevice->m_VB, stride, offset);
    m_pImmediateContext->setIndexBuffer(m_pDevice->m_IB);
    m_pImmediateContext->setPrimitiveTopology();
    m_pImmediateContext->setVertexShader(m_pVertexShader);
    m_pImmediateContext->setPixelShader(m_pPixelShader);
    m_pImmediateContext->m_pDC->VSSetConstantBuffers(0, 1, &m_pCB_VP->m_pCB);

    // Draw with index buffers
    m_pImmediateContext->m_pDC->DrawIndexed(3,0,0);
    m_pSwapChain->m_pSC->Present(0, 0);
  }

  void 
  amDXGraphicsAPI::initContent() {
    tmpLoadResource();
    /**
    ************************
    *
    *  @TODO: set up render passes with models and shaders
    *
    ************************
    */

    m_pVertexShader->createVS("Resources/BasicShader.fx", m_pDevice);
    m_pPixelShader->createPS("Resources/BasicShader.fx", m_pDevice);
    m_pVertexLayout->Create(m_pDevice, m_pVertexShader);
    
  }

  void 
  amDXGraphicsAPI::setManagers() {
    m_pRenderManager->setpManagers(m_pResourceManager, m_pCamManager);
  }

  void 
  amDXGraphicsAPI::initSystems(void* _hWnd) {

    m_pDevice = new amDXDevice();
    m_pSwapChain = new amDXSwapChain();
    m_pCB_VP = new amDXConstantBuffer();
    m_pDepthStencil = new amDXTexture();
    m_pCamManager = new amCameraManager();
    m_pPixelShader = new amDXPixelShader();
    m_pVertexShader = new amDXVertexShader();
    m_pVertexLayout = new  amDXInputLayout();
    m_pRenderManager = new amRenderManager();
    m_pResourceManager = new amResourceManager();
    m_pImmediateContext = new amDXDeviceContext();
    m_pDepthStencilView = new amDXDepthStencilView();
    m_pRenderTargetView = new amDXRenderTargetView();

    setManagers();

    HRESULT hr = S_OK;

    m_hWnd = reinterpret_cast<HWND>(_hWnd);

    RECT rc;
    GetClientRect(m_hWnd, &rc);
    uint32 width = rc.right - rc.left;
    uint32 height = rc.bottom - rc.top;

    uint32 createDeviceFlags = 0;
#if AM_DEBUG_MODE
    createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif // AM_DEBUG_MODE

    DXGI_SWAP_CHAIN_DESC sd;
    memset(&sd, 0, sizeof(sd));
    sd.BufferCount = 1;
    sd.BufferDesc.Width = width;
    sd.BufferDesc.Height = height;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = m_hWnd;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = true;

    D3D_DRIVER_TYPE driverTypes[] =
    {
      D3D_DRIVER_TYPE_HARDWARE,
      D3D_DRIVER_TYPE_WARP,
      D3D_DRIVER_TYPE_REFERENCE,
    };
    uint32 numDriverTypes = _ARRAYSIZE(driverTypes);

    D3D_FEATURE_LEVEL featureLevels[] =
    {
      D3D_FEATURE_LEVEL_11_0,
      D3D_FEATURE_LEVEL_10_1,
      D3D_FEATURE_LEVEL_10_0
    };
    uint32 numFeatureLevels = _ARRAYSIZE(featureLevels);

    for (uint32 driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++) {
      g_driverType = driverTypes[driverTypeIndex];
      hr = D3D11CreateDeviceAndSwapChain(nullptr,
                                         g_driverType,
                                         nullptr,
                                         createDeviceFlags,
                                         featureLevels,
                                         numFeatureLevels,
                                         D3D11_SDK_VERSION,
                                         &sd,
                                         &m_pSwapChain->m_pSC,
                                         &m_pDevice->m_pDV,
                                         &g_featureLevel,
                                         &m_pImmediateContext->m_pDC);

      if(hr == S_OK)
      {
        break;
      }
    }

    AM_ASSERT(m_pImmediateContext && m_pImmediateContext->m_pDC);


    // Create a render target view
    ID3D11Texture2D* pBackBuffer;
    hr = m_pSwapChain->m_pSC->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
    AM_ASSERT(hr == S_OK);

    //m_pSwapChain->getRTVFromBuffer(m_pDevice, NULL);
    hr = m_pDevice->m_pDV->CreateRenderTargetView(pBackBuffer, nullptr, &m_pRenderTargetView->m_pRTV);
    pBackBuffer->Release();

    AM_ASSERT(hr == S_OK);

    // Create depth stencil texture
    D3D11_TEXTURE2D_DESC descDepth;
    memset(&descDepth, 0, sizeof(descDepth));
    descDepth.Width = width;
    descDepth.Height = height;
    descDepth.MipLevels = 1;
    descDepth.ArraySize = 1;
    descDepth.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
    descDepth.SampleDesc.Count = 1;
    descDepth.SampleDesc.Quality = 0;
    descDepth.Usage = D3D11_USAGE_DEFAULT;
    descDepth.BindFlags = D3D11_BIND_DEPTH_STENCIL;
    descDepth.CPUAccessFlags = 0;
    descDepth.MiscFlags = 0;
    hr = m_pDevice->m_pDV->CreateTexture2D(&descDepth, nullptr, &m_pDepthStencil->m_tex);
    AM_ASSERT(hr == S_OK);

    // Create the depth stencil view
    D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;
    memset(&descDSV, 0, sizeof(descDSV));
    descDSV.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
    descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
    descDSV.Texture2D.MipSlice = 0;
    hr = m_pDevice->m_pDV->CreateDepthStencilView(m_pDepthStencil->m_tex, &descDSV, &m_pDepthStencilView->m_pDSV);
    AM_ASSERT(hr == S_OK);

    m_pImmediateContext->m_pDC->OMSetRenderTargets(1, &m_pRenderTargetView->m_pRTV, m_pDepthStencilView->m_pDSV);

    // Setup the viewport
    D3D11_VIEWPORT vp;
    vp.Width = static_cast<float>(width);
    vp.Height = static_cast<float>(height);
    vp.MinDepth = 0.0f;
    vp.MaxDepth = 1.0f;
    vp.TopLeftX = 0;
    vp.TopLeftY = 0;
    m_pImmediateContext->m_pDC->RSSetViewports(1, &vp);

    //////////////////////////////////////////////////////////////////////////
    // Build View Projection Matrix
    //////////////////////////////////////////////////////////////////////////
    m_fov = amMath::DEG2RAD * 75.0f;
    cam.m_matView = amMatrix4x4::IDENTITY;
    cam.movePoint(amVector3(0.0f, 0.0f, -1.0f), amVector3(0.0f, 0.0f, 1.0f), amVector3(0.0f, 1.0f, 0.0f));
    matProjecton = amMatrix4x4::IDENTITY;
    cam.getViewMatrix();
    matProjecton._m.m00 = 1.0f/amMath::tan(m_fov * 0.5f);
    matProjecton._m.m11 = (height / matProjecton._m.m00 / width);
    matProjecton._m.m22 = matProjecton._m.m23 = vp.MinDepth * (vp.MaxDepth - vp.MinDepth);
    cam.m_matView *= matProjecton;
    m_pCB_VP->m_pCBuffer = &cam.getViewMatrix();
    m_pCB_VP->m_size = static_cast<uint32>(sizeof(cam.getViewMatrix()));
  }

  void amDXGraphicsAPI::setShaderConstantBuffers(Vector<amResource*> _vecRes, uint32 _shaderFlags) {
    _vecRes;
    _shaderFlags;
  }

  void amDXGraphicsAPI::Draw(amResource * _pMesh, amMaterial * _pMat, amRenderTarget * _pOutRenderTarget) {
    _pMat;
    _pOutRenderTarget;

    //m_pImmediateContext->setVSResources()
    m_pImmediateContext->setVertexBuffer(&reinterpret_cast<amMesh*>(_pMesh)->m_vb,
                                         reinterpret_cast<amMesh*>(_pMesh)->m_vb.getVertSize(),
                                         0);

    m_pImmediateContext->setIndexBuffer(&reinterpret_cast<amMesh*>(_pMesh)->m_ib);
    _pMat->setTexsAs_PS_RSV(m_pImmediateContext);
    m_pImmediateContext->drawIndexed(reinterpret_cast<amMesh*>(_pMesh)->getIndexCount(), 
                                     reinterpret_cast<amMesh*>(_pMesh)->m_ib.m_vecIB[0], 
                                     0);
  }

  void amDXGraphicsAPI::tmpLoadResource() {
     m_pResourceManager->CreateModel("Resources/3D_Meshes/Cube.x");
    //m_pResourceManager->CreateModel("Resources/3D_Meshes/Vela/Vela_Mat_1.X");
    //m_pResourceManager->CreateModel("Resources/3D_Meshes/Vela/Vela_Mat_2.X");
    //m_pResourceManager->CreateModel("Resources/3D_Meshes/Vela/Vela_Mat_3.X");
    //m_pResourceManager->CreateModel("Resources/3D_Meshes/Vela/Vela_Mat_4.X");
    //m_pResourceManager->CreateModel("Resources/3D_Meshes/Vela/Vela_Mat_5.X");
    //m_pResourceManager->CreateModel("Resources/3D_Meshes/Vela/Vela_Mat_6.X");
    //
    //m_pResourceManager->CreateTexture("Resources/3D_Meshes/Vela/Textures/Vela_Char_BaseColor.tga");
    //m_pResourceManager->CreateTexture("Resources/3D_Meshes/Vela/Textures/Vela_Char_Emissive.tga");
    //m_pResourceManager->CreateTexture("Resources/3D_Meshes/Vela/Textures/Vela_Char_Metallic.tga");
    //m_pResourceManager->CreateTexture("Resources/3D_Meshes/Vela/Textures/Vela_Char_Normal.tga");
    //m_pResourceManager->CreateTexture("Resources/3D_Meshes/Vela/Textures/Vela_Char_Roughness.tga");
    //m_pResourceManager->CreateTexture("Resources/3D_Meshes/Vela/Textures/Vela_EyeCornea_BaseColor.tga");
    //m_pResourceManager->CreateTexture("Resources/3D_Meshes/Vela/Textures/Vela_EyeCornea_Normal.tga");
    //m_pResourceManager->CreateTexture("Resources/3D_Meshes/Vela/Textures/Vela_EyeCornea_Roughness.tga");
    //m_pResourceManager->CreateTexture("Resources/3D_Meshes/Vela/Textures/Vela_Gun_BaseColor.tga");
    //m_pResourceManager->CreateTexture("Resources/3D_Meshes/Vela/Textures/Vela_Gun_Metallic.tga");
    //m_pResourceManager->CreateTexture("Resources/3D_Meshes/Vela/Textures/Vela_Gun_Normal.tga");
    //m_pResourceManager->CreateTexture("Resources/3D_Meshes/Vela/Textures/Vela_Gun_Roughness.tga");
    //m_pResourceManager->CreateTexture("Resources/3D_Meshes/Vela/Textures/Vela_Legs_BaseColor.tga");
    //m_pResourceManager->CreateTexture("Resources/3D_Meshes/Vela/Textures/Vela_Legs_Metallic.tga");
    //m_pResourceManager->CreateTexture("Resources/3D_Meshes/Vela/Textures/Vela_Legs_Normal.tga");
    //m_pResourceManager->CreateTexture("Resources/3D_Meshes/Vela/Textures/Vela_Legs_Roughness.tga");
    //m_pResourceManager->CreateTexture("Resources/3D_Meshes/Vela/Textures/Vela_Mechanical_BaseColor.tga");
    //m_pResourceManager->CreateTexture("Resources/3D_Meshes/Vela/Textures/Vela_Mechanical_Emissive.tga");
    //m_pResourceManager->CreateTexture("Resources/3D_Meshes/Vela/Textures/Vela_Mechanical_Metallic.tga");
    //m_pResourceManager->CreateTexture("Resources/3D_Meshes/Vela/Textures/Vela_Mechanical_Normal.tga");
    //m_pResourceManager->CreateTexture("Resources/3D_Meshes/Vela/Textures/Vela_Mechanical_Roughness.tga");
    //m_pResourceManager->CreateTexture("Resources/3D_Meshes/Vela/Textures/Vela_Plate_BaseColor.tga");
    //m_pResourceManager->CreateTexture("Resources/3D_Meshes/Vela/Textures/Vela_Plate_Emissive.tga");
    //m_pResourceManager->CreateTexture("Resources/3D_Meshes/Vela/Textures/Vela_Plate_Metallic.tga");
    //m_pResourceManager->CreateTexture("Resources/3D_Meshes/Vela/Textures/Vela_Plate_Normal.tga");
    //m_pResourceManager->CreateTexture("Resources/3D_Meshes/Vela/Textures/Vela_Plate_Roughness.tga");
  }

  void 
  amDXGraphicsAPI::destroy() {
    delete(m_pDevice);
    delete(m_pSwapChain);
    delete(m_pCB_VP);
    delete(m_pDepthStencil);
    delete(m_pCamManager);
    delete(m_pPixelShader);
    delete(m_pVertexShader);
    delete(m_pVertexLayout);
    delete(m_pRenderManager);
    delete(m_pResourceManager);
    delete(m_pImmediateContext);
    delete(m_pDepthStencilView);
    delete(m_pRenderTargetView);
  }

  //HRESULT amDXGraphicsAPI::InitWindow(HINSTANCE hInstance, int32 nCmdShow) {
  //  // Register class
  //  WNDCLASSEX wcex;
  //  wcex.cbSize = sizeof(WNDCLASSEX);
  //  wcex.style = CS_HREDRAW | CS_VREDRAW;
  //  wcex.lpfnWndProc = WndProc;
  //  wcex.cbClsExtra = 0;
  //  wcex.cbWndExtra = 0;
  //  wcex.hInstance = hInstance;
  //  //wcex.hIcon = LoadIcon(hInstance, (LPCTSTR)IDI_TUTORIAL1);
  //  //wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
  //  wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
  //  wcex.lpszMenuName = NULL;
  //  wcex.lpszClassName = "TutorialWindowClass";
  //  //wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_TUTORIAL1);
  //  if (!RegisterClassEx(&wcex))
  //    return E_FAIL;
  //
  //  // Create window
  //  m_hInst = hInstance;
  //  RECT rc = {0, 0, 640, 480};
  //  AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
  //  m_hWnd = CreateWindow("TutorialWindowClass", "Direct3D 11 Tutorial 7", WS_OVERLAPPEDWINDOW,
  //                        CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, hInstance,
  //                        NULL);
  //  if (!m_hWnd)
  //    return E_FAIL;
  //
  //  ShowWindow(m_hWnd, nCmdShow);
  //
  //  return S_OK;
  //}

  /*LRESULT CALLBACK WindowProc(HWND hWnd, uint32 message, WPARAM wParam, LPARAM lParam) {
    PAINTSTRUCT ps;
    HDC hdc;

    switch (message) {
      case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        EndPaint(hWnd, &ps);
        break;

      case WM_DESTROY:
        PostQuitMessage(0);
        break;

      default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
  }*/
}
