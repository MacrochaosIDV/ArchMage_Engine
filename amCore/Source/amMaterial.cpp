#include "amMaterial.h"
#include "amTexture.h"
#include "amDevice.h"
#include "amDeviceContext.h"
#include "amShaderResourceView.h"
#include "amTextureObject.h"

namespace amEngineSDK {
  amMaterial::amMaterial() {
    m_resourceType = amResourceType::E::kMATERIAL;
  }

  amMaterial::amMaterial(const String _name) {
    m_resourceType = amResourceType::E::kMATERIAL;
    m_matName = _name;
  }

  amMaterial::amMaterial(const Vector<amTextureObject*>& _vecTex) {
    m_resourceType = amResourceType::E::kMATERIAL;
    m_vecTex = _vecTex;
  }

  amMaterial::amMaterial(const String _name, const Vector<amTextureObject*>& _vecTex) {
    m_resourceType = amResourceType::E::kMATERIAL;
    m_matName = _name;
    m_vecTex = _vecTex;
  }

  amMaterial::~amMaterial() {}

  void amMaterial::createTexturesAsRSV(amDevice* _dv,
                                       const int32 _srvType,
                                       const int32 _format) {
    int32 size = static_cast<int32>(m_vecTex.size());
    //m_vecSRV.resize(size);
    if (size > 0) {
      for (int32 i = 0; i < size; ++i) {
        m_vecTex[i]->m_srv->m_texResource = m_vecTex[i]->m_tex;
        _dv->createShaderResourceView(m_vecTex[i]->m_srv, 
                                      m_vecTex[i]->m_tex, 
                                      _srvType, 
                                      _format, 
                                      amResourceBindFlags::kBIND_SHADER_RESOURCE);
      }
    }
  }

  void amMaterial::setTexsAs_VS_RSV(amDeviceContext * _dc) {
    int32 size = static_cast<int32>(m_vecTex.size());
    if (size <= 0) {
      for (int32 i = 0; i < size; ++i) {
        _dc->setVSResources(i, 1, m_vecTex[i]->m_srv);
      }
    }
  }

  void amMaterial::setTexsAs_PS_RSV(amDeviceContext * _dc) {
    int32 size = static_cast<int32>(m_vecTex.size());
    if (size <= 0) {
      for (int32 i = 0; i < size; ++i) {
        _dc->setPSResources(i, 1, m_vecTex[i]->m_srv);
      }
    }
  }

}
