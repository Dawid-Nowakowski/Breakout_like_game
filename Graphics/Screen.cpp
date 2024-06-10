#include "Screen.h"
#include "Vec2D.h"
#include "Line2D.h"
#include <SDL.h>
#include <cassert>
#include <cmath>

Screen::Screen(): mWidth(0), mHeight(0), moptrWindow(nullptr), mnoptrWindowSurface(nullptr){}

Screen::~Screen(){ // Destruktor klasy Screen
    if(moptrWindow){ // Sprawdza, czy moptrWindow nie jest nullptr
        SDL_DestroyWindow(moptrWindow); // Niszczy okno SDL
        moptrWindow = nullptr;
    }
    SDL_Quit();
}

SDL_Window* Screen::Init(uint32_t w, uint32_t h, uint32_t mag){ // inicjalizuje okno SDL o podanej szerokości, wysokości i powiększeniu
    if(SDL_Init(SDL_INIT_VIDEO)){
        std::cout << "Error SDL_Init Failed" << std::endl;
        return nullptr;
    }

    mWidth = w;
    mHeight = h;
    moptrWindow = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mWidth * mag, mHeight * mag, 0);

    if(moptrWindow){ // Sprawdza, czy okno zostało poprawnie utworzone
        mnoptrWindowSurface = SDL_GetWindowSurface(moptrWindow); // Pobiera powierzchnię okna

        SDL_PixelFormat *  pixelFormat = mnoptrWindowSurface->format; // Pobiera format pikseli powierzchni okna

        Color::InitColorFormat(pixelFormat); // Inicjalizuje format koloru

        mClearColor = Color::Black(); // Ustawia kolor czyszczenia na czarny
        mBackBuffer.Init(pixelFormat->format, mWidth, mHeight); // Inicjalizuje tylny bufor
        mBackBuffer.Clear(mClearColor); // Czyści tylny bufor
    }

    return moptrWindow; // Zwraca wskaźnik na utworzone okno
}

void Screen::SwapScreens(){ // Funkcja wymieniająca zawartość ekranów
    assert(moptrWindow); // Sprawdza, czy moptrWindow nie jest nullptr
    if(moptrWindow){
        ClearScreen(); // Czyści ekran

        SDL_BlitScaled(mBackBuffer.GetSurface(), nullptr, mnoptrWindowSurface, nullptr); // Skaluje i kopiuje zawartość tylnego bufora na powierzchnię okna
        SDL_UpdateWindowSurface(moptrWindow); // Aktualizuje powierzchnię okna

        mBackBuffer.Clear(mClearColor); // Czyści tylny bufor
    }
}

void Screen::Draw(int x, int y, const Color& color){ // Funkcja rysująca piksel o zadanym kolorze w zadanym miejscu
    assert(moptrWindow); // Sprawdza, czy moptrWindow nie jest nullptr
    if(moptrWindow){
        mBackBuffer.SetPixel(color, x, y); // Ustawia piksel w tylnym buforze
    }
}

void Screen::Draw(const Vec2D& point, const Color& color){ // Funkcja rysująca piksel o zadanym kolorze w zadanym punkcie
    assert(moptrWindow); // Sprawdza, czy moptrWindow nie jest nullptr
    if(moptrWindow){
        mBackBuffer.SetPixel(color, point.GetX(), point.GetY()); // Ustawia piksel w tylnym buforze
    }
}

void Screen::Draw(const Line2D& line, const Color& color){ // Funkcja rysująca linię o zadanym kolorze
    assert(moptrWindow); // Sprawdza, czy moptrWindow nie jest nullptr
    if(moptrWindow){
        int dx, dy;

        int x0 = roundf(line.GetP0().GetX()); // zaokrągla współrzędną x punktu początkowego
        int y0 = roundf(line.GetP0().GetY()); // --//-- współrzędną y punktu początkowego
        int x1 = roundf(line.GetP1().GetX()); // --/-/- współrzędną x punktu końcowego
        int y1 = roundf(line.GetP1().GetY()); // --//-- współrzędną y punktu końcowego

        dx = x1 - x0;
        dy = y1 - y0;

        signed const char ix((dx > 0) - (dx < 0)); // kierunek rysowania po osi x
        signed const char iy((dy > 0) - (dy < 0)); // kierunek rysowania po osi y

        dx = abs(dx) * 2; // Podwaja wartość bezwzględną dx
        dy = abs(dy) * 2; // Podwaja wartość bezwzględną dy

        Draw(x0, y0, color); // Rysuje początkowy piksel

        if(dx >= dy){ // Jeśli różnica w x jest większa lub równa różnicy w y
            int d = dy - dx/2; // Oblicza początkową wartość zmiennej decyzyjnej

            while(x0 != x1){ // Dopóki nie osiągniemy punktu końcowego w osi x
                if(d >= 0){
                    d -= dx; // Aktualizuje zmienną decyzyjną
                    y0 += iy; // Zmienia współrzędną y
                }

                d += dy; // Aktualizuje zmienną decyzyjną
                x0 += ix; // Zmienia współrzędną x

                Draw(x0, y0, color); // Rysuje piksel
            }
        }
        else{ // Jeśli różnica w y jest większa od różnicy w x
            int d = dx - dy/2; // Oblicza początkową wartość zmiennej decyzyjnej

            while(y0 != y1){ // Dopóki nie osiągniemy punktu końcowego w osi y
                if(d >= 0){
                    d -= dy; // Aktualizuje zmienną decyzyjną
                    x0 += ix; // Zmienia współrzędną x
                }

                d += dx; // Aktualizuje zmienną decyzyjną
                y0 += iy; // Zmienia współrzędną y

                Draw(x0, y0, color); // Rysuje piksel
            }
        }
    }
}

void Screen::ClearScreen(){ // Funkcja czyszcząca ekran
    assert(moptrWindow); // Sprawdza, czy moptrWindow nie jest nullptr
    if(moptrWindow){
        SDL_FillRect(mnoptrWindowSurface, nullptr, mClearColor.GetPixelColor()); // Wypełnia powierzchnię okna kolorem czyszczenia
    }
}
