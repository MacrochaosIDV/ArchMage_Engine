#include "amDXGraphicsAPI.h"
namespace amEngineSDK {

  D3D_DRIVER_TYPE                     g_driverType = D3D_DRIVER_TYPE_NULL;
  D3D_FEATURE_LEVEL                   g_featureLevel = D3D_FEATURE_LEVEL_11_0;


  amDXGraphicsAPI::~amDXGraphicsAPI() {}

  void amDXGraphicsAPI::createVertexBuffer(int32 nVertex, int32 vertexSize) {
  
  }

  void amDXGraphicsAPI::CleanupDevice() {

  }

  bool amDXGraphicsAPI::init(HWND _hWnd) {
    bool hr = S_OK;
    
    RECT rc;
    GetClientRect(m_hWnd, &rc);
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
    sd.OutputWindow = m_hWnd;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = TRUE;
    return true;

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
      hr = D3D11CreateDeviceAndSwapChain(NULL, g_driverType, NULL, createDeviceFlags, featureLevels, numFeatureLevels,
                                         D3D11_SDK_VERSION, &sd, &m_pSwapChain->m_pSC, &m_pDevice->m_pDV,
                                         &g_featureLevel, &m_pImmediateContext->m_pDC);
    }

    if (FAILED(hr))
      return hr;

    // Create a render target view
    ID3D11Texture2D* pBackBuffer;
    hr = m_pSwapChain->m_pSC->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
    //if (FAILED(hr))
      //return hr;

    hr = m_pSwapChain->getRTVFromBuffer(m_pDevice, NULL);
    pBackBuffer->Release();
    //if (FAILED(hr))
      //return hr;

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
    if (FAILED(hr))
      return hr;

    // Create the depth stencil view
    D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;
    ZeroMemory(&descDSV, sizeof(descDSV));
    descDSV.Format = descDepth.Format;
    descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
    descDSV.Texture2D.MipSlice = 0;
    hr = m_pDevice->m_pDV->CreateDepthStencilView(m_pDepthStencil->m_tex, &descDSV, &m_pDepthStencilView->m_pDSV);
    if (FAILED(hr))
      return hr;

    m_pImmediateContext->m_pDC->OMSetRenderTargets(1, &m_pRenderTargetView->m_pRTV, m_pDepthStencilView->m_pDSV);

    // Setup the viewport
    D3D11_VIEWPORT vp;
    vp.Width = 400;
    vp.Height = 400;
    //vp.Height = (FLOAT)height;
    vp.MinDepth = 0.0f;
    vp.MaxDepth = 1.0f;
    vp.TopLeftX = 0;
    vp.TopLeftY = 0;
    m_pImmediateContext->m_pDC->RSSetViewports(1, &vp);

    return true;
  }

  void amDXGraphicsAPI::Render() {
    float color[4] = {1.0f, 0.0f, 1.0f, 1.0f};
    m_pImmediateContext->m_pDC->ClearRenderTargetView(m_pRenderTargetView->m_pRTV, color);

    amDXVertexBuffer vb;
    m_pDevice->m_VB.setBufferDesc(D3D11_USAGE_DEFAULT, 0, 0, 0);
    m_pDevice->m_VB.setVertexSize(sizeof(m_pDevice->m_VB.m_vVertex));
    m_pDevice->m_VB.m_vVertex = {amVertex(-0.5f,0.0f,0.0f,1.0f,1.0f,0.0f,0.0f,1.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f),
                                 amVertex( 0.0f,0.5f,0.0f,1.0f,0.0f,1.0f,0.0f,1.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f),
                                 amVertex( 0.5f,0.0f,0.0f,1.0f,0.0f,0.0f,1.0f,1.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f)};
    m_pDevice->m_VB.setSubResourceData(&m_pDevice->m_VB.m_vVertex[0], 0, 0);

    
    D3D11_MAPPED_SUBRESOURCE msr;
    m_pImmediateContext->m_pDC->Map(m_pDevice->m_VB.m_pVB, 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);
    m_pDevice->CreateVertexBuffer();

    //m_pDevice->m_pDV->CreateBuffer(&m_pDevice->m_VB.m_bd, &m_pDevice->m_VB.m_initData, &m_pDevice->m_VB.m_pVB);

    m_pSwapChain->m_pSC->Present(0, 0);
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


