/**
***********************************************
 * @file CGraphicsAPI.h
 * @date 2018/10/17
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief  Implements a base Graphics API 
 *
 * @note
***********************************************
*/
#pragma once
/**
************************
*
*  Includes
*
************************
*/
#include <amPrerequisitesUtilities.h>
#include "amPrerequisitesCore.h"
#include "amDevice.h"
#include "amDeviceContext.h"
#include "amRenderManager.h"
#include "amCameraManager.h"
#include "amResourceManager.h"

namespace amEngineSDK {
  class amRenderPass;
  class amRenderTarget;
  class amMaterial;
  class amSceneGraph;
  class amRenderPass;

  class AM_CORE_EXPORT amGraphicsAPI
  {
  public:
    amGraphicsAPI();
    ~amGraphicsAPI();

    virtual void 
    createVertexBuffer(int64 nVertex, int64 vertexSize);

    virtual void 
    Draw(amResource* _pMesh,
         amRenderTarget* _pOutRenderTarget,
         amMaterial* _pMat = nullptr);

    virtual void 
    init(void* _wnd);

    virtual void 
    Update();

    virtual void 
    Render();

    virtual void 
    destroy();

    virtual void
    initContent();

    virtual void
    initSystems();

    virtual void 
    setManagers();

    virtual void 
    initScene();

    virtual void 
    renderResourcesOnCam(amCamera* _cam, amRenderPass* _pass);

    virtual void 
    setRenderTargets(const Vector<amRenderTarget*>& _rt);

    virtual void 
    clearRenderTarget();

    virtual void 
    setShaderResources(Vector<amResource*> _vecRes, uint32 _shaderFlags);

    virtual void 
    Present();

    virtual void 
    setShaders(amVertexShader* _VS, amPixelShader* _PS);

    virtual void
    setShaders(amRenderPass* _pass);

    /**
    ************************
    * @brief These are called from the render manager to set shader specific constBuffers
    ************************
    */
    virtual void
    setConstantBuffer(amConstantBuffer* _cb, int32 _shaderFlags);

    virtual void
    setConstantBuffer(Vector<amConstantBuffer*> _cbVec, int32 _shaderFlags);

    float m_fov;
    amRenderManager* m_pRenderManager;
    amCameraManager* m_pCamManager;
    amResourceManager* m_pResourceManager;

  };
}
