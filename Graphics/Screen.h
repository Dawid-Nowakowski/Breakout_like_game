#ifndef GRAPHICS_SCREEN_H_
#define GRAPHICS_SCREEN_H_

#include <stdint.h>
#include "ScreenBuffer.h"
#include "Color.h"
#include <vector>

class Vec2D;
class Line2D;
class Triangle;
class AARectangle;
class Circle;
struct SDL_Window;
struct SDL_Surface;

class Screen{
public:
    Screen();
    ~Screen(); // destruktor

    SDL_Window* Init(uint32_t w, uint32_t h, uint32_t mag); // inicjalizacja ekranu
    void SwapScreens(); // zamiana zawartości ekranu

    inline void SetClearColor(const Color& clearColor) {mClearColor = clearColor;} //kolor czyszczenia ekranu
    inline uint32_t Width() const {return mWidth;}
    inline uint32_t Height() const {return mHeight;}

    // Deklaracje metod rysujących
    void Draw(int x, int y, const Color& color); // Rysowanie piksela we współrzędnych
    void Draw(const Vec2D& point, const Color& color); // -//- piksela w punkcie
    void Draw(const Line2D& line, const Color& color); // -//- linii
    void Draw(const Triangle& triangle, const Color& color, bool fill = false, const Color& fillColor = Color::White());
    void Draw(const AARectangle& rect, const Color& color, bool fill = false, const Color& fillColor = Color::White());
    void Draw(const Circle& circle, const Color& color, bool fill = false, const Color& fillColor = Color::White());

private:
    Screen(const Screen& screen); // Prywatna kopia konstruktora
    Screen& operator=(const Screen& screen); // operator przypisania

    void ClearScreen(); // czzyszczenie ekranu
    void FillPoly(const std::vector<Vec2D>& points, const Color& color); // wypełnianie wielokątu kolorem

    uint32_t mWidth;
    uint32_t mHeight;

    Color mClearColor; // Kolor czyszczenia ekranu
    ScreenBuffer mBackBuffer; // Tylny bufor ekranu

    SDL_Window* moptrWindow; // Wskaźnik na okno SDL
    SDL_Surface* mnoptrWindowSurface; // Wskaźnik na powierzchnię okna SDL
};

#endif