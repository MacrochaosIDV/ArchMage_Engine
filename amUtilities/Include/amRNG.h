/**
***********************************************
 * @file amRNG.h
 * @date 2018/10/17
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief Implements a Random Number Generator 
 *
 * @note
***********************************************
*/
#include "amPrerequisitesUtilities.h"

namespace amEngineSDK {
  class AM_UTILITIES_EXPORT amRNG
  {
  public:
    amRNG() = default;
    ~amRNG() = default;

    float 
    ziggurat();

    void 
    boxMuller(float u, float v);

  };
}
