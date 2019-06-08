#include "amSceneGraph.h"
#include "amResource.h"
#include "amCameraManager.h"
#include "amResourceManager.h"
#include "amCamera.h"
#include "amSceneNode.h"

namespace amEngineSDK {
  amSceneGraph::amSceneGraph() {}

  amSceneGraph::~amSceneGraph() {}

  Vector<amResource*> amSceneGraph::getAllResourcesInCam(amCamera * _cam) {
    if(m_pRoot)
      return m_pRoot->getAllResourcesInCam(_cam);
    return Vector<amResource*>();
  }

}