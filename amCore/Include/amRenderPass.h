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
    amRenderPass();
    ~amRenderPass();

    void 
    render(Vector<amResource*> _renderObjs);

    amVertexShader* m_pVS;
    amPixelShader* m_pPS;
    Vector<amResource*> m_vecPassModels;
    Vector<amConstantBuffer*> m_vecPassConstBuffers;
    Vector<amRenderTarget*> m_vecRenderTargets;
  };
}


