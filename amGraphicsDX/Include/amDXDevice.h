/**
***********************************************
 * @file amDXDevice.h
 * @date 2018/10/31
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief 
 *
 * TODO: long description
 *
 * @note
***********************************************
*/
#pragma once
#include "amDXPreReqs.h"

namespace amEngineSDK {
  class amDXDevice
  {
  public:
    amDXDevice();
    ~amDXDevice();

    ID3D10Device* mp_d3dDevice;
  };
}


