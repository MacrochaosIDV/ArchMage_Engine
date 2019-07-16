#include "amTexture.h"
#include "amResourceManager.h"

namespace amEngineSDK {
  amTexture::amTexture(Vector<UANSICHAR>* _tBuffer, amTexType::E _tType) {
    m_tBuffer = *_tBuffer;
    m_tType = _tType;
    m_resourceType = amResourceType::E::kIMG;
  }

  amTexture::amTexture() {
    m_resourceType = amResourceType::E::kIMG;
  }

  amTexture::~amTexture() {}

  void
  amTexture::loadFromFile(const String& _filePathName, amResourceManager* _pRM) {
    _pRM->CreateTexture(_filePathName);
  }

  void
  amTexture::unload() {}

  

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
