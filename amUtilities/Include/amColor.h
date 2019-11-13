#pragma once
#include "amPrerequisitesUtilities.h"

namespace amEngineSDK {

  namespace FORCE_INIT_COLOR {
    enum E
    {
      kRED = 0,
      KGREEN,
      kBLUE,
      kYELLOW,
      kCYAN,
      kMAGENTA,
      kWHITE,
      kBLACK,
      kCOUNT
    };
  }

  class AM_UTILITIES_EXPORT amColor
  {
  public:
    amColor();
    amColor(const UANSICHAR _r, 
            const UANSICHAR _g, 
            const UANSICHAR _b, 
            const UANSICHAR _a = 255);
    ~amColor();

    static const amColor RED;
    static const amColor GREEN;
    static const amColor BLUE;
    static const amColor YELLOW;
    static const amColor CYAN;
    static const amColor MAGENTA;
    static const amColor WHITE;
    static const amColor BLACK;

    amColor
    (const uint32 val);

    UANSICHAR m_r;
    UANSICHAR m_g;
    UANSICHAR m_b;
    UANSICHAR m_a;
  };
}
