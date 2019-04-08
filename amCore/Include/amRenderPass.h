#pragma once
#include "amPrerequisitesCore.h"


namespace amEngineSDK {
  class amPixelShader;
  class amVertexShader;
  class amModel;
  class amConstantBuffer;
  class amRenderTarget;
  class amResource;

  class amRenderPass
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


