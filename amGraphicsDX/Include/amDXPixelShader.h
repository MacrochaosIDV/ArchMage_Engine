#pragma once
/**
***********************************************
 * @file amDXPixelShader.h
 * @date 2019/06/01
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief Implements a pixel shader for D3DX11
 *
 * @note createPS(...) uses PS for entry point and shader model 5.0 in the shader file
***********************************************
*/
#include "amDXPreReqs.h"
#include "amPixelShader.h"
#include <d3d11.h>

namespace amEngineSDK {
  class amDevice;
  class amDXDevice;
  class amDXDeviceContext;
  class amDeviceContext;

  class amDXPixelShader : public amPixelShader
  {
   public:
    amDXPixelShader();
    ~amDXPixelShader();

  
    //TODO: Change DXDevice to Device and make createPS into virtual from Core::PS
    //TODO: change inheritance from amDXShader to amPS
   private:
    void
    createPixelShader(amDevice* pDevice);

   public:

   virtual int32
   CompileShaderFromFile(const String szFileName,
                         const ANSICHAR* szEntryPoint,
                         const ANSICHAR* szShaderModel,
                         void** ppBlobOut) override;

    virtual void
    setShader(amDeviceContext* pDC) override;

    virtual void
    createPS(String pathFileName, amDevice* pDevice) override;

    ID3D11PixelShader* m_ps;
    ID3DBlob* m_blob;
  };
}
