
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
#include "amMaterial.h"
#include "amMesh.h"
#include "amModel.h"
#include "amDevice.h"


namespace amEngineSDK {
  amResourceManager::amResourceManager() {}

  amResourceManager::~amResourceManager() {}

  amResource* 
  amResourceManager::CreateRegisterModel(const String & pathName, amDevice * _dv) {
    amResource* res = CreateModel(pathName);
    reinterpret_cast<amModel*>(res)->registerMeshTextures(_dv);
  }

  String 
  aiStr_to_amStr(aiString& _aiStr) {
    return _aiStr.C_Str();
  }

  amVector3 
  getPos(const aiVector3D& other) {
    amVector3 v;
    v.x = other.x;
    v.y = other.y;
    v.z = other.z;
    return v;
  }

  amVector2 
  getUV(const aiVector3t<ai_real>& other) {
    amVector2 v;
    v.x = other.x;
    v.y = other.y;
    return v;
  }

  amVector4 
  getColorRGBA(const aiColor4D& other) {
    amVector4 v;
    v.x = other.r;
    v.y = other.g;
    v.z = other.b;
    v.w = other.a;
    return v;
  }

  aiString 
  str_to_aiStr(const String& str) {
    aiString aiStr;
    aiStr.Set(str);
    return aiStr;
  }

  void 
  processMesh(aiMesh* _aiMesh, amMesh* _mesh) {
    /**
      ************************
      *  Load Vertex data for the mesh
      ************************
      */
    uint32 nvertx = _aiMesh->mNumVertices;
    _mesh->m_vb.m_vVertex.resize(nvertx);
    for (uint32 j = 0; j < nvertx; ++j) {
      _mesh->m_vb.m_vVertex[j].setVertexCoord(getPos(_aiMesh->mVertices[j]));
      _mesh->m_vb.m_vVertex[j].setVertexNormal(getPos(_aiMesh->mNormals[j]));

      /**
      ************************
      *  Load UV data for the mesh if it exists
      ************************
      */
      if (_aiMesh->mTextureCoords[0]) {
        _mesh->m_vb.m_vVertex[j].u = _aiMesh->mTextureCoords[0][j].x;
        _mesh->m_vb.m_vVertex[j].v = _aiMesh->mTextureCoords[0][j].y;
      }
    }

    /**
      ************************
      *  Load Index data for the mesh
      ************************
      */
    uint32 nIndex = 0;
    uint32 j = 0;
    uint32 nFaces = _aiMesh->mNumFaces;
    aiFace* face = nullptr;
    _mesh->m_ib.m_vecIB.resize(nFaces * 3);
    for (uint32 i = 0; i < nFaces; ++i) {
      face = &_aiMesh->mFaces[i];
      for (j = 0; j < face->mNumIndices; ++j) {
        _mesh->m_ib.m_vecIB[nIndex] = face->mIndices[j];
        ++nIndex;
      }
    }
    if (nIndex != nFaces * 3) {
      _mesh->m_ib.m_vecIB.resize(nIndex);
    }
  }

  void processMaterial(aiMaterial* _aiMat, amMesh* _mesh, amModel* _model) {
    /**
    ************************
    *  Load Material data
    ************************
    */

    uint32 nMatTextures = _aiMat->mNumProperties;
    uint32 nModelTextures = _model->m_vecTex.size();
    _mesh->m_mat->m_vecTex.resize(nMatTextures);
    _model->m_vecTex.resize(nModelTextures + nMatTextures);
    for (uint32 j = 0; j < nMatTextures; ++j) {
      uint32 texTYpe = _aiMat->mProperties[j]->mType;
      _mesh->m_mat->m_vecTex[j]->m_fileName = _aiMat->GetName().C_Str();
      _mesh->m_mat->m_vecTex[j]->m_tBuffer.resize(_aiMat->mProperties[j]->mDataLength);
      /**
      ************************
      *  Get texture types of the material
      ************************
      */
      if (_aiMat->mProperties[j]->mType == aiTextureType::aiTextureType_DIFFUSE) 
        _mesh->m_mat->m_vecTex[j]->m_tType = amTexType::E::kALBEDO;
      else if (_aiMat->mProperties[j]->mType == aiTextureType::aiTextureType_EMISSIVE)
        _mesh->m_mat->m_vecTex[j]->m_tType = amTexType::E::kEMISSIVE;
      else if (_aiMat->mProperties[j]->mType == aiTextureType::aiTextureType_NORMALS)
        _mesh->m_mat->m_vecTex[j]->m_tType = amTexType::E::kNORMAL;
      else if (_aiMat->mProperties[j]->mType == aiTextureType::AI_MATKEY_GLTF_PBRMETALLICROUGHNESS_METALLICROUGHNESS_TEXTURE) {
        //if (_aiMat->GetTexture(AI_MATKEY_GLTF_PBRMETALLICROUGHNESS_METALLIC_FACTOR, j, )) {
          //TODO: add metalness & roughness, revert to spec = metal & shiny = rough
        //}
      }
      else
        _mesh->m_mat->m_vecTex[j]->m_tType = amTexType::E::kDEFAULT;
      /**
      ************************
      *  Copy the texture buffer
      ************************
      */
      memcpy(&_mesh->m_mat->m_vecTex[j]->m_tBuffer,
             _aiMat->mProperties[j]->mData,
             _aiMat->mProperties[j]->mDataLength);
      /**
      ************************
      *  Save a copy of the pointer to the model
      ************************
      */
      _model->m_vecTex[nModelTextures + j] = _mesh->m_mat->m_vecTex[j];
    }
  }

  void 
  getAllMaterialTexturesOfType(const amModel* mdl,
                               const aiScene* scn,
                               const int32 index,
                               const aiTextureType type,
                               const String& FilePathName) {
    mdl;
    uint32 nMatTex = scn->mMaterials[index]->GetTextureCount(type);
    if (nMatTex > 0) {
      for (uint32 i = 0; i < nMatTex; ++i) {
        Vector<char> vecTmpTex;
        aiString filePathName = str_to_aiStr(FilePathName.substr(0, FilePathName.find_last_of('/')));
        scn->mMaterials[index]->GetTexture(type, index, &filePathName);
      }
    }
  }

  amResource* 
  amResourceManager::CreateModel(const String& pathName) {
    // Create an instance of the Importer class
    Assimp::Importer importer;

    // And have it read the given file with some example post-processing
    // Usually - if speed is not the most important aspect for you - you'll
    // probably to request more post-processing than we do in this example.
    const aiScene* scene = importer.ReadFile(pathName.c_str(),
                                             aiProcess_CalcTangentSpace |
                                             aiProcess_Triangulate |
                                             aiProcess_GenUVCoords |
                                             aiProcess_GenSmoothNormals |
                                             aiProcess_JoinIdenticalVertices |
                                             aiProcess_SortByPType);

    // If the import failed, report it
    if (!scene) {
      //DoTheErrorLogging(importer.GetErrorString());
      return nullptr;
    }
    amModel* model = new amModel();
    uint32 nMeshes = scene->mNumMeshes;
    model->m_vecMeshes.resize(nMeshes);
    /**
    ************************
    *  If model loaded do a pass for each mesh
    ************************
    */
    for (uint32 i = 0; i < nMeshes; ++i) {
      amMesh* mesh = new amMesh();

      processMesh(scene->mMeshes[i], mesh);
      if (i < scene->mNumMaterials) 
        processMaterial(scene->mMaterials[scene->mMeshes[i]->mMaterialIndex], mesh, model);
      
      model->m_vecMeshes.push_back(mesh);
    }

    /**
      ************************
      *  Load Default Texture data
      ************************
      */

    if (scene->HasTextures()) {
      uint32 nTex = scene->mNumTextures;
      model->m_vecTex.resize(nTex);
      for (uint32 j = 0; j < nTex; ++j) {
        uint32 texSize = scene->mTextures[j]->mHeight * scene->mTextures[j]->mWidth;// *4;
        model->m_vecTex[j]->m_tBuffer.resize(texSize);
        memcpy(&model->m_vecTex[j]->m_tBuffer, scene->mTextures[j]->pcData, texSize * 4);
        model->m_vecTex[j]->m_fileName = scene->mTextures[j]->mFilename.C_Str();
      }
    }
    else {
      //TODO: Load default texture
      model->m_vecTex.push_back(reinterpret_cast<amTexture*>(CreateTexture("Resources/DefaultTexture.png")));
    }

    

    // We're done. Everything will be cleaned up by the importer destructor
    m_vecResources.push_back(model);
    return model;
  }

  amResource* 
  amResourceManager::CreateTexture(const String & pathName) {
    int32 width, height, channels;
    amTexture* tex = new amTexture();
    UANSICHAR* texdata = stbi_load(pathName.c_str(), &width, &height, &channels, 0);
    tex->m_tBuffer.resize(width * height);
    memcpy(&tex->m_tBuffer, &texdata, width * height);
    m_vecResources.push_back(tex);
    return tex;
  }
  void amResourceManager::RegisterTexture(amResource * _res, amDevice * _dv, amFormats::E _format) {
    _dv->createShaderResourceView(reinterpret_cast<amShaderResourceView*>(_res),
                                  reinterpret_cast<void*>(amSRV_Types::E::kSRV_TEXTURE2D)
                                  reinterpret_cast<void*>(_format));
  }
}
