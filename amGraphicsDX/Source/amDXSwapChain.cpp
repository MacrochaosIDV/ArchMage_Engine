#include "amDXSwapChain.h"
#include "amDXDevice.h"

namespace amEngineSDK {
  amDXSwapChain::amDXSwapChain() : m_pSC(nullptr) {}

  amDXSwapChain::~amDXSwapChain() {}
  
  amDXSwapChain::amDXSwapChain(int32 _height, int32 _width, HWND _target) {
    m_scd.BufferCount = 1;
    m_scd.BufferDesc.Width = _height;
    m_scd.BufferDesc.Height = _width;
    m_scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    m_scd.BufferDesc.RefreshRate.Numerator = 60;
    m_scd.BufferDesc.RefreshRate.Denominator = 1;
    m_scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    m_scd.OutputWindow = _target;
    m_scd.SampleDesc.Count = 1;
    m_scd.SampleDesc.Quality = 0;

    //Falta crearla
  }
  
  ID3D11RenderTargetView*
  amDXSwapChain::getRTVFromBuffer(amDXDevice* pDevice, uint32 numBuffer) {
    if (!m_pSC || !pDevice || !pDevice->m_pDV) {
      //Si el swap chain no se ha creado todavía
      return nullptr;
    }

    ID3D11Texture2D* pBuffer = nullptr;
    m_pSC->GetBuffer(numBuffer, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&pBuffer));

    ID3D11RenderTargetView* pRTV = nullptr;
    if (FAILED(pDevice->m_pDV->CreateRenderTargetView(pBuffer, nullptr, &pRTV))) {
      //Error!!!
    }

    pBuffer->Release();
    pBuffer = nullptr;

    return pRTV;
  }

}
