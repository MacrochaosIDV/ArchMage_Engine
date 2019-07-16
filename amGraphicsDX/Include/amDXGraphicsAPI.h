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
#include "amDXDevice.h"
#include "amDXDeviceContext.h"
#include "amDXSwapChain.h"
#include "amDXRenderTargetView.h"
#include "amDXInputLayout.h"
#include "amDXIndexBuffer.h"
#include "amDXVertexBuffer.h"
#include "amDXShaderResourceView.h"
#include "amDXVertexShader.h"
#include "amDXPixelShader.h"
#include "amDXDepthStencilView.h"
#include "amDXTexture.h"
#include "amDXSamplerState.h"
#include "amDXConstantBuffer.h"

namespace amEngineSDK {
  class amMesh;

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

    void 
    CleanupDevice();

    virtual void 
    Render() override;

    virtual void
    initContent() override;

    virtual void
    setManagers() override;

    virtual void
    initSystems(void* _hWnd);

    virtual void 
    setShaderConstantBuffers(Vector<amResource *> _vecRes, uint32 _shaderFlags) override;

    virtual void 
    Draw(amResource* _pMesh, amMaterial* _pMat, amRenderTarget* _pOutRenderTarget) override;

    void 
    tmpLoadResource();

    HWND m_hWnd = NULL;
    amCamera cam;
    amMatrix4x4 matProjecton;
    
    amDXDeviceContext*                  m_pImmediateContext = NULL;
    amDXDepthStencilView*               m_pDepthStencilView = NULL;
    amDXRenderTargetView*               m_pRenderTargetView = NULL;
    amDXSamplerState*                   m_pSamplerLinear = NULL;
    amDXInputLayout*                    m_pVertexLayout = NULL;
    amDXTexture*                        m_pDepthStencil = NULL;
    amDXVertexShader*                   m_pVertexShader = NULL;
    amDXPixelShader*                    m_pPixelShader = NULL;
    amDXShaderResourceView*             m_pTextureRV = NULL;
    amDXSwapChain*                      m_pSwapChain = NULL;
    amDXDevice*                         m_pDevice = NULL;
    amDXConstantBuffer*                 m_pCB_VP = NULL;
  };
}
