#include "amMaterial.h"
#include "amTexture.h"
#include "amDevice.h"
#include "amDeviceContext.h"
#include "amShaderResourceView.h"
#include "amTextureObject.h"

namespace amEngineSDK {
  amMaterial::amMaterial() {
    m_resourceType = amResourceType::E::kMATERIAL;
    zero();
  }

  amMaterial::amMaterial(const String _name) {
    m_resourceType = amResourceType::E::kMATERIAL;
    m_matName = _name;
    zero();
  }

  amMaterial::amMaterial(const Vector<amShaderResourceView*>& _vecTex) {
    m_resourceType = amResourceType::E::kMATERIAL;
    m_vecTex = _vecTex;
    zero();
  }

  amMaterial::amMaterial(const String _name, const Vector<amShaderResourceView*>& _vecTex) {
    m_resourceType = amResourceType::E::kMATERIAL;
    m_matName = _name;
    m_vecTex = _vecTex;
    zero();
  }

  amMaterial::~amMaterial() {}

  void 
  amMaterial::addTextureToMat(amShaderResourceView* _tex) {
    if (m_matSize >= 5)
      return;
    m_vecTex.push_back(_tex);
    ++m_matSize;
  }

  void amMaterial::zero() {
    m_colorAlbedo = amVector4::ZERO;
    m_colorNormal = amVector4::ZERO;
    m_colorEmissive = amVector4::ZERO;
    m_metalness = 0;
    m_roughness = 0;
    m_matSize = 0;
  }
}
