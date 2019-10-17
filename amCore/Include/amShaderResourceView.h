#pragma once
#include "amPrerequisitesCore.h"
#include "amView.h"

namespace amEngineSDK {
  class amTexture;
  class amDevice;

  class AM_CORE_EXPORT amShaderResourceView : public amView
  {
  public:
    amShaderResourceView();
    ~amShaderResourceView();

  private:

  public:
    virtual void 
    createSRV(amTexture * _tex, amDevice * _device);

    virtual void 
    resize(const uint32 _height, const uint32 _width) override;

    amTexture* m_texResource;
  };
}
