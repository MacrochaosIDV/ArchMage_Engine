#pragma once
#include "amPrerequisitesCore.h"
#include "amShader.h"

namespace amEngineSDK {
  class amDevice;

  class AM_CORE_EXPORT amComputeShader : public amShader
  {
  public:
    amComputeShader() = default;
    amComputeShader(const String _pathName,
                    const String _shaderName,
                    const String _entryPoint,
                    const String _shaderModel);
    ~amComputeShader();

    virtual int32 CompileComputeShader(_In_ const WString& srcFile,
                                       _In_ const ANSICHAR* entryPoint,
                                       _In_ amDevice* device,
                                       _Outptr_ void** blob);
    
  };
}
