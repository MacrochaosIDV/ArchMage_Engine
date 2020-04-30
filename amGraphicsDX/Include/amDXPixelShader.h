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
    amDXPixelShader() = default;
    amDXPixelShader(const String _pathName,
                    const String _shaderName,
                    const String _entryPoint,
                    const String _shaderModel);
    ~amDXPixelShader();

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

    virtual void 
    Compile() override;

    ID3D11PixelShader* m_ps = nullptr;
    ID3DBlob* m_blob = nullptr;;
  };
}
