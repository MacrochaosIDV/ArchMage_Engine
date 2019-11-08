#pragma once
#include "amDXPreReqs.h"
#include "amShader.h"

namespace amEngineSDK {
  class amDXDeviceContext;

  class amDXShader : public amShader
  {
  public:
    amDXShader() = default;
    amDXShader(const String _pathName,
               const String _shaderName,
               const String _entryPoint,
               const String _shaderModel);
    ~amDXShader();

    virtual int32 
    CompileShaderFromFile(const char* szFileName,
                          LPCSTR szEntryPoint,
                          LPCSTR szShaderModel,
                          ID3DBlob ** ppBlobOut);

    virtual void
    setShader(amDXDeviceContext* pDC) = 0;

    ID3DBlob* m_pblob;
    String m_pathFileName;
  };
}
