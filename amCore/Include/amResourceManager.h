#pragma once
#include "amPrerequisitesCore.h"

namespace amEngineSDK {
  class amResource;
  class amDevice;
  class amTexture;
  class amMaterial;
  class amShaderResourceView;
  class amTextureObject;
  class amRenderTarget;
  class amRenderTargetView;
  class amModel;
  class amMesh;

  class AM_CORE_EXPORT amResourceManager
  {
  public:
    amResourceManager() = default;
    ~amResourceManager() = default;

    uint32 
    addModel(amModel* _model);

    uint32 
    addMaterial(amMaterial* _mat);

    uint32 
    addRenderTarget(amRenderTargetView* _rtv);

    uint32 
    addSharedResource(amResource* _res);

    uint32 
    addTexture(amResource* _tex);


    amMaterial* m_defaultMat = nullptr;

    Vector<amResource*> m_vecModels;
    Vector<amResource*> m_vecSceneSharedRes;
    Vector<amResource*> m_vecTextures;
    Vector<amResource*> m_vecRenderTargets;
    Vector<amResource*> m_vecMaterials;
  };
}
