#pragma once
#include "amPrerequisitesCore.h"
#include "amVector4.h"
#include "amVector3.h"
#include "amVector2.h"

namespace amEngineSDK {
  class AM_CORE_EXPORT amVertex
  {
  public:
    amVertex();

    amVertex(float _x, float _y, float _z, float _w,
             float _r, float _g, float _b, float _a,
             float _nx, float _ny, float _nz,
             float _u, float _v);
    amVertex(const amVertex& other);

    ~amVertex();


    amVertex& 
    operator=(const amVertex& other);

    void 
    setVertexCoord(const float _x, const float _y, const float _z, const float _w = 1.0f);

    void 
    setVertexCoord(const amVector3& v, const float _w = 1.0f);

    void 
    setVertexColor(const float _r, const float _g, const float _b, const float _a);

    void
    setVertexColor(const amVector4& _v);

    void 
    setVertexNormal(const float _nx, const float _ny, const float _nz);

    void
    setVertexNormal(const amVector3& v);

    void 
    setVertexUV(const float _u, const float _v);

    void
    setVertexUV(const amVector2& _v);
    
    
    float x; float y; float z; float w;
    float r; float g; float b; float a;
    float nx; float ny; float nz;
    float u; float v;
    
  };
}
