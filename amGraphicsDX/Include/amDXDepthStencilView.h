#pragma once
#include "amDXPreReqs.h"
#include <amDepthStencilView.h>

namespace amEngineSDK {
  class amDXDepthStencilView : public amDepthStencilView
  {
  public:
    amDXDepthStencilView();
    ~amDXDepthStencilView();

    ID3D11DepthStencilView* m_pDSV;
    D3D11_TEXTURE2D_DESC m_desc;
  };
}
