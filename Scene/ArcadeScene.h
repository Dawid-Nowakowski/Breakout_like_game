#ifndef SCENE_ARCADESCENE_H
#define SCENE_ARCADESCENE_H

#include "Scene.h"
#include <memory>

class Screen;

enum eGame{
    BREAK_OUT
};

class ArcadeScene: public Scene {
public:
    ArcadeScene();
    virtual void Init() override;
    virtual void Update(uint32_t dt) override;
    virtual void Draw(Screen& theScreen) override;
    virtual const std::string& GetSceneName() const override;

private:
    std::unique_ptr<Scene> GetScene(eGame game);
};

#endif
