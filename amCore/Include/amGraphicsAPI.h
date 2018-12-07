/**
***********************************************
 * @file CGraphicsAPI.h
 * @date 2018/10/17
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief  Implements a base Graphics API 
 *
 * @note
***********************************************
*/
#pragma once
#include <amPrerequisitesUtilities.h>
#include "amPrerequisitesCore.h"
#include "amDevice.h"
#include "amDeviceContext.h"

namespace amEngineSDK {
  class AM_CORE_EXPORT amGraphicsAPI
  {
  public:
    amGraphicsAPI();
    ~amGraphicsAPI();

    void createVertexBuffer(int64 nVertex, int64 vertexSize);
    void init();
    void destroy();

  };
}


