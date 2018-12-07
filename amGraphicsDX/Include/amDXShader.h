#pragma once
#include "amDXPreReqs.h"
namespace amEngineSDK {
  class amDXShader
  {
  public:
    amDXShader();
    ~amDXShader();

    HRESULT CompileShaderFromFile(const char* szFileName,
                                              LPCSTR szEntryPoint,
                                              LPCSTR szShaderModel,
                                              ID3DBlob ** ppBlobOut);
    ID3DBlob* m_pblob;
  };
}

