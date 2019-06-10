#pragma once
#include "amDXPreReqs.h"
#include "amRenderTargetView.h"

namespace amEngineSDK {
  class amDXRenderTargetView : public amRenderTargetView
  {
  public:
    amDXRenderTargetView();
    ~amDXRenderTargetView();

    ID3D11RenderTargetView* m_pRTV;
  };
}
