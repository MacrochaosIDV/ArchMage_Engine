#pragma once
#include "amDXPreReqs.h"

namespace amEngineSDK {
  class amDXSwapChain
  {
  public:
    amDXSwapChain();
    ~amDXSwapChain();

    DXGI_SWAP_CHAIN_DESC m_scd;
    IDXGISwapChain* m_pSwapChain;
  };
}


