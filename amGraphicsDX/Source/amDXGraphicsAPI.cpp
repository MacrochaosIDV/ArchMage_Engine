#include "amDXGraphicsAPI.h"
#include <amVertex.h>
#include <amMaterial.h>
#include <amMesh.h>
#include <amTexture.h>
#include <amModel.h>
#include <amMesh.h>
#include <amResource.h>
#include <amMaterial.h>
#include <amLight.h>
#include <amRenderPass.h>
#include <amRP_GBuffer.h>
#include <amRP_SSAO.h>
#include <amRP_Blur.h>
#include <amRP_DownScaleBloom.h>
#include <amRP_Lighting.h>
#include <amRP_Luminance.h>

#include <stb_image.h>
#include <assimp/Importer.hpp> // C++ importer interface
#include <assimp/scene.h> // Output data structure
#include <assimp/postprocess.h> // Post processing flags
#include <assimp/pbrmaterial.h> // Post processing flags

#include "dds.h"
#include "amDXTexture.h"
#include "amDXTextureObject.h"
#include "amDXConstantBuffer.h"
#include "amDXSamplerState.h"
#include "amDXDepthStencilView.h"
#include "amDXShaderResourceView.h"
#include "amDXPixelShader.h"
#include "amDXVertexShader.h"
#include "amDXInputLayout.h"
#include "amDXRenderTargetView.h"
#include "amDXSwapChain.h"
#include "amDXDeviceContext.h"
#include "amDXDevice.h"


namespace amEngineSDK {
  /**
  ************************
  *  Function forward declarations
  ************************
  */

  amVector3
  get_Pos(const aiVector3D& other);

  D3D_DRIVER_TYPE  g_driverType = D3D_DRIVER_TYPE_NULL;
  D3D_FEATURE_LEVEL g_featureLevel = D3D_FEATURE_LEVEL_11_0;


  amDXGraphicsAPI::~amDXGraphicsAPI() {
    CleanupDevice();
  }

  void 
  amDXGraphicsAPI::CleanupDevice() {
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

    m_pContext->setInputLayout(m_pInputLayout);
    m_pContext->setPrimitiveTopology();

    m_pContext->setVertexShader(m_pVertexShader);
    m_pContext->setPixelShader(m_pPixelShader);

    m_pContext->setVS_CB(0, 1, m_pCB_VP);

    setRenderPass(m_RP_Gbuffer, m_pContext);

    //get all geometry in camera
    /**
    ************************
    *  Draw G-buffer
    ************************
    */
    //TODO: draw all geometry in camera
    Draw(m_testCube->m_vecMeshes[0]);
    /**
    ************************
    *  Post-processing
    ************************
    */
    setRenderPass(m_RP_SSAO, m_pContext);
    setRenderPass(m_RP_Blur, m_pContext);
    setRenderPass(m_RP_Bloom, m_pContext);
    setRenderPass(m_RP_Lighting, m_pContext);
    setRenderPass(m_RP_Luminance, m_pContext);
    Present();
  }

  void 
  amDXGraphicsAPI::initContent() {
    
    m_clearColor = amVector4(0.0f, 0.0f, 0.0f, 1.0f);
    //m_pVertexShader->createVS("Resources/Shaders/VS_GBuffer.hlsl", m_pDevice);
    //m_pPixelShader->createPS("Resources/Shaders/PS_PBR.hlsl", m_pDevice);
    m_pInputLayout->Create(m_pDevice, m_pVertexShader);

    /**
    ************************
    *  Render Pass initialize
    ************************
    */


    m_defaultMaterial = new amMaterial("Default Material");
    m_defaultMaterial->addTextureToMat(createTextureShaderResourceV(AM_MISSING_TEX, 
                                                                    amTexType::kALBEDO));
    m_defaultMaterial->addTextureToMat(createTextureShaderResourceV(AM_BLACK_TEX, 
                                                                    amTexType::kEMISSIVE));
    m_defaultMaterial->addTextureToMat(createTextureShaderResourceV(AM_NORMALS_TEX, 
                                                                    amTexType::kNORMAL));
    m_defaultMaterial->addTextureToMat(createTextureShaderResourceV(AM_WHITE_TEX, 
                                                                    amTexType::kROUGHNESS));
    m_defaultMaterial->addTextureToMat(createTextureShaderResourceV(AM_GREY_TEX, 
                                                                    amTexType::kMETALNESS));
    m_pResourceManager->addMaterial(m_defaultMaterial);

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
    m_pRenderTargetView = new amDXRenderTargetView();

    m_pCamManager = new amCameraManager();
    m_pRenderManager = new amRenderManager();
    m_pResourceManager = new amResourceManager();

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

    /**
    ************************
    *
    *  Device and Swap-chain creation 
    *
    ************************
    */

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

    /**
    ************************
    * Initialize Render Targets and depth stencil
    ************************
    */

    m_rtFullColor = createRenderTargetV(height, width, amFormats::kFORMAT_R16G16B16A16_FLOAT);
    m_rtEmissive = createRenderTargetV(height, width, amFormats::kFORMAT_R8G8B8A8_UNORM);
    m_rtNormals = createRenderTargetV(height, width, amFormats::kFORMAT_R8G8B8A8_UNORM);
    m_rtBlur = createRenderTargetV(height, width, amFormats::kFORMAT_R8G8B8A8_UNORM, 0.25f);
    m_rtLuminance = createRenderTargetV(height, width, amFormats::kFORMAT_R8G8B8A8_UNORM);
    m_rtMADR = createRenderTargetV(height, width, amFormats::kFORMAT_R8G8B8A8_UNORM);

    m_pDepthStencilView = createDepthStencilV(height, width);
    AM_ASSERT(m_pDepthStencilView != nullptr);

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
    m_farPlane->setBufferData(amDXUsageFlags::kDEFAULT, 0, &m_cam.m_far);
    m_nearPlane->setBufferData(amDXUsageFlags::kDEFAULT, 1, &m_cam.m_near);
    m_matViewProjection->setBufferData(amDXUsageFlags::kDEFAULT, 2, &m_cam.m_mat);
    

  }

  void 
  amDXGraphicsAPI::setShaderResources(Vector<amResource*> _vecRes, uint32 _shaderFlags) {
    //TODO: this
    _vecRes;
    _shaderFlags;
  }

  void 
  amDXGraphicsAPI::Draw(amMesh* _pMesh) {
    /**
    ************************
    * Set the Vertex & Index buffer
    ************************
    */
    m_pContext->setVertexBuffer(_pMesh->m_vb, _pMesh->m_vb->getVertSize(), 0);
    m_pContext->setIndexBuffer(_pMesh->m_ib);
    uint32 ibSize = _pMesh->getIndexCount();

    /**
    ************************
    * Set the Textures
    ************************
    */
    for (uint32 i = 0; i < 5; ++i) {
      m_pContext->setPSResources(i, 1, _pMesh->m_mat->m_vecTex[i]);
    }
    
    //TODO: this
    /**
    ************************
    * Set constant buffers, deltaTime
    ************************
    */
    //m_pContext->setVS_CB(0, 1, );

    /**
    ************************
    * Draw
    ************************
    */
    m_pContext->drawIndexed(ibSize, _pMesh->m_ib->m_vecIB[0], 0);
  }

  void 
  amDXGraphicsAPI::setConstantBuffer(amConstantBuffer* _cb, int32 _shaderFlags) {
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

  void amDXGraphicsAPI::setRenderPass(amRenderPass * _pass, 
                                      amDeviceContext* _dv) {
    _pass->setUp(_dv);
  }

  void 
  amDXGraphicsAPI::tmpLoadResource() {
    m_testCube = createModel("Resources/3D_Meshes/Cube.x", 
                             amMeshLoadFlags::kNO_MATS);
    m_testCube->m_vecMeshes[0]->setMaterial(m_defaultMaterial);

    m_irradiance_Cube = loadCubeMap("Resources/3D_Meshes/Vela/Textures/Irradiance.dds", false);
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
    /**
    ***************************************************************************
    *
    *  @TODO: this 
    *
    ***************************************************************************
    */
    _pathName;
    _textureFlags;
    return nullptr;
  }

  amDXShaderResourceView*
  amDXGraphicsAPI::createTextureShaderResourceV(const String & _pathName,
                                                const uint32 _textureFlags) {
    amDXShaderResourceView* dxRTV = new amDXShaderResourceView();
    dxRTV->m_texResource = createTexture(_pathName, _textureFlags);
    m_pResourceManager->addTexture(dxRTV->m_texResource);
    return dxRTV;
  }

  amDXRenderTargetView*
  amDXGraphicsAPI::createRenderTargetV(const uint32 _height, 
                                       const uint32 _width, 
                                       const amFormats::E _format, 
                                       const float _scale) {

    amDXRenderTargetView* dxRTV = new amDXRenderTargetView(_height, _width, _scale);
    m_pDevice->createRenderTargetView(dxRTV,
                                      _format, 
                                      amResourceBindFlags::kBIND_RENDER_T_SHADER_R);
    m_pResourceManager->addRenderTarget(dxRTV);
    return dxRTV;
  }

  amDXDepthStencilView*
  amDXGraphicsAPI::createDepthStencilV(const uint32 _height,
                                       const uint32 _width,
                                       const uint32 _format) {

    amDXDepthStencilView* depth = new amDXDepthStencilView(_height, _width);
    m_pDevice->createDepthStencilView(depth, 
                                      amResourceBindFlags::kBIND_DEPTH_STENCIL,
                                      _format);
    m_pResourceManager->addTexture(depth->m_tex);
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
    return tex;
  }

  amDXTexture*
  amDXGraphicsAPI::createTexture(const String& _pathName, 
                                 const uint32 _textureFlags) {
    int32 width, height, channels;
    amDXTexture* tex = new amDXTexture();
    tex->m_resBindFlag = amResourceBindFlags::kBIND_SHADER_RESOURCE;
    UANSICHAR* texdata = stbi_load(_pathName.c_str(),
                                   &width,
                                   &height,
                                   &channels,
                                   STBI_rgb_alpha);
    tex->m_width = width;
    tex->m_height = height;

    /**
    ************************
    * Format Detection
    ************************
    */
    //Format is assumed an 8bit rgba texture
    tex->m_format = amFormats::kFORMAT_R8G8B8A8_UNORM;

    if (_textureFlags == amTexType::kMETALNESS ||
        _textureFlags == amTexType::kROUGHNESS) {
      //Format becomes greyScale
      tex->m_format = amFormats::kFORMAT_R8_UNORM;
    }

    else if (_textureFlags == amTexType::kLUT ||
             _textureFlags == amTexType::kCUBEMAP) {
      if (_textureFlags == amTexType::kCUBEMAP) {
        //Format becomes 16float for HDR lighting
        tex->m_format = amFormats::kFORMAT_R16G16B16A16_FLOAT;
      }
    }

    if (_textureFlags == amTexType::kHDR) {
      tex->m_tBufferF.resize(width * height * sizeof(HALF));
      memcpy(&tex->m_tBufferF[0], &texdata, width * height * sizeof(HALF));
    }
    else {
      uint32 arraySize = width * height;
      tex->m_tBuffer.resize(tex->m_tBuffer.size() + arraySize);
      memcpy(&tex->m_tBuffer[tex->m_tBuffer.size() - arraySize], 
             &tex->m_tBuffer[0], 
             arraySize * sizeof(UANSICHAR));
      //tex->m_tBuffer.resize(width * height * sizeof(UANSICHAR));
      //memcpy(&tex->m_tBuffer[0], &texdata, width * height * sizeof(UANSICHAR));
      //memcpy(&tex->m_tBuffer.begin(), &texdata, width * height * sizeof(UANSICHAR));
    }
    tex = createTexture(tex->m_height, 
                        tex->m_width, 
                        tex->m_format, 
                        amResourceBindFlags::kBIND_SHADER_RESOURCE);
    return tex;
  }

  amModel* 
  amDXGraphicsAPI::createModel(const String& _pathName, 
                               const uint32 _meshLoadFlags) {
    amModel* model = new amModel();
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(_pathName.c_str(),
                                             aiProcess_Triangulate |
                                             aiProcess_GenUVCoords |
                                             aiProcess_CalcTangentSpace |
                                             aiProcess_GenSmoothNormals |
                                             aiProcess_JoinIdenticalVertices |
                                             aiProcess_RemoveRedundantMaterials |
                                             aiProcess_SortByPType);
    if (!scene)
      return nullptr;
    uint32 nMeshes = scene->mNumMeshes;

    /**
    ************************
    *  If model loaded do a pass for each mesh
    ************************
    */
    for (uint32 i = 0; i < nMeshes; ++i) {
      amMesh* mesh = new amMesh();

      process_Mesh(scene->mMeshes[i], mesh, m_pDevice);
      if (_meshLoadFlags != amMeshLoadFlags::kNO_MATS) {
        if (i < scene->mNumMaterials) {
          process_Material(scene->mMaterials[scene->mMeshes[i]->mMaterialIndex], 
                           mesh, 
                           m_pDevice);
        }
      }
      model->m_vecMeshes.push_back(mesh);
    }
    // We're done. Everything will be cleaned up by the importer destructor
    //m_vecResources.push_back(model);

    return model;
  }

  amDXShaderResourceView* 
  amDXGraphicsAPI::loadCubeMap(const String & _pathFileName, 
                               const bool _hdr) {
    amDXTexture* tex = new amDXTexture();
    tex->m_resBindFlag = amResourceBindFlags::kBIND_SHADER_RESOURCE;
    DDS_Loader::dds_info out;
    DDS_Loader::dds_load_from_file(_pathFileName.c_str(), &out, 0);

    uint32 texSize = out.image.size;
    texSize;
    //m_pDevice->

    return nullptr;
    _hdr;
  }

  /**
  *****************************************************************************
  *
  *  @Helper functions for loading resources
  *
  *****************************************************************************
  */

  /**
  *----------------------------------------------------------------------------
  *  Process the mesh 
  *----------------------------------------------------------------------------
  */
  void
  amDXGraphicsAPI::process_Mesh(aiMesh* _aiMesh, 
                                amMesh* _mesh, 
                                amDevice* _dv) {
    /**
      ************************
      *  Load Vertex data for the mesh
      ************************
      */


    uint32 nvertx = _aiMesh->mNumVertices;
    _mesh->m_vb = new amDXVertexBuffer(nvertx);
    for (uint32 j = 0; j < nvertx; ++j) {
      _mesh->m_vb->m_vVertex[j].setVertexCoord(get_Pos(_aiMesh->mVertices[j]));
      _mesh->m_vb->m_vVertex[j].setVertexNormal(get_Pos(_aiMesh->mNormals[j]));
      _mesh->m_vb->m_vVertex[j].setVertexTangent(get_Pos(_aiMesh->mTangents[j]));
      _mesh->m_vb->m_vVertex[j].setVertexBinormal(get_Pos(_aiMesh->mBitangents[j]));

      /**
      ************************
      *  Load UV data for the mesh if it exists
      ************************
      */
      if (_aiMesh->mTextureCoords[0]) {
        _mesh->m_vb->m_vVertex[j].u = _aiMesh->mTextureCoords[0][j].x;
        _mesh->m_vb->m_vVertex[j].v = _aiMesh->mTextureCoords[0][j].y;
      }
    }

    /**
      ************************
      *  Load Index data for the mesh
      ************************
      */
    uint32 nIndex = 0;
    uint32 j = 0;
    uint32 nFaces = _aiMesh->mNumFaces;
    aiFace* face = nullptr;
    _mesh->m_ib = new amDXIndexBuffer(nFaces * 3);
    for (uint32 i = 0; i < nFaces; ++i) {
      face = &_aiMesh->mFaces[i];
      for (j = 0; j < face->mNumIndices; ++j) {
        _mesh->m_ib->m_vecIB[nIndex] = face->mIndices[j];
        ++nIndex;
      }
    }
    if (nIndex != nFaces * 3) {
      _mesh->m_ib->m_vecIB.resize(nIndex);
    }
    /**
    ************************
    *  Create the Index & Vertex Buffer in the device
    ************************
    */
    _dv->createVertexBuffer(_mesh->m_vb);
    _dv->createIndexBuffer(_mesh->m_ib);
  }

  /**
  *----------------------------------------------------------------------------
  *  Process the material
  *----------------------------------------------------------------------------
  */
  void
  amDXGraphicsAPI::process_Material(aiMaterial* _aiMat,
                                    amMesh* _mesh,
                                    amDevice* _dv) {
    /**
    ************************
    *  Load Material data
    ************************
    */
    uint32 nMatTextures = _aiMat->mNumProperties;
    //uint32 nModelTextures = static_cast<uint32>(_model->m_vecTex.size());
    _mesh->m_mat = new amMaterial();
    uint32 matTexCount = (nMatTextures > 5) ? 5 : nMatTextures;
    _mesh->m_mat->m_vecTex.reserve(matTexCount);
    //_model->m_vecTex.resize(nModelTextures + nMatTextures);

    for (uint32 j = 0; j < matTexCount; ++j) {
      uint32 texWidth =  amMath::sqrt(_aiMat->mProperties[j]->mDataLength);
      uint32 texHeight = texWidth;
      amDXShaderResourceView* tex = new amDXShaderResourceView(texHeight, 
                                                               texWidth);
      tex->m_texResource->m_fileName = _aiMat->GetName().C_Str();
      _mesh->m_mat->m_vecTex.push_back(tex);
      uint32 texTYpe = _aiMat->mProperties[j]->mType;
      /**
      ************************************************
      *  Get texture types of the material
      ************************************************
      */
      if (texTYpe == aiTextureType::aiTextureType_DIFFUSE) {
        _mesh->m_mat->m_vecTex[j]->m_texResource->m_tType = amTexType::E::kALBEDO;
      }
      else if (texTYpe == aiTextureType::aiTextureType_EMISSIVE) {
        _mesh->m_mat->m_vecTex[j]->m_texResource->m_tType = amTexType::E::kEMISSIVE;
      }
      else if (texTYpe == aiTextureType::aiTextureType_NORMALS) {
        _mesh->m_mat->m_vecTex[j]->m_texResource->m_tType = amTexType::E::kNORMAL;
      }
      else if (texTYpe == 
               aiTextureType::AI_MATKEY_GLTF_PBRMETALLICROUGHNESS_METALLICROUGHNESS_TEXTURE) {
        //if (_aiMat->GetTexture(AI_MATKEY_GLTF_PBRMETALLICROUGHNESS_METALLIC_FACTOR, j, )) {
          //TODO: add metalness & roughness, revert to spec = metal & shiny = rough
        //}
      }
      else {
        _mesh->m_mat->m_vecTex[j]->m_texResource->m_tType = amTexType::E::kDEFAULT;
      }
      /**
      ************************************************
      *  Copy the texture buffer
      ************************************************
      */
      _mesh->m_mat->m_vecTex[j]->m_texResource->m_format = amFormats::kFORMAT_R8G8B8A8_UNORM;
      memcpy(&_mesh->m_mat->m_vecTex[j]->m_texResource->m_tBuffer,
             _aiMat->mProperties[j]->mData,
             _aiMat->mProperties[j]->mDataLength);
      /**
      ************************************************
      *  Save a copy of the pointer to the model
      ************************************************
      */
      //_model->m_vecTex[nModelTextures + j]->m_tex = _mesh->m_mat->m_vecTex[j]->m_texResource;
      _dv->createShaderResourceView(tex,
                                    tex->m_texResource,
                                    amSRV_Types::kSRV_TEXTURE2D,
                                    amFormats::kFORMAT_R8G8B8A8_UNORM,
                                    amResourceBindFlags::kBIND_SHADER_RESOURCE);
      
      //_mesh->m_mat->m_vecTex.reserve(nMatTextures);
      //_mesh->m_mat->m_vecTex[j] = tex;
      //_mesh->m_mat->m_vecTex[j]->m_texResource->m_fileName = _aiMat->GetName().C_Str();
      //_mesh->m_mat->m_vecTex[j]->m_texResource->m_tBuffer.resize(_aiMat->mProperties[j]->mDataLength * sizeof(SIZE_T));
      
    }
  }

  String
  aiStr_to_amStr(aiString& _aiStr) {
    return _aiStr.C_Str();
  }

  amVector3
  get_Pos(const aiVector3D& other) {
    amVector3 v;
    v.x = other.x;
    v.y = other.y;
    v.z = other.z;
    return v;
  }

  amVector2
  getUV(const aiVector3t<ai_real>& other) {
    amVector2 v;
    v.x = other.x;
    v.y = other.y;
    return v;
  }

  amVector4
  getColorRGBA(const aiColor4D& other) {
    amVector4 v;
    v.x = other.r;
    v.y = other.g;
    v.z = other.b;
    v.w = other.a;
    return v;
  }

  aiString
  str_to_aiStr(const String& str) {
    aiString aiStr;
    aiStr.Set(str);
    return aiStr;
  }
}
