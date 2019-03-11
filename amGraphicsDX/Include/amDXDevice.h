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
#include "amDXIndexBuffer.h"
#include "amDXConstantBuffer.h"

//class amDXIndexBuffer;
//class amDXVertexBuffer;

namespace amEngineSDK {
  class amDXDevice
  {
  public:
    amDXDevice();
    ~amDXDevice();

    ID3D11Device* m_pDV;
    amDXVertexBuffer m_VB; // temp buffer for testing
    amDXIndexBuffer m_IB; // temp buffer for testing
    int32 CreateConstantBuffer(amDXConstantBuffer* pCB);
    int32 CreateVertexBufferDefault(amDXVertexBuffer* pVB);
    int32 CreateIndexBufferDefault(amDXIndexBuffer* pIB);
  };
}


