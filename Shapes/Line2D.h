#ifndef SHAPES_LINE2D_H_
#define SHAPES_LINE2D_H_

#include "Vec2D.h"

class Line2D{
public:

    Line2D(); // Domyślny konstruktor
    Line2D(float x0, float y0, float x1, float y1);
    Line2D(const Vec2D& p0, const Vec2D& p1);

    inline const Vec2D& GetP0() const {return mP0;}
    inline const Vec2D& GetP1() const {return mP1;}

    inline void SetP0(const Vec2D& p0) {mP0 = p0;}
    inline void SetP1(const Vec2D& p1) {mP1 = p1;}

    bool operator==(const Line2D& line) const; // Operator porównania dwóch linii

    float MinDistanceFrom(const Vec2D& p, bool limitToSegment = false) const; // minimalna odległość od punktu do linii

    Vec2D ClosestPoint(const Vec2D& p, bool limitToSegment = false) const; // najbliższy punkt na linii względem danego punktu

    Vec2D Midpoint() const;
    float Slope() const; // Metoda zwracająca nachylenie linii
    float Length() const;

private:
    Vec2D mP0; // punkt początkowy linii
    Vec2D mP1; // punkt końcowy linii
};

#endif