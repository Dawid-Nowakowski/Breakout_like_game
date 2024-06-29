#include "Utils.h"
#include <cmath>   // Dołącza bibliotekę <cmath>, która zawiera funkcję fabsf używaną do obliczania wartości bezwzględnej

// Definicja funkcji IsEqual, która sprawdza, czy dwie liczby zmiennoprzecinkowe są równe z dokładnością do EPSILON
bool IsEqual(float x, float y) {
    return fabsf(x - y) < EPSILON; // Zwraca prawdę, jeśli wartość bezwzględna różnicy x i y jest mniejsza niż EPSILON
}

// Definicja funkcji IsGreaterThanOrEqual, która sprawdza, czy pierwsza liczba jest większa lub równa drugiej
bool IsGreaterThanOrEqual(float x, float y) {
    return x > y || IsEqual(x, y); // Zwraca prawdę, jeśli x jest większe od y lub jeśli x jest równe y (z dokładnością do EPSILON)
}

// Definicja funkcji IsLessThanOrEqual, która sprawdza, czy pierwsza liczba jest mniejsza lub równa drugiej
bool IsLessThanOrEqual(float x, float y) {
    return x < y || IsEqual(x, y); // Zwraca prawdę, jeśli x jest mniejsze od y lub jeśli x jest równe y (z dokładnością do EPSILON)
}

float MillisecondsToSeconds(unsigned int milliseconds)
{
    return static_cast<float>(milliseconds) / 1000.0f;
}