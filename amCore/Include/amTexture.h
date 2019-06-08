#pragma once
#include "amPrerequisitesCore.h"
#include "amResource.h"

namespace amEngineSDK {
  namespace amTexType {
    enum E
    {
      kDEF = 0,
      kALBEDO,
      kNORMAL,
      kEMISSIVE,
      kAO,
      kMETALNESS,
      kROUGHNESS,
      kDEPTH,
      kCUBEMAP,
      kRENDERTARGET,
      kCOUNT
    };
  }
  class AM_CORE_EXPORT amTexture : public amResource
  {
  public:
    amTexture(Vector<UANSICHAR>* _tBuffer, amTexType::E _tType = amTexType::E::kALBEDO);
    amTexture();
    ~amTexture();

    void 
    setTex(Vector<UANSICHAR>* _tBuffer, amTexType::E _tType = amTexType::E::kDEF);

    Vector<UANSICHAR> m_tBuffer;
    String m_fileName;
    amTexType::E m_tType;
  };
}
