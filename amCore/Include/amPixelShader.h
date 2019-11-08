#pragma once
#include "amPrerequisitesCore.h"
#include "amShader.h"

namespace amEngineSDK {
  class amDevice;
  class amDeviceContext;

  class AM_CORE_EXPORT amPixelShader : public amShader
  {
  public:
    amPixelShader() = default;
    amPixelShader(const String _pathName,
                  const String _shaderName,
                  const String _entryPoint,
                  const String _shaderModel);
    ~amPixelShader();

    virtual void
    createPS(String pathFileName, amDevice* pDevice);

    /**
    ************************
    *  @brief Gets the Device context to set this as the pixelShader
    ************************
    */
    virtual void
    setShader(amDeviceContext* pDC);
  };
}
