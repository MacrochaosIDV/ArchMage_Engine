#pragma once
#include "amPrerequisitesCore.h"

namespace amEngineSDK {
  class amIndexBuffer;
  class amVertexBuffer;
  class amConstantBuffer;
  class amPixelShader;
  class amVertexShader;

  class AM_CORE_EXPORT amDevice
  {
  public:
    amDevice();
    ~amDevice();

    virtual amIndexBuffer*
      createIndexBuffer(amIndexBuffer* _IB);

    virtual amVertexBuffer*
      createVertexBuffer(amVertexBuffer* _VB);

    virtual amConstantBuffer*
      createConstBuffer(amConstantBuffer* _CB);

    virtual amPixelShader*
      createPixelShader(amPixelShader* _PS);

    virtual amVertexShader*
      createVertexShader(amVertexShader* _VS);
  };
}
