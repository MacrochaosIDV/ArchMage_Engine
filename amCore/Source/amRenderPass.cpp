#include "amRenderPass.h"
#include "amVertexShader.h"
#include "amPixelShader.h"
#include "amDeviceContext.h"
#include "amDevice.h"
#include "amGraphicsAPI.h"

//using std::move;

namespace amEngineSDK {

  amRenderPass::amRenderPass(const uint32 _pass,
                             const String& _strPS,
                             const String& _strVS,
                             const String& _name) {
    m_renderPassStage = static_cast<amRenderPassStage::E>(_pass);
    m_strPS = _strPS;
    m_strVS = _strVS;
    m_passName = _name;
  }

  amRenderPass::~amRenderPass() {
  
  }

  void 
  amRenderPass::render(Vector<amResource*>* _renderObjs) {
    _renderObjs;
  }

  int32 
  amRenderPass::compileShaders() {
    if(m_pVS)
      m_pVS->Compile();
    if(m_pPS)
      m_pPS->Compile();
    return ((m_pVS) ? 0 : 1 + ((m_pPS) ? 0 : 10));
  }

  void 
  amRenderPass::setShaders(String _strPS, String _strVS) {
    m_strPS = _strPS;
    m_strVS = _strVS;
  }

  void 
  amRenderPass::setShaderPointers(amVertexShader* _pVS, amPixelShader* _pPS) {
    m_pVS = _pVS;
    m_pPS = _pPS;
  }

  void 
  amRenderPass::setRenderTargetsInputs(Vector<amRenderTarget*> _vecRenderTargets) {
    m_vecRenderTargets = _vecRenderTargets;
  }

  void 
  amRenderPass::setUp(amDeviceContext* _dc) {
    _dc;
  }

  void 
  amRenderPass::addModels(Vector<amResource*>* _mdls) {
    m_vecPassModels.insert(m_vecPassModels.end(), _mdls->begin(), _mdls->end());
  }

  void 
  amRenderPass::clearPassGeom() {
    m_vecPassModels.clear();
  }

  void 
  amRenderPass::createShaders(amDevice* _dv) {
    _dv->createVertexShader(m_pVS);
    _dv->createPixelShader(m_pPS);
  }

  void 
  amRenderPass::init(amDevice * _dv, amGraphicsAPI* _api) {
    _api->createPassShaders(&m_pPS, &m_pVS);
    m_pPS->m_pathFileName = m_strPS;
    m_pPS->m_entryPoint = Move("PS");
    m_pPS->m_shaderModel = Move("ps_5_0");
    m_pVS->m_pathFileName = m_strVS;
    m_pVS->m_entryPoint = Move("VS");
    m_pVS->m_shaderModel = Move("vs_5_0");
    compileShaders();
    createShaders(_dv);
  }
}
