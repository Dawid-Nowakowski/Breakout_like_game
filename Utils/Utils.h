#ifndef UTILS_UTILS_H_
#define UTILS_UTILS_H_

static const float EPSILON = 0.0001f; // Definiowanie stałej EPSILON jako 0.0001f, używanej do porównywania liczb zmiennoprzecinkowych

bool IsEqual(float x, float y);       // Deklaracja funkcji IsEqual, która sprawdza czy dwie liczby zmiennoprzecinkowe są równe
bool IsGreaterThanOrEqual(float x, float y); // Deklaracja funkcji IsGreaterThanOrEqual, która sprawdza czy pierwsza liczba jest większa lub równa drugiej
bool IsLessThanOrEqual(float x, float y); // Deklaracja funkcji IsLessThanOrEqual, która sprawdza czy pierwsza liczba jest mniejsza lub równa drugiej

#endif