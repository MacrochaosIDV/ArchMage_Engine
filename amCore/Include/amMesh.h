#pragma once
#include "amPrerequisitesCore.h"
#include "amResource.h"
#include "amVertexBuffer.h"
#include "amIndexBuffer.h"

namespace amEngineSDK {
  struct amMeshBufferSizes
  {
    SIZE_T nVertex;
    SIZE_T nIndex;
  };

  class amShader;
  class amMaterial;
  class amDeviceContext;
  class amDevice;

  class AM_CORE_EXPORT amMesh : public amResource
  {
  public:
    amMesh();
    ~amMesh();

    virtual amMeshBufferSizes
    getVertexIndexSize();

    void 
    registerTextures(amDevice* _dv, const int32 _rbf);

    uint32 
    getIndexCount();

    amIndexBuffer m_ib;
    amVertexBuffer m_vb;
    amShader* m_shader;
    amMaterial* m_mat;
  };
}
