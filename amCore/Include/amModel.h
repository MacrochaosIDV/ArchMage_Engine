#pragma once
#include "amPrerequisitesCore.h"
#include "amResource.h"

namespace amEngineSDK {
  class amMesh;
  class amTexture;
  class amMaterial;
  class amDevice;
  class amTextureObject;

  class AM_CORE_EXPORT amModel : public amResource
  {
  public:
    amModel();
    ~amModel();

    /**
    ************************
    * //// Mesh ////
    *  Index bufferNum
    *  IndexIndexNum
    *  numVertex
    *  numIndex
    ************************
    */
    void 
    registerMeshTextures(amDevice* _dv);

    void 
    setMaterial(amMaterial* _mat, const uint32 _matIndex);


    Vector<amMesh*> m_vecMeshes;
    uint32 m_numMeshes;
    //Vector<amTextureObject*> m_vecTex;
    //Vector<amMaterial*> m_vecMats;
  };
}
