#include "amMesh.h"
#include "amIndexBuffer.h"
#include "amVertexBuffer.h"
#include "amShader.h"
#include "amMaterial.h"

namespace amEngineSDK {
  amMesh::amMesh() {
    //m_mat = new amMaterial();
  }

  amMesh::~amMesh() {}

  amMeshBufferSizes 
  amMesh::getVertexIndexSize() {
    amMeshBufferSizes res;
    res.nIndex = m_ib.m_vecIB.size();
    res.nVertex = m_vb.m_vVertex.size();
    return res;
  }

  void amMesh::registerTextures(amDevice * _dv, const int32 _rbf) {
    m_mat->createTexturesAsRSV(_dv, _rbf);
  }

  uint32
  amMesh::getIndexCount() {
    return static_cast<uint32>(m_ib.m_vecIB.size());
  }
}
