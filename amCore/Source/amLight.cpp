#include "amLight.h"
#include "amVector4.h"

#include "amColor.h"

namespace amEngineSDK {
  amLight::amLight() {
    memset(this, 0, sizeof(amLight));
    m_color = amColor::WHITE;
    m_intensity = m_radius = 1;
  }

  amLight::amLight(const uint32 _lightmode, 
                   const amVector3& _pos, 
                   const amColor& _color, 
                   const amVector3& _dir, 
                   const float _intensity, 
                   const float _radius) {
    m_lightMode = _lightmode;
    m_position = _pos;
    m_color = _color;
    m_direction = _dir;
    m_intensity = _intensity;
    m_radius = _radius;
  }

  amLight::~amLight() {}
}
