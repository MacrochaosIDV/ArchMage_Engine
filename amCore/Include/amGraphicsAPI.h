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
  class amMesh;
  class amRenderPass;

  class AM_CORE_EXPORT amGraphicsAPI
  {
  public:
    amGraphicsAPI();
    ~amGraphicsAPI();

    virtual void 
    Draw(amMesh* _pMesh);

    virtual void 
    init(void* _wnd);

    virtual void 
    Update();

    virtual void
    Run();

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
    clearRenderTargets();

    virtual void 
    setShaderResources(Vector<amResource*> _vecRes, uint32 _shaderFlags);

    virtual void 
    Present();

    virtual void 
    setShaders(amVertexShader* _VS, amPixelShader* _PS);

    virtual void
    setShaders(amRenderPass* _pass);

    virtual void 
    setRenderPass(amRenderPass* _pass, amDeviceContext* _dc);

    /**
    ************************
    * @brief These are called from the render manager to set shader specific constBuffers
    ************************
    */
    virtual void
    setConstantBuffer(amConstantBuffer* _cb, const int32 _shaderFlags);

    virtual void
    setConstantBuffer(Vector<amConstantBuffer*> _cbVec, 
                      const int32 _shaderFlags);

    
    virtual amModel* 
    createModel(const String& _pathName,
                const uint32 _meshLoadFlags = 0);

    virtual amShaderResourceView* 
    loadCubeMap(const String& _pathFileName, 
                const bool _hdr);

    float m_bloomIntensity;
    float m_fov;
    amRenderManager* m_pRenderManager;
    amCameraManager* m_pCamManager;
    amResourceManager* m_pResourceManager;
  };
}
