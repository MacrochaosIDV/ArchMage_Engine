/**
***********************************************
 * @file CGraphicsAPI.h
 * @date 2018/10/17
 *
 * @author Andr�s Sumano
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

    virtual void createVertexBuffer(int64 nVertex, int64 vertexSize);

    virtual void 
    init(void* _wnd);

    virtual void 
    Render();

    virtual void 
    destroy();

    virtual void
    initContent();

    virtual void
    initSystems();

  };
}

