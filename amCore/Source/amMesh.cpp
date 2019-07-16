#include "amMesh.h"
#include "amIndexBuffer.h"
#include "amVertexBuffer.h"
#include "amShader.h"
#include "amMaterial.h"

namespace amEngineSDK {
  amMesh::amMesh() {}

  amMesh::~amMesh() {}

  amMeshBufferSizes 
  amMesh::getVertexIndexSize() {
    amMeshBufferSizes res;
    res.nIndex = m_ib.m_vecIB.size();
    res.nVertex = m_vb.m_vVertex.size();
    return res;
  }

  void amMesh::registerTextures() {
  
  }

  uint32
  amMesh::getIndexCount() {
    return static_cast<uint32>(m_ib.m_vecIB.size());
  }

}
