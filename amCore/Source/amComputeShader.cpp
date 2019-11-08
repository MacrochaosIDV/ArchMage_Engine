#include "amComputeShader.h"

namespace amEngineSDK {

  amComputeShader::amComputeShader(const String _pathName,
                                   const String _shaderName,
                                   const String _entryPoint,
                                   const String _shaderModel) {
    m_pathFileName = _pathName;
    m_shaderName = _shaderName;
    m_entryPoint = _entryPoint;
    m_shaderModel = _shaderModel;
  }

  amComputeShader::~amComputeShader() {}

  int32 
  amComputeShader::CompileComputeShader(const WString& srcFile, const ANSICHAR * entryPoint, amDevice * device, void ** blob) {
    srcFile;
    entryPoint;
    device;
    blob;
    return 0;
  }
}
