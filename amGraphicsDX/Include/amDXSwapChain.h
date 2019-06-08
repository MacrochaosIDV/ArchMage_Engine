#pragma once
#include "amDXPreReqs.h"

namespace amEngineSDK {
  class amDXDevice;

  class amDXSwapChain
  {
  public:
    amDXSwapChain();
    amDXSwapChain(int32 _height, int32 _width, HWND _target);
    ~amDXSwapChain();
   
    ID3D11RenderTargetView* 
    getRTVFromBuffer(amDXDevice* pDevice, uint32 numBuffer = 0);

    DXGI_SWAP_CHAIN_DESC m_scd;
    IDXGISwapChain* m_pSC;
  };
}
