#pragma once
namespace amEngineSDK {
  class amBaseApp
  {
   public:
    amBaseApp();
    virtual ~amBaseApp();

    void
    run();

   private:
    void
    Init();
    void
    Update(float deltaTime);
     
    void
    Render();

    void
    Destroy();

   protected:
    virtual void
    preInit();

    virtual void
    postInit();

    virtual void
    postUpdate(float deltaTime);

    virtual void
    postRender();

    virtual void
    preDestroy();

    virtual void
    onMouseMove(float x, float y/*, btns*/);

  };
}


