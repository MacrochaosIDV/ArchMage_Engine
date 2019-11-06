#include "amTexture.h"
#include "amResourceManager.h"

namespace amEngineSDK {
  amTexture::amTexture(Vector<UANSICHAR>* _tBuffer, amTexType::E _tType) {
    m_tBuffer = *_tBuffer;
    m_tType = _tType;
    m_resourceType = amResourceType::E::kIMG;
    m_hrd = false;
  }

  amTexture::amTexture() {
    m_resourceType = amResourceType::E::kIMG;
    m_hrd = false;
  }

  amTexture::~amTexture() {}

  void
  amTexture::unload() {}

  void amTexture::resize(const uint32 _height, const uint32 _width) {
    m_height = _height;
    m_width = _width;
    m_tBuffer.resize(_height * _width);
  }

  void 
  amTexture::setTex(Vector<UANSICHAR>* _tBuffer, amTexType::E _tType) {
    m_tBuffer = *_tBuffer;
    m_tType = _tType;
  }

  void 
  amTexture::resizeTex(const uint32 _size) {
    m_tBuffer.resize(_size);
  }

}
