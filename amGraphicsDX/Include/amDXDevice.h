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
#include <amDevice.h>
#include "amDXVertexBuffer.h"
#include "amDXIndexBuffer.h"
#include "amDXConstantBuffer.h"

//class amDXIndexBuffer;
//class amDXVertexBuffer;

namespace amEngineSDK {
  class amVertexShader;
  class amPixelShader;

  class amDXDevice : public amDevice
  {
  public:
    amDXDevice();
    ~amDXDevice();

    int32 
    CreateConstantBuffer(amDXConstantBuffer* pCB);

    int32 
    CreateVertexBufferDefault(amDXVertexBuffer* pVB);

    int32 
    CreateIndexBufferDefault(amDXIndexBuffer* pIB);

    virtual amVertexShader*
    createVertexShader(amVertexShader* _VS) override;

    virtual amPixelShader*
    createPixelShader(amPixelShader* _PS) override;

    ID3D11Device* m_pDV;
    amDXVertexBuffer m_VB; // temp buffer for testing
    amDXIndexBuffer m_IB; // temp buffer for testing
  };
}
