#include "amVertexShader.h"

namespace amEngineSDK {

  amVertexShader::amVertexShader(const String _pathName,
                                 const String _shaderName,
                                 const String _entryPoint,
                                 const String _shaderModel) {
    m_pathFileName = _pathName;
    m_shaderName = _shaderName;
    m_entryPoint = _entryPoint;
    m_shaderModel = _shaderModel;
  }

  amVertexShader::~amVertexShader() {}
}
