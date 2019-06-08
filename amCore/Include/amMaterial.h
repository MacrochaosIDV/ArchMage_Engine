#pragma once
#include "amPrerequisitesCore.h"
#include "amResource.h"

namespace amEngineSDK {
  class amTexture;

  class AM_CORE_EXPORT amMaterial : public amResource
  {
  public:
    amMaterial();
    ~amMaterial();

    /**
    ************************
    *  m_vecTex[0] = diffuse map
    *  m_vecTex[1] = normal map
    *  m_vecTex[2] = emissive map
    *  m_vecTex[3] = metalness map
    *  m_vecTex[4] = roughness map
    ************************
    */
    Vector<amTexture*> m_vecTex;
    String m_matName;
  };
}
