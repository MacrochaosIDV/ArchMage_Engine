#pragma once
#include "amPrerequisitesCore.h"
#include "amResource.h"
#include "amVertex.h"

namespace amEngineSDK {
  class AM_CORE_EXPORT amVertexBuffer : public amResource
  {
  public:
    amVertexBuffer();
    ~amVertexBuffer();

    virtual uint32 
    getVertSize();

    Vector<amVertex> m_vVertex;
    SIZE_T m_numVertex;
  };
}
