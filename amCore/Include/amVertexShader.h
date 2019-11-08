#pragma once
#include "amPrerequisitesCore.h"
#include "amShader.h"

namespace amEngineSDK {
  class AM_CORE_EXPORT amVertexShader : public amShader
  {
  public:
    amVertexShader() = default;
    amVertexShader(const String _pathName,
                   const String _shaderName,
                   const String _entryPoint,
                   const String _shaderModel);
    ~amVertexShader();
  };
}
