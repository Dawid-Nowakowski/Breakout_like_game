#include "ArcadeScene.h"
#include "Screen.h"
#include "AARectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Color.h"
#include "Line2D.h"
#include "GameController.h"
#include <iostream>

ArcadeScene::ArcadeScene(){

}

void ArcadeScene::Init() {
    ButtonAction action;
    action.key = GameController::ActionKey();
    action.action = [](uint32_t dt, InputState state){
        if(GameController::IsPressed(state)){
            std::cout << "Action button was pressed" << std::endl;
        }
    };

    mGameController.AddInputActionForKey(action);

    MouseButtonAction mouseAction;
    mouseAction.mouseButton = GameController::LeftMouseButton();
    mouseAction.mouseInputAction = [](InputState state, const MousePosition& position)
    {
        if(GameController::IsPressed(state))
        {
            std::cout << "Left Mouse button pressed!"<<std::endl;
        }
    };

    mGameController.AddMouseButtonAction(mouseAction);

    mGameController.SetMouseMovedAction([](const MousePosition& mousePosition){
    });
}

void ArcadeScene::Update(uint32_t dt) {

}

void ArcadeScene::Draw(Screen& mScreen) {
    Line2D line = {Vec2D(0, 0), Vec2D(mScreen.Width(), mScreen.Height())};
    Triangle triangle = {Vec2D(60,10), Vec2D(10,110), Vec2D(110,110)};
    AARectangle rect = {Vec2D(mScreen.Width()/2 - 25, mScreen.Height()/2 -25), 50, 50};
    Circle circle = {Vec2D(mScreen.Width()/2 + 50, mScreen.Height()/2 + 50), 50};

    mScreen.Draw(circle, Color::Blue(), true, Color::Blue());
    mScreen.Draw(rect, Color(100,100,180,100), true, Color(100,100,180,100));
    mScreen.Draw(triangle, Color(200,100,50,100), true, Color(200,100,50,100));
    mScreen.Draw(line, Color::Pink());
}

const std::string& ArcadeScene::GetSceneName() const {

    static std::string sceneName = "Arcade Scene";
    return sceneName;
}

std::unique_ptr<Scene> ArcadeScene::GetScene(eGame game){
    switch (game) {
        case BREAK_OUT:{

        }
        break;
        default:{

        }
        break;
    }
    return nullptr;
}