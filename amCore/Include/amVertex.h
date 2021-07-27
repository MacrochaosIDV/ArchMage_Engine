#pragma once
#include "amPrerequisitesCore.h"
#include "amVector4.h"
#include "amVector3.h"
#include "amVector2.h"

//TODO: turn this into template class
namespace amEngineSDK {
  class AM_CORE_EXPORT amVertex
  {
  public:
    amVertex();

    amVertex(float _x, float _y, float _z,
             float _nx, float _ny, float _nz,
             float _u, float _v);

    amVertex(const amVertex& other);

    ~amVertex();


    amVertex& 
    operator=(const amVertex& other);

    void 
    setVertexCoord(const float _x, const float _y, const float _z);

    void 
    setVertexCoord(const amVector3& _v);

    void 
    setVertexNormal(const float _nx, const float _ny, const float _nz);

    void
    setVertexNormal(const amVector3& _v);

    void
    setVertexTangent(const float _tx, const float _ty, const float _tz);

    void
    setVertexTangent(const amVector3& _v);

    void
    setVertexBinormal(const float _bx, const float _by, const float _bz);

    void
    setVertexBinormal(const amVector3& _v);

    void 
    setVertexUV(const float _u, const float _v);

    void
    setVertexUV(const amVector2& _v);
    
    
    float x; float y; float z;
    float u; float v;
    float tx; float ty; float tz;
    float bx; float by; float bz;
    float nx; float ny; float nz;
    
  };
}
