#include "amBaseApp.h"

namespace amEngineSDK {
  amBaseApp::amBaseApp() {}

  amBaseApp::~amBaseApp() {}
  void amBaseApp::run() {}
  void amBaseApp::Init() {
    preInit();
    postInit();
  }
  void amBaseApp::Update(float deltaTime) {
    //input.update();
    postUpdate(deltaTime);
  }
  void amBaseApp::Render() {
    //Begin();
    postRender();
    //end();
    //swap();
  }
  void amBaseApp::Destroy() {}
  void amBaseApp::preInit() {}
  void amBaseApp::postInit() {}
  void amBaseApp::postUpdate(float deltaTime) {}
  void amBaseApp::postRender() {}
  void amBaseApp::preDestroy() {}
  void amBaseApp::onMouseMove(float x, float y) {}
}


