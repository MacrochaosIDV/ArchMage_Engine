#include "amSceneGraph.h"
#include "amResource.h"
#include "amCameraManager.h"
#include "amResourceManager.h"
#include "amCamera.h"
#include "amSceneNode.h"

namespace amEngineSDK {
  amSceneGraph::amSceneGraph() {}

  amSceneGraph::~amSceneGraph() {}
  Vector<amResource*> amSceneGraph::getNodesOnCam(amCamera * _cam) {

    m_pRoot->camOverlap(_cam);

    return Vector<amResource*>();
  }
}


