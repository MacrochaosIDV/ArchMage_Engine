#pragma once
#include "amPrerequisitesCore.h"

class amVertex;
class amVertexBuffer;
class amIndexBuffer;
class amShader;
class amMaterial;

namespace amEngineSDK {
  class AM_CORE_EXPORT amModel
  {
  public:
    amModel();
    ~amModel();
    
    void load(const String& pathname);

    amIndexBuffer* m_ib;
    amVertexBuffer* m_vb;
    amShader* m_shader;
    amMaterial* m_mat;
  };
}
