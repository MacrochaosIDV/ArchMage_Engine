#include "amColor.h"

namespace amEngineSDK {
  amColor::amColor() {}

  amColor::amColor(const UANSICHAR _r, 
                   const UANSICHAR _g, 
                   const UANSICHAR _b, 
                   const UANSICHAR _a) {
    m_r = _r;
    m_g = _g;
    m_b = _b;
    m_a = _a;
  }

  amColor::~amColor() {}

  const amColor
  amColor::RED = amColor(FORCE_INIT_COLOR::kRED);

  const amColor
  amColor::GREEN = amColor(FORCE_INIT_COLOR::KGREEN);

  const amColor
  amColor::BLUE = amColor(FORCE_INIT_COLOR::kBLUE);

  const amColor
  amColor::YELLOW = amColor(FORCE_INIT_COLOR::kYELLOW);

  const amColor
  amColor::CYAN = amColor(FORCE_INIT_COLOR::kCYAN);

  const amColor
  amColor::MAGENTA = amColor(FORCE_INIT_COLOR::kMAGENTA);

  const amColor
  amColor::WHITE = amColor(FORCE_INIT_COLOR::kWHITE);

  const amColor
  amColor::BLACK = amColor(FORCE_INIT_COLOR::kBLACK);

  amColor::amColor(const uint32 val) {
    memset(this, 0, sizeof(amColor));
    if (val == FORCE_INIT_COLOR::kWHITE) {
      m_r = m_g = m_b = m_a = 1;
    }
    if (val == FORCE_INIT_COLOR::kRED) {
      m_r = m_a = 1;
    }
    if (val == FORCE_INIT_COLOR::KGREEN) {
      m_g = m_a = 1;
    }
    if (val == FORCE_INIT_COLOR::kBLUE) {
      m_b = m_a = 1;
    }
    if (val == FORCE_INIT_COLOR::kYELLOW) {
      m_r = m_g = m_a = 1;
    }
    if (val == FORCE_INIT_COLOR::kCYAN) {
      m_g = m_b = m_a = 1;
    }
    if (val == FORCE_INIT_COLOR::kMAGENTA) {
      m_r = m_b = m_a = 1;
    }
  }

}
