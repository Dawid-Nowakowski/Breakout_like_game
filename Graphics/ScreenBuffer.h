#ifndef GRAPHICS_SCREENBUFFER_H_
#define GRAPHICS_SCREENBUFFER_H_

#include <stdint.h>
#include "Color.h"

struct SDL_Surface;

class ScreenBuffer {
public:
    ScreenBuffer();
    ScreenBuffer(const ScreenBuffer& screenBuffer);
    ~ScreenBuffer();

    ScreenBuffer& operator=(const ScreenBuffer& screenBuffer);

    void Init(uint32_t format, uint32_t width, uint32_t h); // inicjalizacja bufora ekranu

    inline SDL_Surface* GetSurface() { return mSurface; } // wskaźnik do powierzchni SDL

    void Clear(const Color& c = Color::Black()); // czyści bufor na czarno

    void SetPixel(const Color& color, int x, int y); // Ustawia piksel na kolor w określonym miejscu

private:
    SDL_Surface* mSurface; // Wskaźnik do powierzchni SDL
    uint32_t GetIndex(int r, int c); // Oblicza indeks piksela na podstawie wiersza i kolumny
};

#endif
