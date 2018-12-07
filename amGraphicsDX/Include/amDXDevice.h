/**
***********************************************
 * @file amDXDevice.h
 * @date 2018/10/31
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief 
 *
 * TODO: long description
 *
 * @note
***********************************************
*/
#pragma once
#include "amDXPreReqs.h"
#include "amDXVertexBuffer.h"

namespace amEngineSDK {
  class amDXDevice
  {
  public:
    amDXDevice();
    ~amDXDevice();

    ID3D11Device* m_pDV;
    amDXVertexBuffer m_VB;
    int32 CreateVertexBuffer();
  };
}


