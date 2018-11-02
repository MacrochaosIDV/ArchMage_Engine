#pragma once
#include "amDXPreReqs.h"
#include <amPrerequisitesUtilities.h>
namespace amEngineSDK {
  class amDXInputLayout
  {
  public:
    amDXInputLayout();
    ~amDXInputLayout();

    ID3D11InputLayout* m_pVertexLayout;
    Vector<D3D11_INPUT_ELEMENT_DESC> m_layout; 
    
    /*=
    {
      {"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
    {"NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0}    };*/
    //uint32 numElements = sizeof(layout) / sizeof(layout[0]);
  };
}


