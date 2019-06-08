#pragma once
#include "amPrerequisitesUtilities.h"

namespace amEngineSDK {
  template<class T>
  class AM_UTILITIES_EXPORT amModule
  {
  public:

    static T&
    instance() {
      if (!isStartedUp()) {
        // TODO: Should throw exception
      }

      if (isDestroyed()) {
        // TODO: Should throw exception
      }
      return *_instance;
    }

    static T*
    instance() {
      if (!isStartedUp()) {
        // TODO: Should throw exception
      }

      if (isDestroyed()) {
        // TODO: Should throw exception
      }
      return _instance;
    }

    template<class ... Args>
    static void
    startUP(Args&& ... args) {
      if (isStartedUp()) {
        // TODO: Should throw exception
      }
      _instance() = new T(std::forward<Args>(args)...);
      isStartedUp() = true;

      static_cast<amModule*>(_instance())->onStartUp();
    }

    template<class SubType, class... Args>
    static void
    startUp() {
      static_assert(std::is_base_of<T, SubType>::value, "Provided type ins´t derived from the type the module is initialized");
      if (isStartedUp()) {
        // TODO: Should throw exception
      }
      _instance() = new SubType(std::forward<Args>(args)...);
      isStartedUp() = true;

      static_cast<amModule*>(_instance())->onStartUp();
    }

    static void
    shutDown() {
      if (isDestroyed()) {
        // TODO: Should throw exception
      }
      if (!isStartedUp()) {
        // TODO: Should throw exception
      }
      static_cast<amModule*>(_instance())->onShutDown();
      delete(_instance());
      isDestroyed() = true;
    }

    static bool
    isStarted() {
      return isStartedUp() && !isDestroyed();
    }

   protected:

    amModule() = default;

    virtual
    ~amModule() = default;

    amModule(amModule&&) = delete;

    amModule(const amModule&) = delete;

    amModule&
    operator=(amModule&&) = delete;

    amModule&
    operator=(const amModule&) = delete;

    virtual void
    onStartUp() {}

    virtual void 
    onShutDown() {}


    /**
    ************************
    *
    *  @brief  Returns a singleton instance
    *
    ************************
    */
    static T*&
    _instance() {
      static T* inst = nullptr;
      return inst;
    }
    
    static bool&
    isDestroyed() {
      static bool inst = false;
      return inst;
    }

    static bool&
    isStartedUp() {
      static bool inst = false;
      return inst;
    }
   public:
  };
}
