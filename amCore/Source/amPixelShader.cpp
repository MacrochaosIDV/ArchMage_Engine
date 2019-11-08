#include "amPixelShader.h"

namespace amEngineSDK {

  amPixelShader::amPixelShader(const String _pathName,
                               const String _shaderName,
                               const String _entryPoint,
                               const String _shaderModel) {
    m_pathFileName = _pathName;
    m_shaderName = _shaderName;
    m_entryPoint = _entryPoint;
    m_shaderModel = _shaderModel;
  }

  amPixelShader::~amPixelShader() {}

  void 
  amPixelShader::createPS(String pathFileName, amDevice * pDevice) {
    pathFileName;
    pDevice;
  }

  void 
  amPixelShader::setShader(amDeviceContext* pDC) {
    pDC;
  }

}
