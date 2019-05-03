#include "amTexture.h"
#include "amPrerequisitesCore.h"

namespace amEngineSDK {
  amTexture::amTexture(Vector<char>* _tBuffer, amTexType::E _tType) {
    m_tBuffer = *_tBuffer;

  }
  amTexture::amTexture() {}

  amTexture::~amTexture() {}

  void amTexture::setTex(Vector<char>* _tBuffer, amTexType::E _tType) {
    m_tBuffer = *_tBuffer;
    m_tType = _tType;
  }
}
