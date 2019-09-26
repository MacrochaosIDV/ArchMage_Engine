#pragma once
#include "amPrerequisitesCore.h"
#include "amResource.h"

namespace amEngineSDK {
  class amTexture;
  class amShaderResourceView;

  class AM_CORE_EXPORT amTextureObject : public amResource
  {
  public:
    /**
    ************************
    *  @long Default constructor will create its amTaxture pointer but not the srv pointer
    *  that one must be created by the api while creating its api srv
    ************************
    */
    amTextureObject();
    ~amTextureObject();

    amTextureObject& 
    operator=(const amTextureObject* _texObj);

    virtual void 
    setapiTex(void* _tex);

    void 
    resize(const uint32 _height, const uint32 _width);

    amTexture* m_tex;
    amShaderResourceView* m_srv;
    void* m_pApiTex;
  };
}


