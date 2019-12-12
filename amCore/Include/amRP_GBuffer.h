#pragma once
#include "amPrerequisitesCore.h"
#include "amRenderPass.h"

namespace amEngineSDK {
  class amShaderResourceView;

  class AM_CORE_EXPORT amRP_GBuffer : public amRenderPass
  {
  public:
    amRP_GBuffer();
    amRP_GBuffer(const uint32 _pass,
                 const String& _strPS,
                 const String& _strVS,
                 const String& _name);
    ~amRP_GBuffer();

    virtual void
    setUp(amDeviceContext* _dc) override;

    void setTextures(amShaderResourceView* _brdfLUT,
                     amShaderResourceView* _irradiance,
                     amShaderResourceView* _specularIBL,
                     amConstantBuffer* _CB_Data);

    amShaderResourceView* m_brdfLUT;
    amShaderResourceView* m_irradiance;
    amShaderResourceView* m_specularIBL;
  };
}