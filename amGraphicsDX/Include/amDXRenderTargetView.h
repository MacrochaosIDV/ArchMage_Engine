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
    D3D11_RENDER_TARGET_VIEW_DESC m_desc;
  };
}
