cmake_minimum_required(VERSION 3.21)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

set(SDL2_INCLUDE_DIR "C:\\Users\\023da\\OneDrive\\Pulpit\\Dawid Nowakowski\\Studia\\Semestr VI\\SGD\\project\\SDL\\include")
set(SDL2_LIB_DIR "C:\\Users\\023da\\OneDrive\\Pulpit\\Dawid Nowakowski\\Studia\\Semestr VI\\SGD\\project\\SDL\\lib\\x64")

include_directories(${SDL2_INCLUDE_DIR} Assets Graphics Shapes Utils)

add_executable(${PROJECT_NAME} main.cpp Utils/Utils.cpp Utils/Vec2D.cpp Graphics/Color.cpp Graphics/Screen.cpp Graphics/ScreenBuffer.cpp Shapes/Line2D.cpp Shapes/Shape.cpp Shapes/Triangle.cpp Shapes/Circle.cpp Shapes/AARectangle.cpp)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIB_DIR}/SDL2.lib ${SDL2_LIB_DIR}/SDL2main.lib)