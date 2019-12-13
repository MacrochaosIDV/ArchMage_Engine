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
      kHDR,
      kCOUNT
    };
  }

  struct cubeMapLoadAssist 
  {
    uint32 texSize;
    uint32 hdrSize;
    uint32 height;
    uint32 width;
    uint32 side0_OffSet;
    uint32 side1_OffSet;
    uint32 side2_OffSet;
    uint32 side3_OffSet;
    uint32 side4_OffSet;
    uint32 side5_OffSet;
  };

  class AM_CORE_EXPORT amTexture : public amResource
  {
  public:
    amTexture(Vector<UANSICHAR>* _tBuffer, 
              amTexType::E _tType = amTexType::E::kALBEDO);
    amTexture();
    ~amTexture();

    virtual void
    setTex(Vector<UANSICHAR>* _tBuffer,
           amTexType::E _tType = amTexType::E::kDEFAULT);

    virtual void
    unload();

    void 
    resize(const uint32 _height, const uint32 _width);

    virtual void
    resizeTex(const uint32 _size);

    uint32 
    getSize();
    /**
    ************************
    * The data buffer
    ************************
    */
    Vector<UANSICHAR> m_tBuffer;

    /**
    ************************
    * Data buffer for floatRGBA16 textures
    ************************
    */
    Vector<HALF> m_tBufferF;
    bool m_hrd;
    String m_fileName;
    amTexType::E m_tType;
    amFormats::E m_format;
    uint32 m_height;
    uint32 m_width;
  };
}
