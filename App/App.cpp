#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "App.h"
#include "ArcadeScene.h"
#include <cassert>


App& App::Singleton(){ // Metoda Singleton, aby zapewnić istnienie tylko jednej instancji App
    static App theApp;
    return theApp;
}


bool App::Init(uint32_t width, uint32_t height, uint32_t mag){
    mnoptrWindow = mScreen.Init(width, height, mag);

    // Utworzenie unikalnego wskaźnika na nową scenę ArcadeScene
    std::unique_ptr<ArcadeScene> arcadeScene = std::make_unique<ArcadeScene>();

    // Dodanie nowo utworzonej sceny do stosu scen
    PushScene(std::move(arcadeScene));

    return mnoptrWindow != nullptr;
}

void App::Run(){
    if(mnoptrWindow){
        bool running = true;

        uint32_t lastTick = SDL_GetTicks();
        uint32_t currentTick = lastTick;

        uint32_t dt = 10; // Czass aktualizacji
        uint32_t accumulator = 0; // śledzenie czasu

        // Inicjalizacja kontrolera wejścia z funkcją lambda do zatrzymania aplikacji
        mInputController.Init([&running](uint32_t dt, InputState state){
            running = false; // Ustawia running na false, aby zakończyć pętlę
        });


        while(running)
        {
            currentTick = SDL_GetTicks(); // bieżąca wartości tików SDL
            uint32_t frameTime = currentTick - lastTick; // czas trwania ramki

            if(frameTime > 300) // Ograniczenie czasu ramki do 300 milisekund
            {
                frameTime = 300;
            }

            lastTick = currentTick;

            accumulator += frameTime; // Dodanie czasu ramki do akumulatora

            // Obsługa wejścia
            mInputController.Update(dt);

            Scene* topScene = App::TopScene(); // Pobranie górnej sceny ze stosu scen
            assert(topScene && "Why don't have a scene?"); // upewnienie, że topScene nie jest pusta

            if(topScene)
            {
                // Aktualizacja sceny
                while(accumulator >= dt)
                {
                    topScene->Update(dt); // Aktualizacja sceny z krokiem czasowym dt
                    accumulator -= dt;
                }

                // Renderowanie sceny
                topScene->Draw(mScreen); // Rysowanie sceny na ekranie
            }

            mScreen.SwapScreens();
        }
    }
}

void App::PushScene(std::unique_ptr<Scene> scene)
{
    assert(scene && "Don't push nullptr");
    if(scene){
        scene->Init();
        mInputController.SetGameController(scene->GetGameController()); // Ustawienie kontrolera gry dla sceny
        mSceneStack.emplace_back(std::move(scene)); // Dodanie sceny do stosu
        SDL_SetWindowTitle(mnoptrWindow, TopScene()->GetSceneName().c_str()); // Ustawienie tytułu okna na nazwę górnej sceny
    }
}

// Usuwanie sceny ze stosu
void App::PopScene(){
    if(mSceneStack.size() > 1){ // Sprawdzenie, czy na stosie jest więcej niż jedna scena
        mSceneStack.pop_back(); // Usunięcie górnej sceny
    }

    if(TopScene()){ // Sprawdzenie, czy po usunięciu jest jakaś scena na stosie
        mInputController.SetGameController(TopScene()->GetGameController()); // Ustawienie kontrolera gry dla nowej górnej sceny
        SDL_SetWindowTitle(mnoptrWindow, TopScene()->GetSceneName().c_str()); // Ustawienie tytułu okna na nazwę nowej górnej sceny
    }
}

// Pobranie górnej sceny ze stosu
Scene* App::TopScene()
{
    if(mSceneStack.empty()){
        return nullptr;
    }
    return mSceneStack.back().get(); // Zwraca wskaźnik do górnej sceny na stosie
}
