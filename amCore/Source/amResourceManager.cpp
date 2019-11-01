#include "amResourceManager.h"
#include <stb_image.h>
#include <assimp\Importer.hpp> // C++ importer interface
#include <assimp/scene.h> // Output data structure
#include <assimp/postprocess.h> // Post processing flags
#include <assimp/pbrmaterial.h> // Post processing flags

#include "amIndexBuffer.h"
#include "amVertexBuffer.h"
#include "amVertex.h"
#include "amVector4.h"
#include "amVector3.h"
#include "amVector2.h"

#include "amTexture.h"
#include "amRenderTarget.h"
#include "amRenderTargetView.h"
#include "amShaderResourceView.h"
#include "amTextureObject.h"
#include "amMaterial.h"
#include "amResource.h"
#include "amMesh.h"
#include "amModel.h"
#include "amDevice.h"


namespace amEngineSDK {
  uint32 amResourceManager::addModel(amModel * _model) {
    m_vecModels.push_back(_model);
    return static_cast<uint32>(m_vecModels.size() - 1);
  }

  uint32 amResourceManager::addMaterial(amMaterial * _mat) {
    m_vecMaterials.push_back(_mat);
    return static_cast<uint32>(m_vecMaterials.size() - 1);
  }

  uint32 amResourceManager::addRenderTarget(amRenderTargetView * _rtv) {
    m_vecRenderTargets.push_back(_rtv->m_rt);
    return static_cast<uint32>(m_vecRenderTargets.size() - 1);
  }

  uint32 amResourceManager::addSharedResource(amResource * _res) {
    m_vecSceneSharedRes.push_back(_res);
    return static_cast<uint32>(m_vecSceneSharedRes.size() - 1);
  }

  uint32 amResourceManager::addTexture(amResource * _tex) {
    m_vecTextures.push_back(_tex);
    return static_cast<uint32>(m_vecTextures.size() - 1);
  }
}
