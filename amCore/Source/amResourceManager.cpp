#include "amResourceManager.h"
#include <stb_image.h>
#include <assimp\Importer.hpp> // C++ importer interface
#include <assimp/scene.h> // Output data structure
#include <assimp/postprocess.h> // Post processing flags

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


namespace amEngineSDK {
  amResourceManager::amResourceManager() {}

  amResourceManager::~amResourceManager() {}

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
        //mdl->m_vecMats[i]->m_vecTex[index]->m_tBuffer.push_back();
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
    const aiScene* scene = importer.ReadFile(pathName,
                                             aiProcess_CalcTangentSpace |
                                             aiProcess_Triangulate |
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
      
      /**
      ************************
      *  Load Vertex data for the mesh
      ************************
      */
      uint32 nvertx = scene->mMeshes[i]->mNumVertices;
      mesh->m_vb.m_vVertex.resize(nvertx);
      for (uint32 j = 0; j < nvertx; ++j) {
        mesh->m_vb.m_vVertex[j].setVertexCoord(getPos(scene->mMeshes[i]->mVertices[j]));
        mesh->m_vb.m_vVertex[j].setVertexNormal(getPos(scene->mMeshes[i]->mNormals[j]));

        //mesh->m_vb->m_vVertex[j].setVertexUV(getUV(scene->mMeshes[i]->mTextureCoords[j]));
        if (scene->mMeshes[j]->HasTextureCoords(0)) {
          mesh->m_vb.m_vVertex[j].u = scene->mMeshes[i]->mTextureCoords[j]->x;
          mesh->m_vb.m_vVertex[j].v = scene->mMeshes[i]->mTextureCoords[j]->y;
        }
        //mesh->m_vb->m_vVertex[j].setVertexColor(getColorRGBA(scene->mMeshes[i]->mColors[j]));
        mesh->m_vb.m_vVertex[j].r = scene->mMeshes[i]->mColors[j]->r;
        mesh->m_vb.m_vVertex[j].g = scene->mMeshes[i]->mColors[j]->g;
        mesh->m_vb.m_vVertex[j].b = scene->mMeshes[i]->mColors[j]->b;
        mesh->m_vb.m_vVertex[j].a = scene->mMeshes[i]->mColors[j]->a;
      }

      /**
      ************************
      *  Load Index data for the mesh
      ************************
      */
      uint32 nIndex = scene->mMeshes[i]->mFaces->mNumIndices;
      mesh->m_ib.m_vecIB.resize(nIndex);
      memcpy(&mesh->m_ib.m_vecIB, &scene->mMeshes[i]->mFaces->mIndices, nIndex * 4);
      //for (uint32 j = 0; j < nIndex; ++j) {
      //  //mesh->m_ib->m_vecIB[j] = scene->mMeshes[i]->mFaces->mIndices[j];
      //}

      /**
      ************************
      *  Load Texture data
      ************************
      */
      if(scene->HasTextures()) {
        uint32 nTex = scene->mNumTextures;
        model->m_vecTex.resize(nTex);
        for (uint32 j = 0; j < nTex; ++j) {
          uint32 texSize = scene->mTextures[j]->mHeight * scene->mTextures[j]->mWidth * 4;
          model->m_vecTex[j]->m_tBuffer.resize(texSize);
          memcpy(&model->m_vecTex[j]->m_tBuffer, scene->mTextures[j]->pcData, texSize);
          model->m_vecTex[j]->m_fileName = scene->mTextures[j]->mFilename.C_Str();
        }
      }
      
      /**
      ************************
      *  Load Material data
      ************************
      */
      if (scene->HasMaterials()) {
        uint32 nMat = scene->mNumMaterials;
        model->m_vecMats.resize(nMat);
        for (uint32 j = 0; j < nMat; ++j) {
          model->m_vecMats[j]->m_matName = scene->mMaterials[j]->GetName().C_Str();
          //if (scene->mMaterials[j]->GetTextureCount(aiTextureType_DIFFUSE) > 0) {
            //getAllMaterialTexturesOfType(model, scene, j, aiTextureType_DIFFUSE, pathName);
          //}
          //model->m_vecMats[j]->m_vecTex.resize(scene->mMaterials[j]->GetTextureCount(aiTextureType_DIFFUSE));
        }
      }
      model->m_vecMeshes.push_back(mesh);
    }

    // We're done. Everything will be cleaned up by the importer destructor
    m_vecResources.push_back(model);
    return model;


  }

  amResource * 
  amResourceManager::CreateTexture(const String & pathName) {
    int32 width, height, channels;
    amTexture* tex = new amTexture();
    UANSICHAR* texdata = stbi_load(pathName.c_str(), &width, &height, &channels, 0);
    tex->m_tBuffer.resize(width * height);
    memcpy(&tex->m_tBuffer, &texdata, width * height);
    m_vecResources.push_back(tex);
    return tex;
  }

}
