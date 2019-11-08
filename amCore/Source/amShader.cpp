#include "amShader.h"

namespace amEngineSDK {

  amShader::amShader(const String _pathName,
                     const String _shaderName,
                     const String _entryPoint,
                     const String _shaderModel) {
    m_pathFileName = _pathName;
    m_shaderName = _shaderName;
    m_entryPoint = _entryPoint;
    m_shaderModel = _shaderModel;
  }

  amShader::~amShader() {}

  int32 
  amShader::CompileShaderFromFile(const String szFileName, 
                                  const ANSICHAR* szEntryPoint, 
                                  const ANSICHAR * szShaderModel, 
                                  void ** ppBlobOut) {
    szFileName;
    szEntryPoint;
    szShaderModel;
    ppBlobOut;
    return int32();
  }

  void 
  amShader::setShader(amDeviceContext * pDC) {
    pDC;
  }

  void 
  amShader::Compile() {}

}
