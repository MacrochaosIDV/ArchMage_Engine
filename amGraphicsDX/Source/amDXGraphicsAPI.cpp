#include "amDXGraphicsAPI.h"
#include <amVertex.h>
#include <amMaterial.h>
#include <amMesh.h>
#include <amTexture.h>
#include <amModel.h>
#include <amResource.h>


#include "amDXTexture.h"
#include "amDXTextureObject.h"
#include "amDXConstantBuffer.h"
#include "amDXSamplerState.h"
#include "amDXDepthStencilView.h"
#include "amDXPixelShader.h"
#include "amDXVertexShader.h"
#include "amDXInputLayout.h"
#include "amDXRenderTargetView.h"
#include "amDXSwapChain.h"
#include "amDXDeviceContext.h"
#include "amDXDevice.h"


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
    delete(m_pRenderManager);
    delete(m_pResourceManager);
    delete(m_pCamManager);
    delete(m_pDevice);
    delete(m_pSwapChain);
    delete(m_pCB_VP);
    delete(m_pDepthStencil);
    delete(m_pCamManager);
    delete(m_pPixelShader);
    delete(m_pVertexShader);
    delete(m_pInputLayout);
    delete(m_pRenderManager);
    delete(m_pResourceManager);
    delete(m_pContext);
    delete(m_pDepthStencilView);
    delete(m_pRenderTargetView);
  }

  void 
  amDXGraphicsAPI::init(void* _hWnd) {
    
    initSystems(_hWnd);
    initContent();
  }

  void 
  amDXGraphicsAPI::Run() {
    /**
    ************************
    *
    *  @TODO: remove Draw functionality from render
    *  @TODO: make the different passes for differed rendering
    *  @TODO: make RTVs for textures get set & used & passed
    *
    ************************
    */
    //m_pContext->clearDepthStencilView(m_pDepthStencilView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
    
    m_pContext->setInputLayout(m_pInputLayout);
    m_pContext->setPrimitiveTopology();
    m_pContext->setVertexShader(m_pVertexShader);
    m_pContext->setPixelShader(m_pPixelShader);
    m_pContext->setVS_CB(0, 1, m_pCB_VP);

    // Draw with index buffers
    Draw(m_testCube->m_vecMeshes[0], nullptr);
    Present();
  }

  void 
  amDXGraphicsAPI::initContent() {
    /**
    ************************
    *
    *  @TODO: set up render passes with models and shaders
    *
    ************************
    */
    m_clearColor = amVector4(0.0f, 0.0f, 0.0f, 1.0f);
    m_pVertexShader->createVS("Resources/Shaders/VS_GBuffer.hlsl", m_pDevice);
    m_pPixelShader->createPS("Resources/Shaders/PS_PBR.hlsl", m_pDevice);
    m_pInputLayout->Create(m_pDevice, m_pVertexShader);
    m_pResourceManager->loadDeafultTex();

    m_pResourceManager->CreateRenderTarget(m_rtFullColor,
                                           amFormats::E::kFORMAT_R16G16B16A16_FLOAT, 
                                           true);

    m_pResourceManager->CreateRenderTarget(m_rtEmissive,
                                           amFormats::E::kFORMAT_R8G8B8A8_UNORM,
                                           false);

    m_pResourceManager->CreateRenderTarget(m_rtNormals,
                                           amFormats::E::kFORMAT_R8G8B8A8_UNORM,
                                           false);

    m_pResourceManager->CreateRenderTarget(m_rtBlur,
                                           amFormats::E::kFORMAT_R8G8B8A8_UNORM,
                                           false);

    m_pResourceManager->CreateRenderTarget(m_rtLuminance,
                                           amFormats::E::kFORMAT_R8G8B8A8_UNORM,
                                           false);

    m_pResourceManager->CreateRenderTarget(m_rtMADR,
                                           amFormats::E::kFORMAT_R8G8B8A8_UNORM,
                                           false);

    tmpLoadResource();
  }

  void 
  amDXGraphicsAPI::setManagers() {
    m_pRenderManager->setpManagers(m_pResourceManager, m_pCamManager);
  }

  void 
  amDXGraphicsAPI::initSystems(void* _hWnd) {
    /**
    ************************
    * Initialize API objects
    ************************
    */
    m_pDevice = new amDXDevice();
    m_pSwapChain = new amDXSwapChain();
    m_pCB_VP = new amDXConstantBuffer();
    m_pContext = new amDXDeviceContext();
    m_pPixelShader = new amDXPixelShader();
    m_pVertexShader = new amDXVertexShader();
    m_pInputLayout = new  amDXInputLayout();
    m_pDepthStencilView = new amDXDepthStencilView();
    m_pRenderTargetView = new amDXRenderTargetView();

    m_pCamManager = new amCameraManager();
    m_pRenderManager = new amRenderManager();
    m_pResourceManager = new amResourceManager(m_pDevice);

    m_farPlane = new amDXConstantBuffer();
    m_matWorld = new amDXConstantBuffer();
    m_nearPlane = new amDXConstantBuffer();
    m_matViewProjection = new amDXConstantBuffer();

    HRESULT hr = S_OK;

    m_hWnd = reinterpret_cast<HWND>(_hWnd);

    RECT rc;
    GetClientRect(m_hWnd, &rc);
    uint32 width = rc.right - rc.left;
    uint32 height = rc.bottom - rc.top;

    m_pDepthStencil = new amDXTexture();

    m_bloomIntensity = 0.25f;

    /**
    ************************
    * Initialize Render Targets
    ************************
    */
    m_rtFullColor = new amRenderTargetView(height, width);
    m_rtEmissive = new amRenderTargetView(height, width);
    m_rtNormals = new amRenderTargetView(height, width);
    m_rtBlur = new amRenderTargetView(height, width, 0.25f);
    m_rtLuminance = new amRenderTargetView(height, width);
    m_rtMADR = new amRenderTargetView(height, width);

    uint32 createDeviceFlags = 0;
#if AM_DEBUG_MODE
    createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif // AM_DEBUG_MODE

    //////////////////////////////////////////////////////////////////////////
    ////// TODO: replace this with engine types
    //////////////////////////////////////////////////////////////////////////
    //DXGI_SWAP_CHAIN_DESC sd;
    memset(&m_pSwapChain->m_scd, 0, sizeof(m_pSwapChain->m_scd));
    m_pSwapChain->m_scd.BufferCount = 1;
    m_pSwapChain->m_scd.BufferDesc.Width = width;
    m_pSwapChain->m_scd.BufferDesc.Height = height;
    m_pSwapChain->m_scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    m_pSwapChain->m_scd.BufferDesc.RefreshRate.Numerator = 60;
    m_pSwapChain->m_scd.BufferDesc.RefreshRate.Denominator = 1;
    m_pSwapChain->m_scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    m_pSwapChain->m_scd.OutputWindow = m_hWnd;
    m_pSwapChain->m_scd.SampleDesc.Count = 1;
    m_pSwapChain->m_scd.SampleDesc.Quality = 0;
    m_pSwapChain->m_scd.Windowed = true;

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
                                         &m_pSwapChain->m_scd,
                                         &m_pSwapChain->m_pSC,
                                         &m_pDevice->m_pDV,
                                         &g_featureLevel,
                                         &m_pContext->m_pDC);

      if(hr == S_OK)
      {
        break;
      }
    }

    AM_ASSERT(m_pContext && m_pContext->m_pDC);
    /**
    ************************
    *  With the device created the others can be created now
    ************************
    */

    setManagers();
    m_pInputLayout->init();
    

    /**
    ************************
    *  Create a render target view
    ************************
    */
    //////////////////////////////////////////////////////////////////////////
    ////// TODO: replace this with engine types
    //////////////////////////////////////////////////////////////////////////

    ID3D11Texture2D* pBackBuffer;
    hr = m_pSwapChain->m_pSC->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
    AM_ASSERT(hr == S_OK);

    //m_pSwapChain->getRTVFromBuffer(m_pDevice, NULL);
    hr = m_pDevice->m_pDV->CreateRenderTargetView(pBackBuffer, nullptr, &m_pRenderTargetView->m_pRTV);
    pBackBuffer->Release();

    AM_ASSERT(hr == S_OK);

    /**
    ************************
    *  Create depth stencil texture
    ************************
    */
    //////////////////////////////////////////////////////////////////////////
    ////// TODO: replace this with engine types
    //////////////////////////////////////////////////////////////////////////

    //m_pDepthStencil->m_pDesc = 
    m_pDepthStencilView = createDepthStencilV(height, width, amFormats::kFORMAT_R8G8B8A8_UNORM);

    /*D3D11_TEXTURE2D_DESC descDepth;
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
    hr = m_pDevice->m_pDV->CreateTexture2D(&descDepth, 
                                           nullptr, 
                                           reinterpret_cast<ID3D11Texture2D**>(
                                             &m_pDepthStencil->m_apiPtr));*/

    /**
    ************************
    *  Create the depth stencil view
    ************************
    */

    /*D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;
    memset(&descDSV, 0, sizeof(descDSV));
    descDSV.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
    descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
    descDSV.Texture2D.MipSlice = 0;
    hr = m_pDevice->m_pDV->CreateDepthStencilView(reinterpret_cast<ID3D11Texture2D*>(
                                                   m_pDepthStencil->m_apiPtr),
                                                  &descDSV,
                                                  &m_pDepthStencilView->m_pDSV);
    AM_ASSERT(hr == S_OK);*/

    AM_ASSERT(m_pDepthStencilView != nullptr);

    
    //////////////////////////////////////////////////////////////////////////
    ////// TODO: replace this with engine types
    //////////////////////////////////////////////////////////////////////////

    

    m_pContext->m_pDC->OMSetRenderTargets(1, &m_pRenderTargetView->m_pRTV, m_pDepthStencilView->m_pDSV);

    /**
    ************************
    *  Setup the viewport
    ************************
    */
    //////////////////////////////////////////////////////////////////////////
    ////// TODO: replace this with engine types
    //////////////////////////////////////////////////////////////////////////

    D3D11_VIEWPORT vp;
    vp.Width = static_cast<float>(width);
    vp.Height = static_cast<float>(height);
    vp.MinDepth = 0.0f;
    vp.MaxDepth = 1.0f;
    vp.TopLeftX = 0;
    vp.TopLeftY = 0;
    m_pContext->m_pDC->RSSetViewports(1, &vp);

    /**
    ************************
    *  Build View Projection Matrix
    ************************
    */

    // TODO: separate the mixed WVP into their own matrices
    m_cam.m_near = 0.01f;
    m_cam.m_far = 100.0f;
    m_cam.m_fov = amMath::DEG2RAD * 75.0f;
    m_cam.m_mat = amMatrix4x4::IDENTITY;
    m_cam.movePoint(amVector3(0.0f, 0.0f, -1.0f), amVector3(0.0f, 0.0f, 1.0f), amVector3(0.0f, 1.0f, 0.0f));
    matProjecton = amMatrix4x4::IDENTITY;
    m_cam.getViewMatrix();
    matProjecton._m.m00 = 1.0f/amMath::tan(m_fov * 0.5f);
    matProjecton._m.m11 = (height / matProjecton._m.m00 / width);
    matProjecton._m.m22 = matProjecton._m.m23 = vp.MinDepth * (vp.MaxDepth - vp.MinDepth);
    m_cam.m_mat *= matProjecton;
    m_pCB_VP->m_pCBuffer = &m_cam.m_mat;
    m_pCB_VP->m_size = static_cast<uint32>(sizeof(m_cam.m_mat));

    /**
    ************************
    * Setup constant buffers
    ************************
    */
    m_farPlane->setBufferData(amDXUsageFlags::E::kDEFAULT, 0, &m_cam.m_far);
    m_nearPlane->setBufferData(amDXUsageFlags::E::kDEFAULT, 1, &m_cam.m_near);
    m_matViewProjection->setBufferData(amDXUsageFlags::E::kDEFAULT, 2, &m_cam.m_mat);
    

  }

  void 
  amDXGraphicsAPI::setShaderResources(Vector<amResource*> _vecRes, uint32 _shaderFlags) {
    //TODO: this
    _vecRes;
    _shaderFlags;
  }

  void 
  amDXGraphicsAPI::Draw(amMesh* _pMesh,
                        amRenderTarget* _pOutRenderTarget,
                        amMaterial* _pMat) { //re-writing this to be able to use other mats
    /**
    ************************
    * Set the Vertex & Index buffer
    ************************
    */
    m_pContext->setVertexBuffer(&_pMesh->m_vb, _pMesh->m_vb.getVertSize(), 0);
    m_pContext->setIndexBuffer(&_pMesh->m_ib);
    uint32 ibSize = _pMesh->getIndexCount();

    /**
    ************************
    * Set the Textures
    ************************
    */
    if (_pMat) {
      _pMat->setTexsAs_PS_RSV(m_pContext);
    }
    else {
      _pMesh->m_mat->setTexsAs_PS_RSV(m_pContext);
    }
    //ensure the 5 srv for g-buffer
    _pOutRenderTarget;
    
    //TODO: this
    /**
    ************************
    * Set constant buffers, deltaTime
    ************************
    */

    /**
    ************************
    * Draw
    ************************
    */
    m_pContext->drawIndexed(ibSize, _pMesh->m_ib.m_vecIB[0], 0);
  }

  void 
  amDXGraphicsAPI::setConstantBuffer(amConstantBuffer * _cb, int32 _shaderFlags) {
    if (amShaderType::kPIXEL == _shaderFlags)
      m_pContext->setPS_CB(0 ,0, _cb);
    else if (amShaderType::kVERTEX == _shaderFlags)
      m_pContext->setVS_CB(0, 0, _cb);
  }

  void 
  amDXGraphicsAPI::setConstantBuffer(Vector<amConstantBuffer*> _cbVec, int32 _shaderFlags) {
    for (int32 i = 0; i < _cbVec.size(); ++i) {
      if (amShaderType::kPIXEL == _shaderFlags)
        m_pContext->setPS_CB(0, 0, _cbVec[i]);
      else if (amShaderType::kVERTEX == _shaderFlags)
        m_pContext->setVS_CB(0, 0, _cbVec[i]);
    }
  }

  void 
  amDXGraphicsAPI::Present() {
    m_pSwapChain->Present();
  }

  void 
  amDXGraphicsAPI::clearRenderTargets() {
    m_pContext->clearDepthStencilView(m_pDepthStencilView, 
                                      amClearFlags::E::kCLEAR_DEPTH | 
                                        amClearFlags::E::kCLEAR_STENCIL, 
                                      1.0f, 
                                      0);
    m_pContext->clearRenderTargetView(m_rtFullColor, &m_clearColor);
    m_pContext->clearRenderTargetView(m_rtEmissive, &m_clearColor);
    m_pContext->clearRenderTargetView(m_rtNormals, &m_clearColor);
    m_pContext->clearRenderTargetView(m_rtBlur, &m_clearColor);
    m_pContext->clearRenderTargetView(m_rtLuminance, &m_clearColor);
    m_pContext->clearRenderTargetView(m_rtMADR, &m_clearColor);
  }

  void 
  amDXGraphicsAPI::tmpLoadResource() {
    //m_pResourceManager->CreateModel("Resources/3D_Meshes/Cube.x");
    m_testCube = m_pResourceManager->CreateModel("Resources/3D_Meshes/Cube.x",
                                                 amMeshLoadFlags::E::kNO_MATS | 
                                                 amMeshLoadFlags::E::kNO_TEX);
    String mat = "mat";
    reinterpret_cast<amModel*>(
      m_testCube)->m_vecMats.push_back(reinterpret_cast<amMaterial*>(
        m_pResourceManager->CreateMaterial(reinterpret_cast<amTextureObject*>(
          m_pResourceManager->m_texObjPureWhite), mat)));

    m_pResourceManager->fillMaterial(reinterpret_cast<amModel*>(
                                      m_testCube)->m_vecMats[0], 
                                     reinterpret_cast<amTextureObject*>(
                                      m_pResourceManager->m_texObjPureBlack));
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
    delete(m_pInputLayout);
    delete(m_pRenderManager);
    delete(m_pResourceManager);
    delete(m_pContext);
    delete(m_pDepthStencilView);
    delete(m_pRenderTargetView);
  }

  void 
  amDXGraphicsAPI::Update() {
  
  }

  

  amDXShaderResourceView*
  amDXGraphicsAPI::loadTexture(const String & _pathName, 
                               const uint32 _textureFlags) {
    _pathName;
    _textureFlags;
    return nullptr;
  }

  amDXShaderResourceView*
    amDXGraphicsAPI::createTextureShaderResourceV(const String & _pathName,
                                                  const uint32 _textureFlags) {
    _pathName;
    _textureFlags;
    /**
    ************************
    *  @TODO: this
    ************************
    */
    return nullptr;
  }

  amDXRenderTargetView*
  amDXGraphicsAPI::createRenderTargetV(const uint32 _height, 
                                       const uint32 _width, 
                                       const amFormats::E _format, 
                                       const float _scale) {
    amDXRenderTargetView* dxRTV = new amDXRenderTargetView();
    dxRTV->m_rt = new amDXTexture();
    dxRTV->resize(static_cast<uint32>(_height * _scale),
                  static_cast<uint32>(_width * _scale));
    m_pDevice->createRenderTargetView(dxRTV,
                                      _format, 
                                      amResourceBindFlags::kBIND_RENDER_T_SHADER_R);
    //Store in res manager
    return nullptr;
  }

  amDXDepthStencilView*
  amDXGraphicsAPI::createDepthStencilV(const uint32 _height,
                                       const uint32 _width,
                                       const amFormats::E _format) {
    amDXDepthStencilView* depth = new amDXDepthStencilView();
    depth->m_tex = new amDXTexture();
    depth->resize(_height, _width);
    m_pDevice->createDepthStencilView(depth, amResourceBindFlags::kBIND_DEPTH_STENCIL);
    //Store in res manager
    return depth;
  }

  amDXTexture*
  amDXGraphicsAPI::createTexture(const uint32 _height, 
                                 const uint32 _width, 
                                 const amFormats::E _format,
                                 const int32 _rbf) {
    amDXTexture* tex = new amDXTexture();
    tex->resize(_height, _width);
    m_pDevice->createTexture(tex, _format, _rbf);
    //Store in res manager
    return tex;
  }

  amDXTexture*
  amDXGraphicsAPI::createTexture(const String& _pathName, 
                                 const uint32 _textureFlags) {
    _pathName;
    _textureFlags;
    return nullptr;
  }

  amModel* 
  amDXGraphicsAPI::createModel(const String& _pathName, 
                               const uint32 _meshLoadFlags) {
    _pathName;
    _meshLoadFlags;
    return nullptr;
  }

  amMaterial* 
  amDXGraphicsAPI::CreateMaterial(amTextureObject* _tex, 
                                  const String& _matName) {
    _tex;
    _matName;
    return nullptr;
  }

  amMaterial* 
  amDXGraphicsAPI::CreateMaterial(const String& _pathName, 
                                  uint32 _textureFlags) {
    _pathName;
    _textureFlags;
    return nullptr;
  }
}
