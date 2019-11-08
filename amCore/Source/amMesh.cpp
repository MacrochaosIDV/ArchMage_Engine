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
    memset(&res, 0, sizeof(res));
    if (m_ib)
      res.nIndex = m_ib->m_vecIB.size();
    if (m_vb)
      res.nVertex = m_vb->m_vVertex.size();
    return res;
  }

  void 
  amMesh::setMaterial(amMaterial * _mat) {
    m_mat = _mat;
  }

  uint32
  amMesh::getIndexCount() {
    if (m_ib)
      return static_cast<uint32>(m_ib->m_vecIB.size());
    return 0;
  }
}
