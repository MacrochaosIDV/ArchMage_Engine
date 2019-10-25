#include "amVertex.h"

namespace amEngineSDK {
  amVertex::amVertex() {}

  amVertex::amVertex(const float _x, const float _y, const float _z,
                     const float _nx, const float _ny, const float _nz,
                     const float _u, const float _v) {
    x = _x; y = _y; z = _z;
    nx = _nx; ny = _ny; nz = _nz;
    u = _u; v = _v;
  }

  amVertex::amVertex(const amVertex & other) {
    x = other.x; y = other.y; z = other.z;
    nx = other.nx; ny = other.ny; nz = other.nz;
    u = other.u; v = other.v;
  }

  amVertex::~amVertex() {}

  amVertex&
  amVertex::operator=(const amVertex & other) {
    x = other.x; y = other.y; z = other.z;
    nx = other.nx; ny = other.ny; nz = other.nz;
    tx = other.tx; ty = other.ty; tz = other.tz;
    bx = other.bx; by = other.by; bz = other.bz;
    u = other.u; v = other.v;
    return *this;
  }

  void 
  amVertex::setVertexCoord(const float _x, const float _y, const float _z) {
    x = _x; 
    y = _y; 
    z = _z;
  }

  void 
  amVertex::setVertexCoord(const amVector3& _v) {
    x = _v.x;
    y = _v.y;
    z = _v.z;
  }

  void 
  amVertex::setVertexNormal(const float _nx, const float _ny, const float _nz) {
    nx = _nx; 
    ny = _ny; 
    nz = _nz;
  }

  void 
  amVertex::setVertexTangent(const float _tx, const float _ty, const float _tz) {
    tx = _tx;
    ty = _ty;
    tz = _tz;
  }

  void 
  amVertex::setVertexTangent(const amVector3 & _v) {
    tx = _v.x;
    ty = _v.y;
    tz = _v.z;
  }

  void 
  amVertex::setVertexBinormal(const float _bx, const float _by, const float _bz) {
    bx = _bx;
    by = _by;
    bz = _bz;
  }

  void 
  amVertex::setVertexBinormal(const amVector3 & _v) {
    bx = _v.x;
    by = _v.y;
    bz = _v.z;
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
