#include "amVertex.h"

namespace amEngineSDK {
  amVertex::amVertex() {
    w = 1;
  }

  amVertex::amVertex(const float _x, const float _y, const float _z, const float _w,
                     const float _r, const float _g, const float _b, const float _a,
                     const float _nx, const float _ny, const float _nz,
                     const float _u, const float _v) {
    x = _x; y = _y; z = _z; w = _w;
    r = _r; g = _g; b = _b; a = _a;
    nx = _nx; ny = _ny; nz = _nz;
    u = _u; v = _v;
  }

  amVertex::amVertex(const amVertex & other) {
    x = other.x; y = other.y; z = other.z; w = other.w;
    r = other.r; g = other.g; b = other.b; a = other.a;
    nx = other.nx; ny = other.ny; nz = other.nz;
    u = other.u; v = other.v;
  }

  amVertex::~amVertex() {}

  amVertex &
  amVertex::operator=(const amVertex & other) {
    x = other.x; y = other.y; z = other.z; w = other.w;
    r = other.r; g = other.g; b = other.b; a = other.a;
    nx = other.nx; ny = other.ny; nz = other.nz;
    u = other.u; v = other.v;
    return *this;
  }

  void 
  amVertex::setVertexCoord(const float _x, const float _y, const float _z, const float _w) {
    x = _x; y = _y; z = _z; w = _w;
  }
  
  void 
  amVertex::setVertexCoord(const amVector3& _v, const float _w) {
    x = _v.x;
    y = _v.y;
    z = _v.z;
    w = _w;
  }

  void 
  amVertex::setVertexColor(const float _r, const float _g, const float _b, const float _a) {
    r = _r; g = _g; b = _b; a = _a;
  }
  
  void 
  amVertex::setVertexColor(const amVector4 & _v) {
    r = _v.x;
    g = _v.y;
    b = _v.z;
    a = _v.w;
  }

  void 
  amVertex::setVertexNormal(const float _nx, const float _ny, const float _nz) {
    nx = _nx; ny = _ny; nz = _nz;
  }

  void 
  amVertex::setVertexNormal(const amVector3 & _v) {
    nx = _v.x; ny = _v.y; nz = _v.z;
  }

  void 
  amVertex::setVertexUV(const float _u, const float _v) {
    u = _u; v = _v;
  }

  void 
  amVertex::setVertexUV(const amVector2 & _v) {
    v = _v.x;
    u = _v.y;
  }
}
