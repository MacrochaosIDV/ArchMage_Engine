#pragma once
#include "amPrerequisitesCore.h"

namespace amEngineSDK {
  class amResource;
  class amDevice;
  class amTexture;
  class amMaterial;
  class amShaderResourceView;
  class amTextureObject;

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
                        amMeshLoadFlags::E _flags = amMeshLoadFlags::E::kNO_FLAG,
                        amDevice* _dv = nullptr);

    amResource*
    CreateModel(const String& pathName, 
                amMeshLoadFlags::E _flags = amMeshLoadFlags::E::kNO_FLAG);

    amResource*
    CreateTexture(const String& pathName, uint32 _textureFlags = 0);

    amShaderResourceView*
    RegisterTexture(amResource* _res, 
                    const int32,
                    const int32 _srv = amSRV_Types::E::kSRV_TEXTURE2D,
                    amDevice* _dv = nullptr);

    void 
    loadDeafultTex();

    amResource* 
    CreateMaterial(amTextureObject* _tex, const String& _matName = "");

    amResource* 
    CreateMaterial(Vector<amTextureObject*>& _texVec, const String& _matName = "");

    amResource* 
    CreateMaterial(const String& _pathName, uint32 _textureFlags = 0);

    void 
    fillMaterial(amMaterial* _mat, amTextureObject* _tex);

    void 
    setDevice(amDevice* _dv);

    amResource* m_pureBlack;
    amResource* m_pureWhite;
    amResource* m_defaultTex;

    amShaderResourceView* m_SRVpureBlack;
    amShaderResourceView* m_SRVpureWhite;
    amShaderResourceView* m_SRVdefaultTex;

    amDevice* m_dv;

    Vector<amResource*> m_vecResources;
    Vector<amResource*> m_vecSceneSharedRes;
  };
}
