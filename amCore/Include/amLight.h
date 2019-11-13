#pragma once
#include "amPrerequisitesCore.h"
#include "amResource.h"

namespace amEngineSDK {
  class amVector3;
  class amVector4;
  class amColor;

  namespace amLightMode {
    enum E
    {
      kPOINTLIGHT,
      kSPOTLIGHT,
      kDIRECTIONAL
    };
  }

  class AM_CORE_EXPORT amLight : public amResource
  {
  public:
    amLight();
    amLight(const uint32 _lightmode, 
            const amVector3& _pos = amVector3::Zero, 
            const amColor& _color = amColor::WHITE, 
            const amVector3& _dir = amVector3::Front, 
            const float _intensity = 1.0f, 
            const float _radius = 1.0f);
    ~amLight();

    
    amVector3 m_position;
    amVector3 m_direction;
    amColor m_color;
    float m_intensity;
    float m_radius;
    uint32 m_lightMode;
  };
}
