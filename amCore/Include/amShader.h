#pragma once
#include "amPrerequisitesCore.h"
#include "amBlob.h"

namespace amEngineSDK {
  class amDeviceContext;

  class AM_CORE_EXPORT amShader
  {
   public:
    amShader() = default;
    amShader(const String _pathName,
             const String _shaderName,
             const String _entryPoint, 
             const String _shaderModel);
    ~amShader();

    virtual int32
    CompileShaderFromFile(const String szFileName,
                          const ANSICHAR* szEntryPoint,
                          const ANSICHAR* szShaderModel,
                          void** ppBlobOut);

    virtual void
    setShader(amDeviceContext* pDC);

    virtual void 
    Compile();

    amBlob m_buffer;
    String m_shaderName;
    String m_pathFileName;
    String m_entryPoint;
    String m_shaderModel;
  };
}
