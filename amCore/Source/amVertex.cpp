#include "amVertex.h"

namespace amEngineSDK {
  amVertex::amVertex() {
    m_vertex.w = 1;
  }

  amVertex::amVertex(float _x, float _y, float _z, float _w,
                     float _r, float _g, float _b, float _a,
                     float _nx, float _ny, float _nz,
                     float _u, float _v) {
    m_vertex.x = _x; m_vertex.y = _y; m_vertex.z = _z; m_vertex.w = _w;
    m_vertex.r = _r; m_vertex.g = _g; m_vertex.b = _b; m_vertex.a = _a;
    m_vertex.nx = _nx; m_vertex.ny = _ny; m_vertex.nz = _nz;
    m_vertex.u = _u; m_vertex.v = _v;
  }

  amVertex::~amVertex() {}
  void amVertex::setVertexCoord(float _x, float _y, float _z, float _w) {
    m_vertex.x = _x; m_vertex.y = _y; m_vertex.z = _z; m_vertex.w = _w;
  }
  void amVertex::setVertexColor(float _r, float _g, float _b, float _a) {
    m_vertex.r = _r; m_vertex.g = _g; m_vertex.b = _b; m_vertex.a = _a;
  }
  void amVertex::setVertexNormal(float _nx, float _ny, float _nz) {
    m_vertex.nx = _nx; m_vertex.ny = _ny; m_vertex.nz = _nz;
  }
  void amVertex::setVertexUV(float _u, float _v) {
    m_vertex.u = _u; m_vertex.v = _v;
  }
}


