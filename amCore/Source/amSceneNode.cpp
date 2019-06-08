#include "amSceneNode.h"

#include "amGameObject.h"
#include "amCamera.h"

namespace amEngineSDK {
  amSceneNode::amSceneNode(amSceneNode* _parent,
                           amNodeType::E _type,
                           bool _isVisible) {
    m_parent = _parent;
    m_type = _type;
    m_nodeObj = nullptr;
    m_isVisible = _isVisible;
  }

  amSceneNode::amSceneNode(amSceneNode * _parent,
                           amGameObject * _obj,
                           amNodeType::E _type,
                           bool _isVisible) {
    m_parent = _parent;
    m_type = _type;
    m_nodeObj = _obj;
    m_isVisible = _isVisible;
  }

  amSceneNode::~amSceneNode() {
    delete(m_nodeObj);
    uint32 size = static_cast<uint32>(m_vecChildren.size());
    for (uint32 i = 0; i < size; ++i) {
      delete(m_vecChildren[i]);
    }
  }

  Vector<amSceneNode*> 
  amSceneNode::getAllChildrenInCam(amCamera * _cam) {
    Vector<amSceneNode*> camObjs;
    uint32 chldrn = static_cast<uint32>(m_vecChildren.size());
    if (chldrn > 0) {

      for (uint32 i = 0; i < chldrn; ++i) {
        if (m_vecChildren[i]->camOverlap(_cam)) {
          camObjs.push_back(m_vecChildren[i]);
          Vector<amSceneNode*> childCamObjs = m_vecChildren[i]->getAllChildrenInCam(_cam);
          camObjs.insert(camObjs.end(), childCamObjs.begin(), childCamObjs.end());
        }
      }
      
    }
    return camObjs;
  }

  Vector<amResource*> 
  amSceneNode::getAllResourcesInCam(amCamera * _cam) {
    Vector<amResource*> camRes;
    uint32 chldrn = static_cast<uint32>(m_vecChildren.size());
    if (chldrn > 0) {

      for (uint32 i = 0; i < chldrn; ++i) {
        if (m_vecChildren[i]->camOverlap(_cam)) {
          camRes.push_back(m_vecChildren[i]->m_nodeObj->getResourceInComp());
          Vector<amResource*> childCamObjs = m_vecChildren[i]->getAllResourcesInCam(_cam);
          camRes.insert(camRes.end(), childCamObjs.begin(), childCamObjs.end());
        }
      }

    }
    return camRes;
  }

  void 
  amSceneNode::setParent(amSceneNode * _parent) {
    m_parent = _parent;
  }

  void 
  amSceneNode::addChild(amSceneNode * _child) {
    m_vecChildren.push_back(_child);
  }

  void 
  amSceneNode::addChild(amGameObject * _childObj) {
    m_vecChildren.push_back(new amSceneNode(this, _childObj));
  }

  void 
  amSceneNode::removeChild(amSceneNode * _child) {
    uint32 nChildren = static_cast<uint32>(m_vecChildren.size());
    if (nChildren > 0) {
      for (uint32 i = 0; i < nChildren; ++i) {
        if (m_vecChildren[i] == _child)
          delete(m_vecChildren[i]);
      }
    }
  }

  void 
  amSceneNode::setNodeAsRoot(amSceneNode* _root) {
    //Set this node to be Root
    m_type = amNodeType::E::ROOT;
    m_parent = nullptr;
    if (m_nodeObj) {
      m_vecChildren.push_back(new amSceneNode(this, m_nodeObj));
    }
    m_nodeObj = nullptr;
    m_isVisible = false;
    //steal all the child nodes from root
    uint32 nRootChildNodes = static_cast<uint32>(_root->m_vecChildren.size());
    for (uint32 i = 0; i < nRootChildNodes; ++i) {
      m_vecChildren.push_back(_root->m_vecChildren[i]);
    }
  }

  void 
  amSceneNode::setGameObj(amGameObject * _obj) {
    m_nodeObj = _obj;
  }

  bool 
  amSceneNode::camOverlap(amCamera* _cam) {
    return (m_isVisible && m_nodeObj && amMath::intersects(m_nodeObj->getPosition(), _cam->m_clipSpace)) ? true : false;
  }

}
