/**
***********************************************
 * @file amMaterial.h
 * @date 2019/06/27
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief Implements a material class for rendering
 *
 * Usual material layout
 *
 *  m_vecTex[0] = diffuse map
 *  m_vecTex[1] = normal map
 *  m_vecTex[2] = emissive map
 *  m_vecTex[3] = metalness map
 *  m_vecTex[4] = roughness map
 *
 * @note
***********************************************
*/

#pragma once
#include "amPrerequisitesCore.h"
#include "amResource.h"

namespace amEngineSDK {
  class amTexture;
  class amDevice;
  class amDeviceContext;
  class amShaderResourceView;

  class AM_CORE_EXPORT amMaterial : public amResource
  {
  public:
    amMaterial();
    ~amMaterial();

    void
    createTexturesAsRSV(amDevice* _dv);

    void 
    setTexsAs_VS_RSV(amDeviceContext* _dc);

    void
    setTexsAs_PS_RSV(amDeviceContext* _dc);

    Vector<amTexture*> m_vecTex;
    Vector<amShaderResourceView*> m_vecSRV;
    String m_matName;
  };
}
