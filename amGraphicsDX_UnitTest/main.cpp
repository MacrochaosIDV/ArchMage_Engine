#include <amBaseApp.h>
#include <amDXGraphicsAPI.h>
using namespace amEngineSDK;

class UT_app : public amBaseApp
{
 public:
  amDXGraphicsAPI amDX;
};

int main() {

  UT_app amApp;

  amApp.setGraphicsAPI(amApp.amDX);
  amApp.run();

  return 0;
}