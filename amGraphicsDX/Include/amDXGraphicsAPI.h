/**
***********************************************
 * @file CGraphicsAPI.h
 * @date 2018/10/17
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief  Implements a Graphics API of DirectX
 *
 * @note
***********************************************
*/
#pragma once
#include "amDXPreReqs.h"
/**
************************
*
*  Includes 
*
************************
*/
#include <amGraphicsAPI.h>
#include <amCamera.h>
#include <amVector4.h>
#include <amLight.h>

struct aiMesh;
struct aiMaterial;

namespace amEngineSDK {
  class amMesh;
  class amModel;
  class amMaterial;
  class amTexture;
  class amDXTexture;
  class amDXConstantBuffer;
  class amDXSamplerState;
  class amDXDepthStencilView;
  class amDXPixelShader;
  class amDXVertexShader;
  class amDXInputLayout;
  class amDXShaderResourceView;
  class amDXRenderTargetView;
  class amDXSwapChain;
  class amDXDeviceContext;
  class amDXDevice;
  class amCamera;
  class amVector4;
  class amRenderPass;
  class amLight;
  class amRP_GBuffer;
  class amRP_SSAO;
  class amRP_Blur;
  class amRP_DownScaleBloom;
  class amRP_Lighting;
  class amRP_Luminance;

  class AM_GRAPHICSDX_EXPORT amDXGraphicsAPI : public amGraphicsAPI
  {
   public:
    amDXGraphicsAPI() = default;
    ~amDXGraphicsAPI();

    void
    init(void* _hWnd);

    virtual void
    destroy() override;

    virtual void 
    Update() override;

    void 
    CleanupDevice();

    /**
    ************************
    *  @brief The function that gets called from top to run all things
    ************************
    */
    virtual void 
    Run() override;

    virtual void
    initContent() override;

    virtual void
    setManagers() override;

    virtual void
    initSystems(void* _hWnd);

    virtual void 
    setShaderResources(Vector<amResource *> _vecRes, 
                       uint32 _shaderFlags) override;

    virtual void 
    Draw(amMesh* _pMesh) override;

    virtual void
    setConstantBuffer(amConstantBuffer* _cb, int32 _shaderFlags) override;

    virtual void
    setConstantBuffer(Vector<amConstantBuffer*> _cbVec, 
                      int32 _shaderFlags) override;

    virtual void 
    Present() override;

    virtual void
    clearRenderTargets() override;

    virtual void 
    setRenderPass(amRenderPass* _pass, amDeviceContext* _dv) override;

    virtual void
    createPassShaders(amPixelShader** _ps, amVertexShader** _vs) override;

    void 
    tmpLoadResource();

    /**
    ************************************************
    *
    *  @section API resource creation
    *
    ************************************************
    */

    virtual amDXShaderResourceView*
    createTextureShaderResourceV(const String& _pathName,
                                 const uint32 _textureFlags = 0);

    virtual amDXShaderResourceView*
    loadTexture(const String& _pathName,
                const uint32 _textureFlags = 0);


    virtual amDXRenderTargetView*
    createRenderTargetV(const uint32 _height,
                        const uint32 _width,
                        const uint32 _format,
                        const float _scale = 1.0f);

    virtual amDXTexture*
    createTexture(const uint32 _height,
                  const uint32 _width,
                  const uint32 _format,
                  const int32 _rbf);

    virtual amDXTexture*
    createTexture(const String& _pathName, 
                  const uint32 _textureFlags = 0);

    virtual amDXDepthStencilView*
    createDepthStencilV(const uint32 _height,
                        const uint32 _width,
                        const uint32 _format = amFormats::kFORMAT_D24_UNORM_S8_UINT);

    virtual amModel*
    createModel(const String& _pathName, 
                const uint32 _meshLoadFlags = 0) override;

    amDXShaderResourceView* 
    loadCubeMap(const String& _pathFileName);

   private:
    void
    process_Material(aiMaterial* _aiMat,
                     amMesh* _mesh,
                     amDevice* _dv);

    void 
    process_Mesh(aiMesh* _aiMesh, amMesh* _mesh, amDevice* _dv);
   public:

    

    /**
    ************************************************
    ************************************************
    */

    amVector4 m_clearColor;

    HWND m_hWnd = 0;
    amCamera m_cam;
    amMatrix4x4 matProjecton;
    amMatrix4x4 matView;
    amDXConstantBuffer* m_nearPlane = nullptr;
    amDXConstantBuffer* m_farPlane = nullptr;
    amDXConstantBuffer* m_matWorld = nullptr;
    amDXConstantBuffer* m_matViewProjection = nullptr;

    amDXShaderResourceView* m_specularIBL_Cube = nullptr;
    amDXShaderResourceView* m_irradiance_Cube = nullptr;

    amRenderTargetView* m_rtFullColor = nullptr;
    amRenderTargetView* m_rtEmissive = nullptr;
    amRenderTargetView* m_rtNormals = nullptr;
    amRenderTargetView* m_rtBlur = nullptr;
    amRenderTargetView* m_rtLuminance = nullptr;
    amRenderTargetView* m_rtMADR = nullptr;

    amRP_GBuffer* m_RP_Gbuffer = nullptr;
    amRP_SSAO* m_RP_SSAO = nullptr;
    amRP_Blur* m_RP_Blur = nullptr;
    amRP_DownScaleBloom* m_RP_Bloom = nullptr;
    amRP_Lighting* m_RP_Lighting = nullptr;
    amRP_Luminance* m_RP_Luminance = nullptr;


    amMaterial* m_defaultMaterial = nullptr;
    amLight m_light;

    amModel* m_testCube = nullptr;

    amModel* m_screenAlignedQuad = nullptr;
    
    amDXDeviceContext*                  m_pContext = nullptr;
    amDXDepthStencilView*               m_pDepthStencilView = nullptr;
    amDXRenderTargetView*               m_pRenderTargetView = nullptr;
    amDXSamplerState*                   m_pSamplerLinear = nullptr;
    amDXInputLayout*                    m_pInputLayout = nullptr;
    amDXTexture*                        m_pDepthStencil = nullptr;
    amDXShaderResourceView*             m_pTextureRV = nullptr;
    amDXSwapChain*                      m_pSwapChain = nullptr;
    amDXDevice*                         m_pDevice = nullptr;
    amDXConstantBuffer*                 m_pCB_VP = nullptr;
  };
}
