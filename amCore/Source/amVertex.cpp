#include "amVertex.h"

namespace amEngineSDK {
  amVertex::amVertex() {
    w = 1;
  }

  amVertex::amVertex(float _x, float _y, float _z, float _w,
                     float _r, float _g, float _b, float _a,
                     float _nx, float _ny, float _nz,
                     float _u, float _v) {
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
  amVertex & amVertex::operator=(const amVertex & other) {
    x = other.x; y = other.y; z = other.z; w = other.w;
    r = other.r; g = other.g; b = other.b; a = other.a;
    nx = other.nx; ny = other.ny; nz = other.nz;
    u = other.u; v = other.v;
    return *this;
  }
  void amVertex::setVertexCoord(float _x, float _y, float _z, float _w) {
    x = _x; y = _y; z = _z; w = _w;
  }
  void amVertex::setVertexColor(float _r, float _g, float _b, float _a) {
    r = _r; g = _g; b = _b; a = _a;
  }
  void amVertex::setVertexNormal(float _nx, float _ny, float _nz) {
    nx = _nx; ny = _ny; nz = _nz;
  }
  void amVertex::setVertexUV(float _u, float _v) {
    u = _u; v = _v;
  }
}


