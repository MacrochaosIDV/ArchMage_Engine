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
  class amTextureObject;
  class amShaderResourceView;

  class AM_CORE_EXPORT amMaterial : public amResource
  {
  public:
    amMaterial();
    ~amMaterial();

    void
    createTexturesAsRSV(amDevice* _dv,
                        const int32 = amSRV_Types::E::kSRV_TEXTURE2D,
                        const int32 = amFormats::E::kFORMAT_R8G8B8A8_UINT);

    void 
    setTexsAs_VS_RSV(amDeviceContext* _dc);

    void
    setTexsAs_PS_RSV(amDeviceContext* _dc);

    Vector<amTextureObject*> m_vecTex;
    //Vector<amShaderResourceView*> m_vecSRV;
    String m_matName;
  };
}
