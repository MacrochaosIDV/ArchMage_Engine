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
    initSystems(void* _hWnd);


    HWND m_hWnd = NULL;
    
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

    //amDXVertexBuffer*                   m_pVertexBuffer = NULL;
    //amDXIndexBuffer*                    m_pIndexBuffer = NULL;
    //amDXConstantBuffer*                 m_pCBNeverChanges = NULL;
    //amDXConstantBuffer*                 m_pCBChangeOnResize = NULL;
    //amDXConstantBuffer*                 m_pCBChangesEveryFrame = NULL;
    
  };
}
