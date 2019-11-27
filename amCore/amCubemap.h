#pragma once
#include "amPrerequisitesCore.h"
#include "amResource.h"

namespace amEngineSDK {
  class amShaderResourceView;

  class amCubemap : public amResource
  {
  public:
    amCubemap();
    ~amCubemap();

    union
    {
      struct 
      {
        amShaderResourceView* m_right;
        amShaderResourceView* m_left;
        amShaderResourceView* m_top;
        amShaderResourceView* m_bottom;
        amShaderResourceView* m_front;
        amShaderResourceView* m_back;
      };
      amShaderResourceView* m_cube[6];
    };

    amShaderResourceView* m_cubeOneTex;
    bool m_hrd;
    String m_fileName;
    amFormats::E m_format;
    uint32 m_size;
  };
}
