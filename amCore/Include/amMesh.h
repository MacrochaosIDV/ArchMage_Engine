#pragma once
#include "amPrerequisitesCore.h"
#include "amResource.h"

namespace amEngineSDK {

  class amVertexBuffer;
  class amIndexBuffer;
  class amShader;
  class amMaterial;

  class AM_CORE_EXPORT amMesh : public amResource
  {
  public:
    amMesh();
    ~amMesh();

    amIndexBuffer* m_ib;
    amVertexBuffer* m_vb;
    amShader* m_shader;
    amMaterial* m_mat;
  };
}


