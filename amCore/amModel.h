#pragma once
#include "amPrerequisitesCore.h"

namespace amEngineSDK {
  class AM_CORE_EXPORT amModel
  {
  public:
    amModel();
    ~amModel();
    /*
    void load(const string& pathname); {
      vector<vertex> tmpVrtx;
      vector<int32> tmpIndex;
      m_vb = GraphicsAPI->createVB(desc...);
      m_vb->SetData(tmpVrtx);
      m_vb->createGraphicsObj();
    }

    indexbuffer m_ib;
    VertexBuffer m_vb;
    */
  };
}
