#pragma once
#include "amDXPreReqs.h"
#include <amSwapChain.h>

namespace amEngineSDK {
  class amDXDevice;

  class amDXSwapChain : public amSwapChain
  {
  public:
    amDXSwapChain();
    amDXSwapChain(int32 _height, int32 _width, HWND _target);
    ~amDXSwapChain();
   
    ID3D11RenderTargetView* 
    getRTVFromBuffer(amDXDevice* pDevice, uint32 numBuffer = 0);

    virtual void 
    Present() override;

    DXGI_SWAP_CHAIN_DESC m_scd;
    IDXGISwapChain* m_pSC;
  };
}
