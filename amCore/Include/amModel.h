#pragma once
#include "amPrerequisitesCore.h"
#include "amResource.h"

namespace amEngineSDK {
  class amMesh;
  class amTexture;
  class amMaterial;
  class amDevice;

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
    registerMeshTextures(amDevice* _dv);


    Vector<amMesh*> m_vecMeshes;
    Vector<amTexture*> m_vecTex;
    Vector<amMaterial*> m_vecMats;
  };
}
