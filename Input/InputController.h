//
// Created by 023da on 13.06.2024.
//

#ifndef INPUT_INPUTCONTROLLER_H
#define INPUT_INPUTCONTROLLER_H

#include "InputAction.h"

struct GameController;

class InputController{
public:

    InputController();
    void Init(InputAction quickAction);
    void Update(uint32_t dt);
    void SetGameController(GameController* controller);
private:
    InputAction mQuit;
    GameController* mnoptrCurrentController;
};

#endif
