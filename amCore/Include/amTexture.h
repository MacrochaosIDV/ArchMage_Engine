#pragma once
#include "amPrerequisitesCore.h"
#include "amResource.h"

namespace amEngineSDK {
  class amResourceManager;

  namespace amTexType {
    enum E
    {
      kDEFAULT = 0,
      kALBEDO,
      kNORMAL,
      kEMISSIVE,
      kAO,
      kMETALNESS,
      kROUGHNESS,
      kDEPTH,
      kHEIGHT,
      kCUBEMAP,
      kRENDERTARGET,
      kLUT,
      kCOUNT
    };
  }
  class AM_CORE_EXPORT amTexture : public amResource
  {
  public:
    amTexture(Vector<ANSICHAR>* _tBuffer, 
              amTexType::E _tType = amTexType::E::kALBEDO);
    amTexture();
    ~amTexture();

    virtual void
    setTex(Vector<ANSICHAR>* _tBuffer, 
           amTexType::E _tType = amTexType::E::kDEFAULT);

    virtual void
    loadFromFile(const String& _filePathName, 
                 amResourceManager* _pRM);

    virtual void
    unload();

    virtual void
    resizeTex(const uint32 _size);

    Vector<ANSICHAR> m_tBuffer;
    String m_fileName;
    amTexType::E m_tType;
    uint32 m_height;
    uint32 m_width;
    void* m_pDesc;
    void* m_apiPtr;
  };
}
