#include "amMaterial.h"
#include "amTexture.h"
#include "amDevice.h"
#include "amDeviceContext.h"
#include "amShaderResourceView.h"

namespace amEngineSDK {
  amMaterial::amMaterial() {
    m_resourceType = amResourceType::E::kMATERIAL;
  }

  amMaterial::~amMaterial() {}

  void amMaterial::createTexturesAsRSV(amDevice* _dv) {
    int32 size = static_cast<int32>(m_vecTex.size());
    m_vecSRV.resize(size);
    if (size <= 0) {
      for (int32 i = 0; i < size; ++i) {
        m_vecSRV[i]->m_texResource = m_vecTex[i];
        _dv->createShaderResourceView(m_vecSRV[i], 
                                      reinterpret_cast<void*>(amSRV_Types::E::kSRV_TEXTURE2D), 
                                      reinterpret_cast<void*>(amFormats::E::kFORMAT_R16G16B16A16_UINT));
      }
    }
  }

  void amMaterial::setTexsAs_VS_RSV(amDeviceContext * _dc) {
    int32 size = static_cast<int32>(m_vecTex.size());
    if (size <= 0) {
      for (int32 i = 0; i < size; ++i) {
        _dc->setVSResources(i, 1, m_vecSRV[i]);
      }
    }
  }

  void amMaterial::setTexsAs_PS_RSV(amDeviceContext * _dc) {
    int32 size = static_cast<int32>(m_vecTex.size());
    if (size <= 0) {
      for (int32 i = 0; i < size; ++i) {
        _dc->setPSResources(i, 1, m_vecSRV[i]);
      }
    }
  }

}
