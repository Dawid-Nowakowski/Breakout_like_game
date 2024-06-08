#include <SDL.h>
#include <iostream>
using namespace std;

int main( int argc, char* args[] ) {

    SDL_Init( SDL_INIT_EVERYTHING );  // Inicjalizacja wszystkich systemów SDL
    SDL_Window *window;  // Wskaźnik do okna SDL
    SDL_Renderer *renderer;  // Wskaźnik do renderera SDL
    if (auto error = SDL_CreateWindowAndRenderer( 640, 480,
                                                  SDL_WINDOW_SHOWN, &window, &renderer )) {
        cout << "Nie udalo sie utworzyc okienka" << endl;
    }
    SDL_Event event;  // Zmienna do przechowywania zdarzeń SDL
    int playing = 1;  // Flaga sterująca pętlą gry
    while (playing) {  // Pętla gry
        while (SDL_PollEvent(&event)) {  // Obsługa zdarzeń SDL
            switch (event.type)
            {
                case SDL_QUIT:  // Jeśli użytkownik zamknie okno
                    playing = false;  // Ustawienie flagi końca gry
                    break;
                default:
                    cout << event.type << endl;  // Wypisanie typu zdarzenia na standardowe wyjście
                    break;
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Ustawienie koloru rysowania na czarny (tło)
        SDL_RenderClear(renderer);  // Czyszczenie rendera tj. rysowanie tła
        SDL_SetRenderDrawColor(renderer, 255, 128, 200, 255);  // Ustawienie koloru rysowania na różowy
        SDL_RenderDrawLine(renderer,
                           0, 0, 640, 480);  // Narysowanie linii od lewego górnego do prawego dolnego rogu okna
        SDL_RenderPresent(renderer);  // wyświetlenie wyrenderowanego obrazu
    }
    SDL_DestroyRenderer( renderer );  // Zniszczenie renderera
    SDL_DestroyWindow( window );  // Zniszczenie okna
    SDL_Quit();
    return 0;
}