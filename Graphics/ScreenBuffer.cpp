#include "ScreenBuffer.h"
#include <SDL.h>
#include <cassert>

ScreenBuffer::ScreenBuffer(): mSurface(nullptr){}

ScreenBuffer::ScreenBuffer(const ScreenBuffer& screenBuffer){
    mSurface = SDL_CreateRGBSurfaceWithFormat(0, screenBuffer.mSurface->w, screenBuffer.mSurface->h, 0, screenBuffer.mSurface->format->format); // Tworzy nową powierzchnię o takich samych parametrach jak screenBuffer

    SDL_BlitSurface(screenBuffer.mSurface, nullptr, mSurface, nullptr);
}

ScreenBuffer::~ScreenBuffer(){
    if(mSurface){
        SDL_FreeSurface(mSurface); // Zwolnia pamięć powierzchni
    }
}

ScreenBuffer& ScreenBuffer::operator=(const ScreenBuffer& screenBuffer){ // operator przypisania
    if(this == &screenBuffer){ // Sprawdza, czy obiekt nie jest przypisywany do samego siebie
        return *this; // Jeśli tak, zwraca *this
    }

    if(mSurface != nullptr){ // Sprawdza, czy mSurface nie jest nullptr
        SDL_FreeSurface(mSurface); // Zwolnia pamięć powierzchni
        mSurface = nullptr; // Ustawia mSurface na nullptr
    }

    if(screenBuffer.mSurface != nullptr){
        mSurface = SDL_CreateRGBSurfaceWithFormat(0, screenBuffer.mSurface->w, screenBuffer.mSurface->h, 0, screenBuffer.mSurface->format->format); // Tworzy nową powierzchnię o takich samych parametrach jak screenBuffer

        SDL_BlitSurface(screenBuffer.mSurface, nullptr, mSurface, nullptr); // Kopiuje zawartość z screenBuffer do nowo utworzonej powierzchni
    }

    return *this;
}

void ScreenBuffer::Init(uint32_t format, uint32_t width, uint32_t height){
    mSurface = SDL_CreateRGBSurfaceWithFormat(0, width, height, 0, format); // powierzchnia o parametrach
    Clear();
}

void ScreenBuffer::Clear(const Color& c){
    assert(mSurface);
    if(mSurface){
        SDL_FillRect(mSurface, nullptr, c.GetPixelColor()); // wypełnia powierzchnię kolorem
    }
}

void ScreenBuffer::SetPixel(const Color& color, int x, int y){ // Ustawia piksel o współrzędnych na kolor
    assert(mSurface); // Sprawdza, czy mSurface nie jest nullptr

    if(mSurface && (y < mSurface->h && y >= 0 && x >= 0 && x < mSurface->w)){ // sprawdza, czy współrzędne są w granicach powierzchni
        SDL_LockSurface(mSurface); // blokuje powierzchnię przed dostępem

        uint32_t * pixels = (uint32_t*)mSurface->pixels; // pobiera wskaźnik do tablicy pikseli

        size_t index = GetIndex(y, x);
        pixels[index] = color.GetPixelColor();

        SDL_UnlockSurface(mSurface);
    }
}

uint32_t ScreenBuffer::GetIndex(int r, int c){ // indeks piksela na podstawie wiersza i kolumny
    assert(mSurface); // Sprawdza, czy mSurface nie jest nullptr
    if(mSurface){
        return r * mSurface->w + c;
    }
    return 0;
}