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

namespace amEngineSDK {
  class amMesh;
  class amModel;
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

  class AM_GRAPHICSDX_EXPORT amDXGraphicsAPI : public amGraphicsAPI
  {
   public:
    amDXGraphicsAPI() = default;
    ~amDXGraphicsAPI();

    void 
    createVertexBuffer(int32 nVertex, int32 vertexSize);

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
    setShaderResources(Vector<amResource *> _vecRes, uint32 _shaderFlags) override;

    virtual void 
    Draw(amMesh* _pMesh,
         amRenderTarget* _pOutRenderTarget, 
         amMaterial* _pMat = nullptr) override;

    virtual void
    setConstantBuffer(amConstantBuffer* _cb, int32 _shaderFlags) override;

    virtual void
    setConstantBuffer(Vector<amConstantBuffer*> _cbVec, int32 _shaderFlags) override;

    virtual void 
    Present() override;

    virtual void
    clearRenderTargets() override;

    void 
    tmpLoadResource();

    /**
    ************************
    *
    *  @section API resource creation
    *
    ************************
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
                        const amFormats::E _format,
                        const float _scale = 1.0f);

    virtual amDXTexture*
    createTexture(const uint32 _height,
                  const uint32 _width,
                  const amFormats::E _format,
                  const int32 _rbf);

    virtual amDXTexture*
    createTexture(const String& _pathName, 
                  const uint32 _textureFlags = 0);

    virtual amModel*
    createModel(const String& _pathName,
                const uint32 _meshLoadFlags = 0);

    virtual amDXDepthStencilView*
    createDepthStencilV(const uint32 _height,
                        const uint32 _width,
                        const uint32 _format = amFormats::kFORMAT_D24_UNORM_S8_UINT);

    amMaterial*
    CreateMaterial(amTextureObject* _tex, 
                   const String& _matName = "Material");

    amMaterial*
    CreateMaterial(const String& _pathName, uint32 _textureFlags = 0);

    amModel* 
    CreateModel(const String& _pathName, const uint32 _meshLoadFlags = 0);





    amVector4 m_clearColor;

    HWND m_hWnd = 0;
    amCamera m_cam;
    amMatrix4x4 matProjecton;
    amMatrix4x4 matView;
    amDXConstantBuffer* m_nearPlane;
    amDXConstantBuffer* m_farPlane;
    amDXConstantBuffer* m_matWorld;
    amDXConstantBuffer* m_matViewProjection;

    amRenderTargetView* m_rtFullColor;
    amRenderTargetView* m_rtEmissive;
    amRenderTargetView* m_rtNormals;
    amRenderTargetView* m_rtBlur;
    amRenderTargetView* m_rtLuminance;
    amRenderTargetView* m_rtMADR;

    amModel* m_testCube;
    
    amDXDeviceContext*                  m_pContext = NULL;
    amDXDepthStencilView*               m_pDepthStencilView = NULL;
    amDXRenderTargetView*               m_pRenderTargetView = NULL;
    amDXSamplerState*                   m_pSamplerLinear = NULL;
    amDXInputLayout*                    m_pInputLayout = NULL;
    amDXTexture*                        m_pDepthStencil = NULL;
    amDXVertexShader*                   m_pVertexShader = NULL;
    amDXPixelShader*                    m_pPixelShader = NULL;
    amDXShaderResourceView*             m_pTextureRV = NULL;
    amDXSwapChain*                      m_pSwapChain = NULL;
    amDXDevice*                         m_pDevice = NULL;
    amDXConstantBuffer*                 m_pCB_VP = NULL;

    /**
    ************************
    *
    /**
    ************************
    *
    *  @PRIORITY_1_TODO: re write resource creation process to that
    *  resManager::get data -> Api::create ptrs -> resManager::store ptrd
    *
    ************************
    *
    *
    ************************
    */
  };
}
