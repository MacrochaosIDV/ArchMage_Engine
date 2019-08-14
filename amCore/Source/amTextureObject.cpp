#include "amTextureObject.h"
#include "amTexture.h"

namespace amEngineSDK {
  amTextureObject::amTextureObject() {
    m_tex = new amTexture();
  }

  amTextureObject::~amTextureObject() {}
  amTextureObject & amTextureObject::operator=(const amTextureObject * _texObj) {
    m_tex = _texObj->m_tex;
    m_srv = _texObj->m_srv;
    m_resourceType = amResourceType::kTEX_OBJ;
    return *this;
  }
}
