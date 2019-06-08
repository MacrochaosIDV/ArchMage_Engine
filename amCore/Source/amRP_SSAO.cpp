#include "amRP_SSAO.h"

namespace amEngineSDK {
  amRP_SSAO::amRP_SSAO(amRenderPassStage::E _pass, String _strPS, String _strVS, String _name) {
    m_renderPassStage = _pass;
    m_strPS = _strPS;
    m_strVS = _strVS;
    m_passName = _name;
  }

  amRP_SSAO::~amRP_SSAO() {}

}
