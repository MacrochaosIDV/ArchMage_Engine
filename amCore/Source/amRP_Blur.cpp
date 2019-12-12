#include "amRP_Blur.h"

namespace amEngineSDK {
  amRP_Blur::amRP_Blur() {
  
  }

  amRP_Blur::amRP_Blur(const uint32 _pass, 
                       const String& _strPS, 
                       const String& _strVS, 
                       const String& _name) {
    m_renderPassStage = _pass;
    m_strPS = _strPS;
    m_strVS = _strVS;
    m_passName = _name;
  }

  amRP_Blur::~amRP_Blur() {}
}
