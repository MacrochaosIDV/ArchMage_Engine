#include "amDXVertexShader.h"
#pragma comment(lib,"d3dcompiler.lib")
#include <fstream>
#include <iostream>
#include "amDevice.h"
#include "amDeviceContext.h"

namespace amEngineSDK {

  amDXVertexShader::amDXVertexShader(const String _pathName,
                                     const String _shaderName,
                                     const String _entryPoint,
                                     const String _shaderModel) {
    m_pathFileName = _pathName;
    m_shaderName = _shaderName;
    m_entryPoint = _entryPoint;
    m_shaderModel = _shaderModel;
    m_vs = nullptr;
  }

  amDXVertexShader::~amDXVertexShader() {
    if (m_vs) {
      m_vs->Release();
      m_vs = nullptr;
    }
  }

  void
  amDXVertexShader::createVertexShader(amDevice* pDevice) {
    pDevice->createVertexShader(this);
  }

  int32 
  amDXVertexShader::CompileShaderFromFile(const String szFileName, const ANSICHAR * szEntryPoint, const ANSICHAR * szShaderModel, void ** ppBlobOut) {
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
    shdr.seekg(std::ios::beg);

    std::vector<char> fileBuffer;
    fileBuffer.resize(fileSize);
    shdr.read(&fileBuffer[0], fileSize);

    ID3DBlob* pErrorBlob;
    //ID3DBlob* pOutBlob;
    hr = D3DCompile(&fileBuffer[0], fileSize, szFileName.c_str(), nullptr, NULL, szEntryPoint, szShaderModel, dwShaderFlags,
                    0, reinterpret_cast<ID3DBlob**>(ppBlobOut), &pErrorBlob);
    if (FAILED(hr)) {
      if (pErrorBlob != NULL) {
        String _error = reinterpret_cast<ANSICHAR*>(pErrorBlob->GetBufferPointer());
        std::cout << _error;
      }
      //OutputDebugStringA((char*)pErrorBlob->GetBufferPointer());
      if (pErrorBlob) pErrorBlob->Release();
      return hr;
    }
    if (pErrorBlob)
      pErrorBlob->Release();

    //uint32 blobSize = reinterpret_cast<ID3DBlob*>(ppBlobOut)->GetBufferSize();
    //void* pBuffer = reinterpret_cast<ID3DBlob*>(ppBlobOut)->GetBufferPointer();
    //ppBlobOut->m_buffer.resize(blobSize);
    //memcpy(&ppBlobOut->m_buffer[0], pOutBlob->GetBufferPointer(), blobSize);
    return S_OK;
  }

  void
  amDXVertexShader::setShader(amDeviceContext * pDC) {
    //pDC->m_pDC->VSSetShader(m_vs, nullptr, 0);
    pDC->setVertexShader(this);
  }

  void 
  amDXVertexShader::createVS(const String pathFileName, amDevice* pDevice) {
    CompileShaderFromFile(pathFileName, "VS", "vs_5_0", reinterpret_cast<void**>(&m_blob));
    createVertexShader(pDevice);
  }

  void amDXVertexShader::Compile() {
    CompileShaderFromFile(m_pathFileName,
                          m_entryPoint.c_str(),
                          m_shaderModel.c_str(),
                          reinterpret_cast<void**>(&m_blob));
  }
}
