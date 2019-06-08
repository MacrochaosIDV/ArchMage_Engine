#include "amModel.h"
#include "amMesh.h"
#include "amMaterial.h"
#include "amTexture.h"

namespace amEngineSDK {
  amModel::amModel() {
    m_resourceType = amResourceType::E::kMODEL;
  }

  amModel::~amModel() {}

}
