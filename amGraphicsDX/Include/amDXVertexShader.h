#pragma once
#include "amDXPreReqs.h"
#include "amVertexShader.h"

namespace amEngineSDK {
  class amDevice;
  class amDeviceContext;

  class amDXVertexShader : public amVertexShader
  {
  public:
    amDXVertexShader() = default;
    amDXVertexShader(const String _pathName,
                     const String _shaderName,
                     const String _entryPoint,
                     const String _shaderModel);
    ~amDXVertexShader();

  private:
    void
    createVertexShader(amDevice* pDevice);

  public:

    virtual int32
    CompileShaderFromFile(const String szFileName,
                          const ANSICHAR* szEntryPoint,
                          const ANSICHAR* szShaderModel,
                          void** ppBlobOut) override;

    virtual void
    setShader(amDeviceContext* pDC) override;

    void 
    createVS(const String pathFileName, amDevice* pDevice);

    virtual void
    Compile() override;

    ID3D11VertexShader* m_vs;
    ID3DBlob* m_blob;
  };
}
