#pragma once
#include "amPrerequisitesCore.h"

namespace amEngineSDK {
  class amPixelShader;
  class amVertexShader;
  class amModel;
  class amConstantBuffer;
  class amRenderTarget;
  class amResource;

  namespace amRenderPassStage {
    enum E
    {
      kG_BUFFER = 0,
      kSSAO,
      kDOWNSCALE_BLOOM,
      kBLUR_H,
      kBLUR_V,
      kLUMINANCE,
      kFINAL,
      COUNT
    };
  }

  class AM_CORE_EXPORT amRenderPass
  {
  public:
    amRenderPass() = default;
    amRenderPass(amRenderPassStage::E _pass, String _strPS, String _strVS, String _name);
    ~amRenderPass();

    void 
    render(Vector<amResource*> _renderObjs);

    int32 
    compileShaders();


    bool m_computeShading;
    String m_passName;
    String m_strPS;
    String m_strVS;
    amRenderPassStage::E m_renderPassStage;
    amVertexShader* m_pVS;
    amPixelShader* m_pPS;
    Vector<amResource*> m_vecPassModels;
    Vector<amConstantBuffer*> m_vecPassConstBuffers;
    Vector<amRenderTarget*> m_vecRenderTargets;
  };
}
