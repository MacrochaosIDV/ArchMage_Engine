#include "amDXShader.h"
#pragma comment(lib,"d3dcompiler.lib")
#include <fstream>
#include <iostream>
#include <vector>

namespace amEngineSDK {
  amDXShader::amDXShader() {}


  amDXShader::~amDXShader() {}

  HRESULT amDXShader::CompileShaderFromFile(const char* szFileName,
                                                 LPCSTR szEntryPoint,
                                                 LPCSTR szShaderModel,
                                                 ID3DBlob ** ppBlobOut) {
    HRESULT hr = S_OK;

    DWORD dwShaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;
#if defined( DEBUG ) || defined( _DEBUG )
    // Set the D3DCOMPILE_DEBUG flag to embed debug information in the shaders.
    // Setting this flag improves the shader debugging experience, but still allows 
    // the shaders to be optimized and to run exactly the way they will run in 
    // the release configuration of this program.
    dwShaderFlags |= D3DCOMPILE_DEBUG;
#endif

    std::ifstream shdr(szFileName, std::ios::in | std::ios::binary | std::ios::ate);
    if (!shdr.is_open()) {
      return -1;
    }
    SIZE_T fileSize = shdr.tellg();
    std::vector<char> fileBuffer;
    fileBuffer.resize(fileSize);
    shdr.read(&fileBuffer[0], fileSize);

    ID3DBlob* pErrorBlob;
    hr = D3DCompile(&fileBuffer[0], fileSize, szFileName, nullptr, NULL, szEntryPoint, szShaderModel, dwShaderFlags,
                    0, &m_pblob, &pErrorBlob);
    if (FAILED(hr)) {
      if (pErrorBlob != NULL)
        OutputDebugStringA((char*)pErrorBlob->GetBufferPointer());
      if (pErrorBlob) pErrorBlob->Release();
      return hr;
    }
    if (pErrorBlob) pErrorBlob->Release();

    return S_OK;
  }

  
}

