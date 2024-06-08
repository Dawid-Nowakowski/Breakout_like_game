#include "Vec2D.h"
#include "Utils.h"
#include <cassert>
#include <cmath>

const Vec2D Vec2D::Zero;  // Inicjalizacja statycznej stałej klasy Vec2D

std::ostream& operator<<(std::ostream& consoleOut, const Vec2D& vec){
    std::cout << "X: " << vec.mX << ", Y: " << vec.mY << std::endl;  // Wypisanie współrzędnych wektora na standardowe wyjście
    return consoleOut;  // Zwrócenie strumienia wyjścia
}

Vec2D operator*(float scalar, const Vec2D& vec){
    return vec * scalar;  // Przeciążenie operatora mnożenia wektora przez skalar
}

bool Vec2D::operator==(const Vec2D& vec2) const{
    return IsEqual(mX, vec2.mX) && IsEqual(mY, vec2.mY);  // Przeciążenie operatora równości dla porównania dwóch wektorów
}

bool Vec2D::operator!=(const Vec2D& vec2) const{
    return !(*this == vec2);  // Przeciążenie operatora nierówności dla porównania dwóch wektorów
}

Vec2D Vec2D::operator-() const{
    return Vec2D(-mX, -mY);  // Przeciążenie operatora negacji dla wektora
}

Vec2D Vec2D::operator*(float scale) const{
    return Vec2D(scale * mX, scale * mY);  // Przeciążenie operatora mnożenia wektora przez skalar
}

Vec2D Vec2D::operator/(float scale) const{
    assert(fabsf(scale) > EPSILON);  // Sprawdzenie, czy skalar nie jest bliski zeru (fabsf do wartości bezwględnej)
    return Vec2D(mX / scale, mY / scale);  // Przeciążenie operatora dzielenia wektora przez skalar
}

Vec2D& Vec2D::operator*=(float scale){
    *this = *this * scale;  // Przeciążenie operatora mnożenia wektora przez skalar z przypisaniem
    return *this;  // Zwrócenie referencji do siebie
}

Vec2D& Vec2D::operator/=(float scale){
    assert(fabsf(scale) > EPSILON);  // Sprawdzenie, czy skalar nie jest bliski zeru
    *this = *this / scale;  // Przeciążenie operatora dzielenia wektora przez skalar z przypisaniem
    return *this;  // Zwrócenie referencji do siebie
}

Vec2D Vec2D::operator+(const Vec2D& vec) const{
    return Vec2D(mX + vec.mX, mY + vec.mY);  // Przeciążenie operatora dodawania dwóch wektorów
}

Vec2D Vec2D::operator-(const Vec2D& vec) const{
    return Vec2D(mX - vec.mX, mY - vec.mY);  // Przeciążenie operatora odejmowania dwóch wektorów
}

Vec2D& Vec2D::operator+=(const Vec2D& vec){
    *this = *this + vec;  // Przeciążenie operatora dodawania wektora z przypisaniem
    return *this;  // Zwrócenie referencji do siebie
}

Vec2D& Vec2D::operator-=(const Vec2D& vec){
    *this = *this - vec;  // Przeciążenie operatora odejmowania wektora z przypisaniem
    return *this;  // Zwrócenie referencji do siebie
}

float Vec2D::Mag2() const{
    return Dot(*this);  // Obliczenie kwadratu normy wektora
}

float Vec2D::Mag() const{
    return sqrt(Mag2());  // Obliczenie normy wektora
}

Vec2D Vec2D::GetUnitVec() const{
    float mag = Mag();  // Obliczenie długości wektora

    if(mag > EPSILON){  // Sprawdzenie, czy długość wektora jest większa od wartości epsilon
        return *this / mag;  // Zwrócenie wektora znormalizowanego (podzielonego przez jego długość)
    }
    return Vec2D::Zero;  // Jeśli długość wektora jest bliska zeru, zwróć wektor zerowy
}

Vec2D& Vec2D::Normalize(){
    float mag = Mag();  // Obliczenie długości wektora

    if(mag > EPSILON){  // Sprawdzenie, czy długość wektora jest większa od wartości epsilon
        *this /= mag;  // Znormalizowanie wektora (podzielenie przez jego długość)
    }
    return *this;  // Zwrócenie referencji do siebie
}

float Vec2D::Distance(const Vec2D& vec) const{
    return (vec - *this).Mag();  // Obliczenie odległości między dwoma wektorami (długość różnicy)
}

float Vec2D::Dot(const Vec2D& vec) const{
    return mX * vec.mX + mY * vec.mY;  // Obliczenie iloczynu skalarnego dwóch wektorów
}

Vec2D Vec2D::ProjectOnto(const Vec2D& vec2) const{
    Vec2D unitVec2 = vec2.GetUnitVec();  // Obliczenie wektora jednostkowego
    float dot = Dot(unitVec2);  // Obliczenie iloczynu skalarnego

    return unitVec2 * dot;  // Obliczenie projekcji wektora
}

float Vec2D::AngleBetween(const Vec2D& vec2) const{
    return acosf(GetUnitVec().Dot(vec2.GetUnitVec()));  // Obliczenie kąta między dwoma wektorami
}

Vec2D Vec2D::Reflect(const Vec2D& normal) const{
    return *this - 2 * ProjectOnto(normal);  // Obliczenie wektora odbitego
}

void Vec2D::Rotate(float angle, const Vec2D& aroundPoint){
    float cosine = cosf(angle);  // Obliczenie cosinusa kąta
    float sine = sinf(angle);  // Obliczenie sinusua kąta

    Vec2D thisVec(mX, mY);  // Utworzenie kopii bieżącego wektora
    thisVec -= aroundPoint;  // Przesunięcie wektora względem punktu

    float xRot = thisVec.mX * cosine - thisVec.mY * sine;  // Obliczenie współrzędnej x po rotacji
    float yRot = thisVec.mX * sine + thisVec.mY * cosine;  // Obliczenie współrzędnej y po rotacji
    Vec2D rot = Vec2D(xRot, yRot);  // Utworzenie wektora po rotacji

    *this = rot + aroundPoint;  // Przypisanie przetransformowanego wektora
}

Vec2D Vec2D::RotationResult(float angle, const Vec2D& aroundPoint) const{
    float cosine = cosf(angle);  // Obliczenie cosinusa kąta
    float sine = sinf(angle);  // Obliczenie sinusua kąta

    Vec2D thisVec(mX, mY);  // Utworzenie kopii bieżącego wektora
    thisVec -= aroundPoint;  // Przesunięcie wektora względem punktu

    float xRot = thisVec.mX * cosine - thisVec.mY * sine;  // Obliczenie współrzędnej x po rotacji
    float yRot = thisVec.mX * sine + thisVec.mY * cosine;  // Obliczenie współrzędnej y po rotacji
    Vec2D rot = Vec2D(xRot, yRot);  // Utworzenie wektora po rotacji

    return rot + aroundPoint;  // Zwrócenie przetransformowanego wektora
}