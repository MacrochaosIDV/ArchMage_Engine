#pragma once
#include "amDXPreReqs.h"
#include <amDepthStencilView.h>

namespace amEngineSDK {
  class amDXDepthStencilView : public amDepthStencilView
  {
  public:
    amDXDepthStencilView();
    amDXDepthStencilView(const uint32 _height,
                         const uint32 _width,
                         const float _scale = 1.0f);
    ~amDXDepthStencilView();

    ID3D11DepthStencilView* m_pDSV;
    D3D11_DEPTH_STENCIL_VIEW_DESC m_desc;
  };
}
