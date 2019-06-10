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

  class AM_CORE_EXPORT amGraphicsAPI
  {
  public:
    amGraphicsAPI();
    ~amGraphicsAPI();

    virtual void 
    createVertexBuffer(int64 nVertex, int64 vertexSize);

    virtual void 
    Draw(amResource* _pMesh, amMaterial* _pMat, amRenderTarget* _pOutRenderTarget);

    virtual void 
    init(void* _wnd);

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
    renderResourcesOnCam(amCamera* _cam, amRenderPass* _pass);

    virtual void 
    ClearRenderTarget();

    virtual void 
    Present();

    virtual void 
    setShaders(amVertexShader* _VS, amPixelShader* _PS);

    float m_fov;
    amRenderManager* m_pRenderManager;
    amCameraManager* m_pCamManager;
    amResourceManager* m_pResourceManager;
  };
}
