#include "amDXComputeShader.h"
#include "amDXDevice.h"

namespace amEngineSDK {
  amDXComputeShader::amDXComputeShader() {}

  amDXComputeShader::~amDXComputeShader() {}
  int32 amDXComputeShader::CompileComputeShader(const WString & srcFile,
                                                const ANSICHAR * entryPoint,
                                                amDevice * device,
                                                void ** blob) {
    if (!entryPoint || !device || !blob)
      return E_INVALIDARG;

    *blob = nullptr;

    UINT flags = D3DCOMPILE_ENABLE_STRICTNESS;
#if defined( DEBUG ) || defined( _DEBUG )
    flags |= D3DCOMPILE_DEBUG;
#endif

    // We generally prefer to use the higher CS shader profile when possible as CS 5.0 is better performance on 11-class hardware
    LPCSTR profile = (reinterpret_cast<amDXDevice*>(device)->m_pDV->GetFeatureLevel() >= D3D_FEATURE_LEVEL_11_0) ? "cs_5_0" : "cs_4_0";

    const D3D_SHADER_MACRO defines[] =
    {
        "EXAMPLE_DEFINE", "1",
        NULL, NULL
    };

    ID3DBlob* shaderBlob = nullptr;
    ID3DBlob* errorBlob = nullptr;
    HRESULT hr = D3DCompileFromFile(srcFile.c_str(), defines, D3D_COMPILE_STANDARD_FILE_INCLUDE,
                                    entryPoint, profile,
                                    flags, 0, &shaderBlob, &errorBlob);
    if (FAILED(hr)) {
      if (errorBlob) {
        OutputDebugStringA((char*)errorBlob->GetBufferPointer());
        errorBlob->Release();
      }

      if (shaderBlob)
        shaderBlob->Release();

      return hr;
    }

    *blob = shaderBlob;

    return hr;
  }

  void amDXComputeShader::Compile() {

  }

  void amDXComputeShader::Dispatch() {
    
  }

}
