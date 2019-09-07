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

    // TODO: make a shared VB & IB
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
    registerMeshTextures(amDevice* _dv, const int32 _rbf);


    Vector<amMesh*> m_vecMeshes;
    Vector<amTextureObject*> m_vecTex;
    Vector<amMaterial*> m_vecMats;
  };
}
