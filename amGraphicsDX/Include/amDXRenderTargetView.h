#pragma once
#include "amDXPreReqs.h"
namespace amEngineSDK {
  class amDXRenderTargetView
  {
  public:
    amDXRenderTargetView();
    ~amDXRenderTargetView();

    ID3D10RenderTargetView* mp_RenderTargetView;
  };
}


