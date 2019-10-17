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
    createVertexBuffer(int64 nVertex, int64 vertexSize);

    virtual void 
    Draw(amMesh* _pMesh,
         amRenderTarget* _pOutRenderTarget,
         amMaterial* _pMat = nullptr);

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

    /**
    ************************
    *
    *
    *  section@ API resource creation
    *
    *
    ************************
    */

    /*virtual amShaderResourceView* 
    createTextureShaderResourceV(const String& _pathName, 
                                 const uint32 _textureFlags = 0);

    virtual amShaderResourceView*
    loadTexture(const String& _pathName,
                const uint32 _textureFlags = 0);

    virtual amRenderTargetView*
    createRenderTargetV(const uint32 _height,
                        const uint32 _width,
                        const amFormats::E _format,
                        const float _scale = 1.0f);

    virtual amTexture*
    createTexture(const uint32 _height,
                  const uint32 _width,
                  const amFormats::E _format);

    virtual amTexture*
    createTexture(const String& _pathName, const uint32 _textureFlags = 0);

    virtual amModel* 
    createModel(const String& _pathName,
                const uint32 _meshLoadFlags = 0);

    virtual amDepthStencilView*
    createDepthStencilV(const uint32 _height,
                        const uint32 _width,
                        const amFormats::E _format);

    amMaterial*
    CreateMaterial(amTextureObject* _tex, const String& _matName = "Material");

    amMaterial*
    CreateMaterial(Vector<amTextureObject*>& _texVec,
                   const String& _matName = "Material");

    amMaterial*
    CreateMaterial(const String& _pathName, uint32 _textureFlags = 0);*/


    float m_bloomIntensity;
    float m_fov;
    amRenderManager* m_pRenderManager;
    amCameraManager* m_pCamManager;
    amResourceManager* m_pResourceManager;
  };
}
