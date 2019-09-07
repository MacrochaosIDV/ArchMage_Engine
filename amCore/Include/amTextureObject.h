#pragma once
#include "amPrerequisitesCore.h"
#include "amResource.h"

namespace amEngineSDK {
  class amTexture;
  class amShaderResourceView;

  class AM_CORE_EXPORT amTextureObject : public amResource
  {
  public:
    amTextureObject();
    ~amTextureObject();

    amTextureObject& 
    operator=(const amTextureObject* _texObj);

    virtual void 
    setapiTex(void* _tex);

    amTexture* m_tex;
    amShaderResourceView* m_srv;
    void* m_pApiTex;
  };
}


