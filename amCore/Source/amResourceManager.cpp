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
#include "amTextureObject.h"
#include "amMaterial.h"
#include "amResource.h"
#include "amMesh.h"
#include "amModel.h"
#include "amDevice.h"


namespace amEngineSDK {
  amResourceManager::amResourceManager(amDevice* _dv) {
    m_dv = _dv;
  }

  amResourceManager::~amResourceManager() {}

  amResource* 
  amResourceManager::CreateRegisterModel(const String & pathName,
                                         const int32 _flags) {
    amResource* res = CreateModel(pathName, _flags);
    reinterpret_cast<amModel*>(res)->registerMeshTextures(m_dv);
    return res;
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

  void 
  processMaterial(aiMaterial* _aiMat, amMesh* _mesh, amModel* _model) {
    /**
    ************************
    *  Load Material data
    ************************
    */
    //TODO: make _mesh->m_mat not be nullptr 
    uint32 nMatTextures = _aiMat->mNumProperties;
    uint32 nModelTextures = static_cast<uint32>(_model->m_vecTex.size());
    _mesh->m_mat = new amMaterial();
    _mesh->m_mat->m_vecTex.resize(nMatTextures);
    _model->m_vecTex.resize(nModelTextures + nMatTextures);
    for (uint32 j = 0; j < nMatTextures; ++j) {
      uint32 texTYpe = _aiMat->mProperties[j]->mType;
      _mesh->m_mat->m_vecTex[j] = new amTextureObject();
      _mesh->m_mat->m_vecTex[j]->m_tex->m_fileName = _aiMat->GetName().C_Str();
      _mesh->m_mat->m_vecTex[j]->m_tex->m_tBuffer.resize(_aiMat->mProperties[j]->mDataLength * sizeof(SIZE_T));
      /**
      ************************
      *  Get texture types of the material
      ************************
      */
      if (texTYpe == aiTextureType::aiTextureType_DIFFUSE)
        _mesh->m_mat->m_vecTex[j]->m_tex->m_tType = amTexType::E::kALBEDO;
      else if (texTYpe == aiTextureType::aiTextureType_EMISSIVE)
        _mesh->m_mat->m_vecTex[j]->m_tex->m_tType = amTexType::E::kEMISSIVE;
      else if (texTYpe == aiTextureType::aiTextureType_NORMALS)
        _mesh->m_mat->m_vecTex[j]->m_tex->m_tType = amTexType::E::kNORMAL;
      else if (texTYpe == aiTextureType::AI_MATKEY_GLTF_PBRMETALLICROUGHNESS_METALLICROUGHNESS_TEXTURE) {
        //if (_aiMat->GetTexture(AI_MATKEY_GLTF_PBRMETALLICROUGHNESS_METALLIC_FACTOR, j, )) {
          //TODO: add metalness & roughness, revert to spec = metal & shiny = rough
        //}
      }
      else
        _mesh->m_mat->m_vecTex[j]->m_tex->m_tType = amTexType::E::kDEFAULT;
      /**
      ************************
      *  Copy the texture buffer
      ************************
      */
      memcpy(&_mesh->m_mat->m_vecTex[j]->m_tex->m_tBuffer,
             _aiMat->mProperties[j]->mData,
             _aiMat->mProperties[j]->mDataLength);
      /**
      ************************
      *  Save a copy of the pointer to the model
      ************************
      */
      _model->m_vecTex[nModelTextures + j]->m_tex = _mesh->m_mat->m_vecTex[j]->m_tex;
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

  amModel*
  amResourceManager::CreateModel(const String& pathName, 
                                 const int32 _flags) {
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
    //model->m_vecMeshes.resize(nMeshes);
    /**
    ************************
    *  If model loaded do a pass for each mesh
    ************************
    */
    for (uint32 i = 0; i < nMeshes; ++i) {
      amMesh* mesh = new amMesh();

      processMesh(scene->mMeshes[i], mesh);
      if (_flags != amMeshLoadFlags::E::kNO_MATS) {
        if (i < scene->mNumMaterials) {
          processMaterial(scene->mMaterials[scene->mMeshes[i]->mMaterialIndex], mesh, model);
        }
      }
      model->m_vecMeshes.push_back(mesh);
    }

    /**
      ************************
      *  Load Default Texture data
      ************************
      */
    if (_flags != amMeshLoadFlags::E::kNO_TEX) {
      if (scene->HasTextures()) {
        uint32 nTex = scene->mNumTextures;
        model->m_vecTex.resize(nTex);
        for (uint32 j = 0; j < nTex; ++j) {
          uint32 texSize = scene->mTextures[j]->mHeight * scene->mTextures[j]->mWidth;// *4;
          model->m_vecTex[j]->m_tex->m_tBuffer.resize(texSize);
          memcpy(&model->m_vecTex[j]->m_tex->m_tBuffer, scene->mTextures[j]->pcData, texSize * 4);
          model->m_vecTex[j]->m_tex->m_fileName = scene->mTextures[j]->mFilename.C_Str();
        }
      }
      else {
        //Load default texture
        amTextureObject* defaultTex = reinterpret_cast<amTextureObject*>(CreateTexture("Resources/Textures/DefaultTexture.png"));
        model->m_vecTex.push_back(defaultTex);
        amMaterial* defaultMat = new amMaterial();
        defaultMat->m_matName = "Default Material";
        defaultMat->m_vecTex.push_back(defaultTex);
        model->m_vecMats.push_back(defaultMat);
      }
    }

    // We're done. Everything will be cleaned up by the importer destructor
    m_vecResources.push_back(model);
    return model;
  }

  amTexture*
  amResourceManager::CreateTexture(const String & pathName, 
                                   const int32 _textureFlags) {
    int32 width, height, channels;
    amTexture* tex = new amTexture();
    tex->m_resBindFlag = amResourceBindFlags::E::kBIND_SHADER_RESOURCE;
    UANSICHAR* texdata = stbi_load(pathName.c_str(),
                                   &width, 
                                   &height, 
                                   &channels, 
                                   0);
    tex->m_width = width;
    tex->m_height = height;
    
    /**
    ************************
    * Format Detection
    ************************
    */
    //Format assumes a color texture
    tex->m_format = amFormats::E::kFORMAT_R8G8B8A8_UNORM;

    if (_textureFlags == amTexType::kMETALNESS ||
        _textureFlags == amTexType::kROUGHNESS) {
      //Format becomes greyScale
      tex->m_format = amFormats::E::kFORMAT_R32_FLOAT;
    }
    else if (_textureFlags == amTexType::E::kLUT ||
             _textureFlags == amTexType::E::kCUBEMAP) {
      m_vecSceneSharedRes.push_back(tex);
      if (_textureFlags == amTexType::E::kCUBEMAP) {
        //Format becomes 16float for HDR lighting
        tex->m_format = amFormats::E::kFORMAT_R16G16B16A16_FLOAT;
      }
    }
    if (_textureFlags == amTexType::E::kCUBEMAP) {
      Vector<float>* v = new Vector<float>();
      v->resize(width * height);
      memcpy(&tex->m_tBufferF, &texdata, width * height);
      tex->m_tBufferF = v;
    }
    else {
      tex->m_tBuffer.resize(width * height);
      memcpy(&tex->m_tBuffer, &texdata, width * height);
    }
    m_vecResources.push_back(tex);
    return tex;
  }

  amTextureObject*
  amResourceManager::CreateTextureObject(const String& pathName, 
                                         const int32 _textureFlags) {
    amTextureObject* texObj = new amTextureObject();
    texObj->m_tex = CreateTexture(pathName, _textureFlags);
    RegisterTexture(texObj->m_srv, texObj->m_tex, texObj->m_tex->m_format);
    return texObj;
  }

  amTextureObject* 
  amResourceManager::CreateTextureObjectRT(const uint32 _height, 
                                           const uint32 _width, 
                                           const int32 _format,
                                           const bool _hdr) {
    _format;

    amTextureObject* texObj = new amTextureObject();
    texObj->m_tex->m_height = _height;
    texObj->m_tex->m_width = _width;
    uint32 size = _height * _width;
    if (_hdr) {
      Vector<float>* v = new Vector<float>();
      v->resize(size);
      texObj->m_tex->m_tBufferF = v;
    }
    else {
      texObj->m_tex->m_tBuffer.resize(size);
    }
    //RegisterRenderTarget(texObj->m_srv, texObj->m_tex, _format);

    return texObj;
  }

  amShaderResourceView*
  amResourceManager::RegisterTexture(amShaderResourceView * _res,
                                     amTexture* _tex,
                                     const int32 _format,
                                     const int32 _srv) {
    return m_dv->createShaderResourceView(_res, 
                                          _tex, 
                                          _srv, 
                                          _format,
                                          amResourceBindFlags::kBIND_SHADER_RESOURCE);
  }

  amRenderTargetView* 
  amResourceManager::RegisterRenderTarget(amRenderTargetView * _rt) {
    _rt;
    return nullptr;
  }

  void 
  amResourceManager::loadDeafultTex() {
    m_texObjPureWhite = CreateTextureObject("Resources/Textures/pureWhite.png");
    m_texObjPureBlack = CreateTextureObject("Resources/Textures/pureBlack.png");
    m_texObjPureMidGrey = CreateTextureObject("Resources/Textures/midGrey.png");
    m_texObjDefaultNormals = CreateTextureObject("Resources/Textures/defaultNormals.png");
    m_texObjDefaultTex = CreateTextureObject("Resources/Textures/DefaultTexture.png");
    m_texObjIBL_BRDF_LUT = CreateTextureObject("Resources/Textures/ibl_brdf_lut.png",
                                               amTexType::kLUT);

    m_defaultMat = new amMaterial("Default Material");
    m_defaultMat->m_vecTex.push_back(m_texObjPureMidGrey);
    m_defaultMat->m_vecTex.push_back(m_texObjDefaultNormals);
    m_defaultMat->m_vecTex.push_back(m_texObjPureBlack);
    m_defaultMat->m_vecTex.push_back(m_texObjPureWhite);
    m_defaultMat->m_vecTex.push_back(m_texObjPureWhite);
  }

  amMaterial*
  amResourceManager::CreateMaterial(amTextureObject* _tex,
                                    const String& _matName) {
    amMaterial* mat = new amMaterial(_matName);
    mat->m_vecTex.push_back(_tex);
    //TODO: make sure texture is registered
    return mat;
  }

  amMaterial*
  amResourceManager::CreateMaterial(Vector<amTextureObject*>& _texVec, 
                                    const String& _matName) {
    amMaterial* mat = new amMaterial();
    mat->m_matName = _matName;
    uint32 size = static_cast<uint32>(_texVec.size());
    mat->m_vecTex.resize(size);
    //mat->m_vecSRV.resize(size);
    for (uint32 i = 0; i < size; ++i) {
      mat->m_vecTex[i] = _texVec[i];
    }
    return mat;
  }

  amMaterial*
  amResourceManager::CreateMaterial(const String& _pathName, 
                                    const int32 _textureFlags) {
    amMaterial* mat = new amMaterial();
    mat->m_matName = _pathName;
    mat->m_vecTex.push_back(reinterpret_cast<amTextureObject*>(CreateTexture(_pathName,
                            _textureFlags)));
    return mat;
  }

  amRenderTargetView*
  amResourceManager::CreateRenderTarget(amRenderTargetView * _rtv,
                                        const int32 _format,
                                        const bool _hdr) {

    _format;
    _hdr;
    /*_rtv->m_rt = CreateTextureObjectRT(_rtv->m_rt->m_height, 
                                              _rtv->m_rt->m_width, 
                                              _format, 
                                              _hdr);*/
    return _rtv;
  }

  void 
  amResourceManager::fillMaterial(amMaterial * _mat, 
                                  amTextureObject * _tex) {

    if (_mat->m_vecTex.size() < 5) { //Change the 5 to a const
      _mat->m_vecTex.resize(5);
      for (uint32 i = static_cast<uint32>(_mat->m_vecTex.size()); i < 5; ++i) {
        _mat->m_vecTex[i] = _tex;
        //_mat->m_vecSRV[i] = _srv;
      }
    }
  }

  void 
  amResourceManager::setDevice(amDevice * _dv) {
    m_dv = _dv;
  }
}
