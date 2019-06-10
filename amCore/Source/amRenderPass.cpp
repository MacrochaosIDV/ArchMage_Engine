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
    if(m_pVS)
      m_pVS->Compile();
    if(m_pPS)
      m_pPS->Compile();
    return ((m_pVS) ? 0 : 1 + ((m_pPS) ? 0 : 10));
  }

  void amRenderPass::setShaders(String _strPS, String _strVS) {
    m_strPS = _strPS;
    m_strVS = _strVS;
  }

  void amRenderPass::setShaderPointers(amVertexShader * _pVS, amPixelShader * _pPS) {
    m_pVS = _pVS;
    m_pPS = _pPS;
  }

  void 
  amRenderPass::setRenderTargetsInputs(Vector<amRenderTarget*> _vecRenderTargets) {
    m_vecRenderTargets = _vecRenderTargets;
  }



}
