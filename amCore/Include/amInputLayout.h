#pragma once
#include "amPrerequisitesCore.h"

namespace amEngineSDK {
  class AM_CORE_EXPORT amInputLayout
  {
  public:
    amInputLayout();
    ~amInputLayout();

    virtual void 
    init();

    amShaderInputLayout::E m_shaderLayout;
  };
}
