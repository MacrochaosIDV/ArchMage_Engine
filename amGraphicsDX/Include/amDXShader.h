#pragma once
#include "amDXPreReqs.h"

namespace amEngineSDK {
  class amDXDeviceContext;

  class amDXShader
  {
  public:
    amDXShader();
    ~amDXShader();

    virtual int32 
    CompileShaderFromFile(const char* szFileName,
                          LPCSTR szEntryPoint,
                          LPCSTR szShaderModel,
                          ID3DBlob ** ppBlobOut);

    virtual void
    setShader(amDXDeviceContext* pDC) = 0;

    ID3DBlob* m_pblob;
    String m_shaderName;
  };
}
