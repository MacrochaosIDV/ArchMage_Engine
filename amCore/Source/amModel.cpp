#include "amModel.h"
#include "amMesh.h"
#include "amMaterial.h"
#include "amTexture.h"

namespace amEngineSDK {
  amModel::amModel() {
    m_resourceType = amResourceType::E::kMODEL;
  }

  amModel::~amModel() {}

  void amModel::registerMeshTextures(amDevice* _dv) {
    uint32 size = static_cast<uint32>(m_vecMeshes.size());
    for (uint32 i = 0; i < size; ++i) {
      _dv;
      //m_vecMeshes[i]->registerTextures(_dv);
    }
  }

}
