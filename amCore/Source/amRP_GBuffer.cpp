#include "amRP_GBuffer.h"
#include "amDeviceContext.h"
#include "amShaderResourceView.h"

namespace amEngineSDK {
  amRP_GBuffer::amRP_GBuffer() {}

  amRP_GBuffer::amRP_GBuffer(const uint32 _pass, 
                             const String& _strPS, 
                             const String& _strVS, 
                             const String& _name) {
    m_renderPassStage = _pass;
    m_strPS = _strPS;
    m_strVS = _strVS;
    m_passName = _name;
  }

  amRP_GBuffer::~amRP_GBuffer() {}

  void amRP_GBuffer::setUp(amDeviceContext * _dc) {
    _dc->setPixelShader(m_pPS);
    _dc->setVertexShader(m_pVS);

    _dc->setPSResources(5, 1, m_brdfLUT);
    _dc->setPSResources(6, 1, m_irradiance);
    _dc->setPSResources(7, 1, m_specularIBL);
  }

  void 
  amRP_GBuffer::setTextures(amShaderResourceView* _brdfLUT,
                            amShaderResourceView* _irradiance,
                            amShaderResourceView* _specularIBL,
                            amConstantBuffer* _CB_Data) {
    m_brdfLUT = _brdfLUT;
    m_irradiance = _irradiance;
    m_specularIBL = _specularIBL;
    m_vsConstBuffer = _CB_Data;
  }
}
