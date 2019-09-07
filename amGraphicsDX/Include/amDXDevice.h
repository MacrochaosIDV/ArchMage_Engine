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

namespace amEngineSDK {
  class amVertexShader;
  class amPixelShader;
  class amComputeShader;
  class amShaderResourceView;
  ;

  class amDXDevice : public amDevice
  {
  public:
    amDXDevice();
    ~amDXDevice();

    virtual amConstantBuffer*
    createConstBuffer(amConstantBuffer* _pCB,
                      amResourceBindFlags::E _RBF = 
                        amResourceBindFlags::E::kBINDF_CONSTANT_BUFFER) override;

    virtual amVertexBuffer*
    createVertexBuffer(amVertexBuffer* _pVB,
                       amResourceBindFlags::E _RBF = 
                         amResourceBindFlags::E::kBINDF_VERTEX_BUFFER) override;

    virtual amIndexBuffer*
    createIndexBuffer(amIndexBuffer* _pIB,
                      amResourceBindFlags::E _RBF = 
                        amResourceBindFlags::E::kBINDF_INDEX_BUFFER) override;

    virtual amVertexShader*
    createVertexShader(amVertexShader* _pVS) override;

    virtual amPixelShader*
    createPixelShader(amPixelShader* _pPS) override;

    virtual amComputeShader* 
    createComputeShader(amComputeShader* _pCS) override;

    virtual amShaderResourceView* 
    createShaderResourceView(amShaderResourceView* _SRV,
                             const int32 amSRV_type,
                             const int32 _format,
                             const int32 _rbf) override;

     

    ID3D11Device* m_pDV;
    amDXVertexBuffer* m_VB; // temp buffer for testing
    amDXIndexBuffer* m_IB; // temp buffer for testing
  };
}
