#include "amModel.h"
#include "amVertex.h"
#include "amVertexBuffer.h"
#include "amIndexBuffer.h"
#include "amMaterial.h"
#include "amShader.h"

namespace amEngineSDK {
  amModel::amModel() {}


  amModel::~amModel() {}
  void amModel::load(const String & pathname) {
    Vector<amVertex> tmpVrtx;
    Vector<int32> tmpIndex;
    //m_vb = GraphicsAPI->createVB(desc...);
    //m_vb->SetData(tmpVrtx);
    //m_vb->createGraphicsObj();
  }
}
