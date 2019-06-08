#include "amRenderPass.h"
#include "amVertexShader.h"
#include "amPixelShader.h"

namespace amEngineSDK {

  //TODO:make sure the shaders initialize during init content in graphics api
  amRenderPass::amRenderPass(amRenderPassStage::E _pass, String _strPS, String _strVS, String _name) {
    m_renderPassStage = _pass;
    m_strPS = _strPS;
    m_strVS = _strVS;
    m_passName = _name;
  }

  amRenderPass::~amRenderPass() {
  
  }

  void 
  amRenderPass::render(Vector<amResource*>) {
  
  }

  int32 
  amRenderPass::compileShaders() {
    m_pVS = new amVertexShader();
    m_pPS = new amPixelShader();
    return(m_pVS && m_pPS) ? true : false;
  }

}
