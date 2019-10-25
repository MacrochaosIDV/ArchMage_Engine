#pragma once
#include "amPrerequisitesCore.h"

namespace amEngineSDK {
  class amResource;
  class amDevice;
  class amTexture;
  class amMaterial;
  class amShaderResourceView;
  class amTextureObject;
  class amRenderTarget;
  class amRenderTargetView;
  class amModel;
  class amMesh;

  class AM_CORE_EXPORT amResourceManager
  {
  public:
    amResourceManager(amDevice* _dv);
    ~amResourceManager();

    amResource* 
    CreateRegisterModel(const String& pathName,
                        const int32 = amMeshLoadFlags::E::kNO_FLAG);

    amModel*
    CreateModel(const String& pathName, 
                const int32 _flags = amMeshLoadFlags::E::kNO_FLAG);

    amTexture*
    CreateTexture(const String& pathName, const int32 _textureFlags = 0);

    amTextureObject*
    CreateTextureObject(const String& pathName, const int32 _textureFlags = 0);

    /**
    ************************
    *  @brief Creates a texObj for render targets' textures
    *  Only use for render targets
    ************************
    */
    amTextureObject*
    CreateTextureObjectRT(const uint32 _height, 
                          const uint32 _width, 
                          const int32 _format,
                          const bool _hdr);

    amShaderResourceView*
    RegisterTexture(amShaderResourceView* _res,
                    amTexture* _tex,
                    const int32,
                    const int32 _srv = amSRV_Types::E::kSRV_TEXTURE2D);

    amRenderTargetView* 
    RegisterRenderTarget(amRenderTargetView* _rt);

    void 
    loadDeafultTex();

    amMaterial*
    CreateMaterial(amTextureObject* _tex, const String& _matName = "");

    amMaterial*
    CreateMaterial(Vector<amTextureObject*>& _texVec, 
                   const String& _matName = "");

    amMaterial*
    CreateMaterial(const String& _pathName, const int32 _textureFlags = 0);

    amRenderTargetView* 
    CreateRenderTarget(amRenderTargetView* _rtv,
                       const int32 _format,
                       const bool _hdr);

    void 
    fillMaterial(amMaterial* _mat, amTextureObject* _tex);

    void 
    setDevice(amDevice* _dv);

    const void*
    GetScene(const String& _pathname);

    /**
    ************************
    *  Default textures and materials
    ************************
    */
    amTextureObject* m_texObjPureBlack;
    amTextureObject* m_texObjPureWhite;
    amTextureObject* m_texObjPureMidGrey;
    amTextureObject* m_texObjDefaultNormals;
    amTextureObject* m_texObjIBL_BRDF_LUT;
    amTextureObject* m_texObjDefaultTex;
    
    amMaterial* m_defaultMat;

    amDevice* m_dv;

    Vector<amResource*> m_vecResources;
    Vector<amResource*> m_vecSceneSharedRes;
    Vector<amResource*> m_vecRenderTargets;
    Vector<amResource*> m_vecMaterials;
    /**
    ************************
    *
    *
    ************************
    *
    *  @PRIORITY_1_TODO: re write resource creation process to that
    *  resManager::get data -> Api::create ptrs -> resManager::store ptrs
    *
    ************************
    *
    *
    ************************
    */
  };
}
