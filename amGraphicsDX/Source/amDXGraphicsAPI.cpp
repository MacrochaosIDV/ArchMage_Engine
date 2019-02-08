#include "amDXGraphicsAPI.h"
namespace amEngineSDK {

  D3D_DRIVER_TYPE                     g_driverType = D3D_DRIVER_TYPE_NULL;
  D3D_FEATURE_LEVEL                   g_featureLevel = D3D_FEATURE_LEVEL_11_0;


  amDXGraphicsAPI::~amDXGraphicsAPI() {}

  void amDXGraphicsAPI::createVertexBuffer(int32 nVertex, int32 vertexSize) {
    nVertex;
    vertexSize;
  }

  void amDXGraphicsAPI::CleanupDevice() {

  }

  void amDXGraphicsAPI::init(void* _hWnd) {
    
    initSystems(_hWnd);
    initContent();
  }

  void amDXGraphicsAPI::Render() {
    float color[4] = {0.0f, 0.0f, 1.0f, 1.0f};
    m_pImmediateContext->m_pDC->ClearRenderTargetView(m_pRenderTargetView->m_pRTV, color);
    
    UINT stride = sizeof(amVertex);
    UINT offset = 0;

    m_pVertexShader->setShader(m_pImmediateContext);
    m_pVertexShader->setShader(m_pImmediateContext);
    m_pVertexLayout->setLayout(m_pImmediateContext);
    m_pImmediateContext->m_pDC->IASetVertexBuffers(0, 1, &m_pDevice->m_VB.m_pVB, &stride, &offset);

    m_pImmediateContext->m_pDC->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    m_pImmediateContext->m_pDC->Draw(3, 0);

    m_pSwapChain->m_pSC->Present(0, 0);
  }

  void amDXGraphicsAPI::initContent() {

    m_pVertexShader->CompileShaderFromFile("Resources/BasicShader.fx", "VS", "vs_5_0", &m_pVertexShader->m_pblob);
    m_pPixelShader->CompileShaderFromFile("Resources/BasicShader.fx", "PS", "ps_5_0", &m_pPixelShader->m_pblob);

    m_pVertexShader->createVertexShader(m_pDevice);
    m_pPixelShader->createPixelShader(m_pDevice);

    m_pVertexLayout->Create(m_pDevice, m_pVertexShader->m_pblob);
    
    m_pDevice->m_VB.m_vVertex = {amVertex(-0.5f,0.0f,0.0f,1.0f,1.0f,0.0f,0.0f,1.0f,0.0f,0.0f,0.0f,0.0f,0.0f),
                                 amVertex(0.0f,0.5f,0.0f,1.0f,0.0f,1.0f,0.0f,1.0f,0.0f,0.0f,0.0f,0.0f,0.0f),
                                 amVertex(0.5f,0.0f,0.0f,1.0f,0.0f,0.0f,1.0f,1.0f,0.0f,0.0f,0.0f,0.0f,0.0f)};

    m_pDevice->m_VB.setBufferData(D3D11_USAGE_DEFAULT, sizeof(m_pDevice->m_VB.m_vVertex.size()*sizeof(amVertex)), &m_pDevice->m_VB.m_vVertex);
    
    m_pDevice->m_pDV->CreateBuffer(&m_pDevice->m_VB.m_bd, &m_pDevice->m_VB.m_initData, &m_pDevice->m_VB.m_pVB);
  }

  void amDXGraphicsAPI::initSystems(void* _hWnd) {

    m_pDevice = new amDXDevice();
    m_pSwapChain = new amDXSwapChain();
    m_pDepthStencil = new amDXTexture();
    m_pPixelShader = new amDXPixelShader();
    m_pVertexShader = new amDXVertexShader();
    m_pVertexLayout = new  amDXInputLayout();
    m_pImmediateContext = new amDXDeviceContext();
    m_pDepthStencilView = new amDXDepthStencilView();
    m_pRenderTargetView = new amDXRenderTargetView();
    
    
    



    HRESULT hr = S_OK;

    HWND hwnd = reinterpret_cast<HWND>(_hWnd);

    RECT rc;
    GetClientRect(hwnd, &rc);
    uint32 width = rc.right - rc.left;
    uint32 height = rc.bottom - rc.top;

    uint32 createDeviceFlags = 0;

    DXGI_SWAP_CHAIN_DESC sd;
    ZeroMemory(&sd, sizeof(sd));
    sd.BufferCount = 1;
    sd.BufferDesc.Width = width;
    sd.BufferDesc.Height = height;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = hwnd;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = TRUE;

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
      hr = D3D11CreateDeviceAndSwapChain(NULL, g_driverType,
                                         NULL, createDeviceFlags,
                                         featureLevels, numFeatureLevels,
                                         D3D11_SDK_VERSION,
                                         &sd, &m_pSwapChain->m_pSC,
                                         &m_pDevice->m_pDV,
                                         &g_featureLevel,
                                         &m_pImmediateContext->m_pDC);
    }

    AM_ASSERT(m_pImmediateContext && m_pImmediateContext->m_pDC);


    // Create a render target view
    ID3D11Texture2D* pBackBuffer;
    hr = m_pSwapChain->m_pSC->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
    AM_ASSERT(pBackBuffer);

    //m_pSwapChain->getRTVFromBuffer(m_pDevice, NULL);
    m_pDevice->m_pDV->CreateRenderTargetView(pBackBuffer, nullptr, &m_pRenderTargetView->m_pRTV);
    pBackBuffer->Release();

    AM_ASSERT(m_pRenderTargetView->m_pRTV);

    // Create depth stencil texture
    D3D11_TEXTURE2D_DESC descDepth;
    ZeroMemory(&descDepth, sizeof(descDepth));
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
    hr = m_pDevice->m_pDV->CreateTexture2D(&descDepth, NULL, &m_pDepthStencil->m_tex);
    AM_ASSERT(&m_pDepthStencil->m_tex);

    // Create the depth stencil view
    D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;
    ZeroMemory(&descDSV, sizeof(descDSV));
    descDSV.Format = descDepth.Format;
    descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
    descDSV.Texture2D.MipSlice = 0;
    hr = m_pDevice->m_pDV->CreateDepthStencilView(m_pDepthStencil->m_tex, &descDSV, &m_pDepthStencilView->m_pDSV);
    AM_ASSERT(&m_pDepthStencilView->m_pDSV);

    m_pImmediateContext->m_pDC->OMSetRenderTargets(1, &m_pRenderTargetView->m_pRTV, m_pDepthStencilView->m_pDSV);

    // Setup the viewport
    D3D11_VIEWPORT vp;
    vp.Width = 1.0;
    vp.Height = 1.0;
    vp.MinDepth = 0.0f;
    vp.MaxDepth = 1.0f;
    vp.TopLeftX = 0;
    vp.TopLeftY = 0;
    m_pImmediateContext->m_pDC->RSSetViewports(1, &vp);

    
  }

  void amDXGraphicsAPI::destroy() {

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

