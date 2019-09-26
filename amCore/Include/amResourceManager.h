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

  namespace amMeshLoadFlags
  {
    enum E
    {
      kNO_FLAG = 0,
      kNO_MATS,
      kNO_TEX,
      kNO_MATS_NO_TEX,
      kFIRST_MESH_ONLY,
      kCOMBINE_MESHES,
      kCOUNT
    };
  };

  class AM_CORE_EXPORT amResourceManager
  {
  public:
    amResourceManager(amDevice* _dv);
    ~amResourceManager();

    amResource* 
    CreateRegisterModel(const String& pathName,
                        amMeshLoadFlags::E _flags = amMeshLoadFlags::E::kNO_FLAG);

    amResource*
    CreateModel(const String& pathName, 
                amMeshLoadFlags::E _flags = amMeshLoadFlags::E::kNO_FLAG);

    amTexture*
    CreateTexture(const String& pathName, uint32 _textureFlags = 0);

    amTextureObject*
    CreateTextureObject(const String& pathName, uint32 _textureFlags = 0);

    /**
    ************************
    *  @brief Creates a texObj for render targets' textures
    *  Only use for render targets
    ************************
    */
    amTextureObject*
    CreateTextureObject(const uint32 _height, 
                        const uint32 _width, 
                        const amFormats::E _format, 
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
    CreateMaterial(Vector<amTextureObject*>& _texVec, const String& _matName = "");

    amMaterial*
    CreateMaterial(const String& _pathName, uint32 _textureFlags = 0);

    amRenderTarget* 
    CreateRenderTarget(amRenderTarget* _rt, 
                       const amFormats::E _format, 
                       const bool _hdr);

    void 
    fillMaterial(amMaterial* _mat, amTextureObject* _tex);

    void 
    setDevice(amDevice* _dv);

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
  };
}
