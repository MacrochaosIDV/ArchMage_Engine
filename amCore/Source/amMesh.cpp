#include "amMesh.h"
#include "amIndexBuffer.h"
#include "amVertexBuffer.h"
#include "amShader.h"
#include "amMaterial.h"

namespace amEngineSDK {
  amMesh::amMesh() {
    m_ib = new amIndexBuffer();
    m_vb = new amVertexBuffer();
  }

  amMesh::~amMesh() {}
}

