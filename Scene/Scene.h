#ifndef SCENE_SCENE_H
#define SCENE_SCENE_H
#include <string>
#include "Screen.h"
#include "GameController.h"

class Scene{

    //Interface
public:
    virtual ~Scene(){};
    virtual void Init() = 0;
    virtual void Update(uint32_t dt) = 0;
    virtual void Draw(Screen& theScreen) = 0;
    virtual const std::string& GetSceneName() const = 0;

    GameController* GetGameController() {return &mGameController;};

protected:
    GameController mGameController;
};

#endif