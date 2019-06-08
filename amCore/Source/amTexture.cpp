#include "amTexture.h"
#include "amPrerequisitesCore.h"

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
  amTexture::setTex(Vector<UANSICHAR>* _tBuffer, amTexType::E _tType) {
    m_tBuffer = *_tBuffer;
    m_tType = _tType;
  }

}
