#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <iostream>
#include "App.h"

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;
const int MAGNIFICATION = 3;

using namespace std;

int main(int argc, const char * argv[]){

    if(App::Singleton().Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION)){
        App::Singleton().Run();
    }

    return 0;
}