#pragma once
#include "amDXPreReqs.h"
#include "amComputeShader.h"

namespace amEngineSDK {
  class amDXComputeShader : public amComputeShader
  {
  public:
    amDXComputeShader() = default;
    amDXComputeShader(const String _pathName,
                      const String _shaderName,
                      const String _entryPoint,
                      const String _shaderModel);
    ~amDXComputeShader();

    virtual int32 CompileComputeShader(_In_ const WString& srcFile,
                                       _In_ const ANSICHAR* entryPoint,
                                       _In_ amDevice* device,
                                       _Outptr_ void** blob) override;
    
    virtual void 
    Compile() override;

    void 
    Dispatch();

    ID3D11ComputeShader* m_cs;
    ID3DBlob* m_blob;
  };
}
