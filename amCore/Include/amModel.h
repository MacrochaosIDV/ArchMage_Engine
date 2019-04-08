#pragma once
#include "amPrerequisitesCore.h"
#include "amResource.h"

namespace amEngineSDK {
  class amMesh;
  class amTexture;
  class amMaterial;

  class AM_CORE_EXPORT amModel : public amResource
  {
  public:
    amModel();
    ~amModel();
    
    Vector<amMesh*> m_vecMeshes;
    Vector<amTexture*> m_vecTex;
    Vector<amMaterial*> m_vecMats;
  };
}
