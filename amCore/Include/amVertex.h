#pragma once
#include "amPrerequisitesCore.h"

namespace amEngineSDK {
  class AM_CORE_EXPORT amVertex
  {
  public:
    amVertex();
    amVertex(float _x, float _y, float _z, float _w,
             float _r, float _g, float _b, float _a,
             float _nx, float _ny, float _nz,
             float _u, float _v);
    ~amVertex();

    void setVertexCoord(float _x, float _y, float _z, float _w);
    void setVertexColor(float _r, float _g, float _b, float _a);
    void setVertexNormal(float _nx, float _ny, float _nz);
    void setVertexUV(float _u, float _v);
    
    struct
    {
      float x; float y; float z; float w;
      float r; float g; float b; float a;
      float nx; float ny; float nz;
      float u; float v;
    }m_vertex;
  };
}


