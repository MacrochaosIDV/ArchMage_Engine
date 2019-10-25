#include "amResource.h"

namespace amEngineSDK {
  amResource::amResource() {}

  amResource::~amResource() {}

  void 
  amResource::operator<<(FStream& f) {
    f;
  }

  void
  amResource::operator>>(FStream& f) {
    f;
  }
}
