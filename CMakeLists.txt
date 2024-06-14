cmake_minimum_required(VERSION 3.21)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

set(SDL2_INCLUDE_DIR "C:\\Users\\023da\\OneDrive\\Pulpit\\Dawid Nowakowski\\Studia\\Semestr VI\\SGD\\project\\SDL\\include")
set(SDL2_LIB_DIR "C:\\Users\\023da\\OneDrive\\Pulpit\\Dawid Nowakowski\\Studia\\Semestr VI\\SGD\\project\\SDL\\lib\\x64")

include_directories(${SDL2_INCLUDE_DIR} App Assets Game Graphics Input Shapes Scene Utils)

add_executable(${PROJECT_NAME} main.cpp Utils/Utils.cpp Utils/Vec2D.cpp Graphics/Color.cpp Graphics/Screen.cpp Graphics/ScreenBuffer.cpp Shapes/Line2D.cpp Shapes/Shape.cpp Shapes/Triangle.cpp Shapes/Circle.cpp Shapes/AARectangle.cpp App/App.h App/App.cpp Scene/Scene.h Scene/ArcadeScene.h Scene/ArcadeScene.cpp Input/InputAction.h Input/GameController.h Input/GameController.cpp Input/InputController.h Input/InputController.cpp Scene/GameScene.cpp Scene/GameScene.h Game/Game.h Utils/FileCommandLoader.cpp Utils/FileCommandLoader.h)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIB_DIR}/SDL2.lib ${SDL2_LIB_DIR}/SDL2main.lib)