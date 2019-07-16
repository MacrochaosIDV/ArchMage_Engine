#pragma once
#include "amPrerequisitesCore.h"

namespace amEngineSDK {
  class amResource;
  class amDevice;
  class amShaderResourceView;

  class AM_CORE_EXPORT amResourceManager
  {
  public:
    amResourceManager();
    ~amResourceManager();

    amResource* 
    CreateRegisterModel(const String& pathName, amDevice* _dv);

    amResource*
    CreateModel(const String& pathName);

    amResource*
    CreateTexture(const String& pathName);

    void
    RegisterTexture(amResource* _res, amDevice* _dv, amFormats::E _format);


    Vector<amResource*> m_vecResources;
  };
}
