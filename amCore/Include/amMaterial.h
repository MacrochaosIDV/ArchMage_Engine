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
#include "amVector4.h"

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
    amMaterial(const String _name);
    amMaterial(const Vector<amShaderResourceView*>& _vecTex);
    amMaterial(const String _name, const Vector<amShaderResourceView*>& _vecTex);
    ~amMaterial();

    void
    addTextureToMat(amShaderResourceView* _tex);
   private:
     void
     zero();

   public:

    Vector<amShaderResourceView*> m_vecTex;
    String m_matName;

    amVector4 m_colorAlbedo;
    amVector4 m_colorEmissive;
    amVector4 m_colorNormal;
    float m_metalness;
    float m_roughness;

   private:
    uint8 m_matSize;
  };
}
