#include "amTextureObject.h"
#include "amTexture.h"

namespace amEngineSDK {
  amTextureObject::amTextureObject() {
    m_tex = new amTexture();
  }

  amTextureObject::~amTextureObject() {}
  amTextureObject & amTextureObject::operator=(const amTextureObject* _texObj) {
    m_tex = _texObj->m_tex;
    m_srv = _texObj->m_srv;
    m_resourceType = amResourceType::kTEX_OBJ;
    return *this;
  }

  void 
  amTextureObject::setapiTex(void * _tex) {
    m_pApiTex = _tex;
  }

  void 
  amTextureObject::resize(const uint32 _height, const uint32 _width) {
    m_tex->resize(_height, _width);
  }
}
