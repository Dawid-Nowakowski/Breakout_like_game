#ifndef UTILS_VEC2D_H_
#define UTILS_VEC2D_H_
#include <iostream>

class Vec2D {

public:

    static const Vec2D Zero; // Statyczna stała reprezentująca wektor zerowy

    Vec2D() : Vec2D(0, 0) {} // Konstruktor domyślny inicjujący wektor (0,0)
    Vec2D(float x, float y) : mX(x), mY(y) {} // Konstruktor inicjujący wektor (x, y)

    inline void SetX(float x) { mX = x; }
    inline void SetY(float y) { mY = y; }
    inline float GetX() const { return mX; }
    inline float GetY() const { return mY; }

    friend std::ostream& operator<<(std::ostream& consoleOut, const Vec2D& vec); // Deklaracja przyjacielskiej funkcji operatora <<

    bool operator==(const Vec2D& vec2) const; // Deklaracja operatora porównania ==
    bool operator!=(const Vec2D& vec2) const; // Deklaracja operatora porównania !=

    Vec2D operator-() const; // Deklaracja operatora negacji
    Vec2D operator*(float scale) const; // Deklaracja operatora mnożenia wektora przez skalar
    Vec2D operator/(float scale) const; // Deklaracja operatora dzielenia wektora przez skalar
    Vec2D& operator*=(float scale); // Deklaracja operatora mnożenia wektora przez skalar z przypisaniem
    Vec2D& operator/=(float scale); // Deklaracja operatora dzielenia wektora przez skalar z przypisaniem

    Vec2D operator+(const Vec2D& vec) const; // Deklaracja operatora dodawania wektorów
    Vec2D operator-(const Vec2D& vec) const; // Deklaracja operatora odejmowania wektorów
    Vec2D& operator+=(const Vec2D& vec); // Deklaracja operatora dodawania wektorów z przypisaniem
    Vec2D& operator-=(const Vec2D& vec); // Deklaracja operatora odejmowania wektorów z przypisaniem

    float Mag2() const; // Deklaracja funkcji zwracającej kwadrat długości wektora
    float Mag() const; // Deklaracja funkcji zwracającej długość wektora

    Vec2D GetUnitVec() const; // Deklaracja funkcji zwracającej jednostkowy wektor
    Vec2D& Normalize(); // Deklaracja funkcji normalizującej wektor

    float Distance(const Vec2D& vec) const; // Deklaracja funkcji zwracającej odległość do innego wektora
    float Dot(const Vec2D& vec) const; // Deklaracja funkcji zwracającej iloczyn skalarny z innym wektorem

    Vec2D ProjectOnto(const Vec2D& vec2) const; // Deklaracja funkcji zwracającej rzut wektora na inny wektor

    float AngleBetween(const Vec2D& vec2) const; // Deklaracja funkcji zwracającej kąt pomiędzy wektorami

    Vec2D Reflect(const Vec2D& normal) const; // Deklaracja funkcji zwracającej odbicie wektora względem normalnej

    void Rotate(float angle, const Vec2D& aroundPoint); // Deklaracja funkcji obracającej wektor o kąt wokół punktu
    Vec2D RotationResult(float angle, const Vec2D& aroundPoint) const; // Deklaracja funkcji zwracającej wynik obrotu wektora o kąt wokół punktu

    friend Vec2D operator*(float scalar, const Vec2D& vec); // Deklaracja przyjacielskiego operatora mnożenia skalara przez wektor

private:
    float mX, mY; // Prywatne zmienne członkowskie przechowujące współrzędne wektora
};

#endif // Zakończenie bloku warunkowego preprocesora, oznaczające koniec nagłówka UTILS_VEC2D_H_