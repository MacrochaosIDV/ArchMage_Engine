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

    void 
    resize(const uint32 _height, const uint32 _width);

    virtual void
    resizeTex(const uint32 _size);
    /**
    ************************
    * The data buffer
    ************************
    */
    Vector<ANSICHAR> m_tBuffer;
    /**
    ************************
    * A ptr for creating a buffer of another type
    ************************
    */
    void* m_tBufferF;
    String m_fileName;
    amTexType::E m_tType;
    amFormats::E m_format;
    uint32 m_height;
    uint32 m_width;
    bool m_hrd;
  };
}
