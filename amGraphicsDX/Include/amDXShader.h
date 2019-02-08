#pragma once
#include "amDXPreReqs.h"

namespace amEngineSDK {
  class amDXDeviceContext;

  class amDXShader
  {
  public:
    amDXShader();
    ~amDXShader();

    HRESULT CompileShaderFromFile(const char* szFileName,
                                              LPCSTR szEntryPoint,
                                              LPCSTR szShaderModel,
                                              ID3DBlob ** ppBlobOut);

    virtual void
    setShader(amDXDeviceContext* pDC) = 0;

    ID3DBlob* m_pblob;
    std::string m_shaderName;
  };
}

