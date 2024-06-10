#include "Line2D.h"
#include <cmath>
#include "Utils.h"

Line2D::Line2D():Line2D(Vec2D::Zero, Vec2D::Zero){}

Line2D::Line2D(float x0, float y0, float x1, float y1): Line2D(Vec2D(x0, y0), Vec2D(x1, y1)){} // Konstruktor inicjujący obiekt Line2D dwoma punktami o określonych współrzędnych

Line2D::Line2D(const Vec2D& p0, const Vec2D& p1):mP0(p0), mP1(p1){} // Konstruktor inicjujący obiekt Line2D dwoma zadanymi punktami

bool Line2D::operator==(const Line2D& line) const{ // Przeciążenie operatora == dla obiektów typu Line2D
    return line.GetP0() == mP0 && line.GetP1() == mP1;
}

float Line2D::Slope() const{ // współczynnik nachylenia linii
    float dx = mP1.GetX() - mP0.GetX(); // różnica współrzędnych x punktu końcowego i początkowego

    if(fabsf(dx) < EPSILON){
        return 0;
    }

    float dy = mP1.GetY() - mP0.GetY(); // różnica współrzędnych y punktu końcowego i początkowego

    return dy / dx;
}

Vec2D Line2D::Midpoint() const{ // środek odcinka
    return Vec2D((mP0.GetX() + mP1.GetX())/ 2.0f, (mP0.GetY() + mP1.GetY())/2.0f);
}

float Line2D::MinDistanceFrom(const Vec2D& p, bool limitToSegment) const{ // minimalna odległość od punktu do linii
    return p.Distance(ClosestPoint(p, limitToSegment));
}

Vec2D Line2D::ClosestPoint(const Vec2D& p, bool limitToSegment) const{ // najbliższy punkt na linii do podanego punktu
    Vec2D p0ToP = p - mP0; // Wektor od punktu początkowego do zadanego punktu
    Vec2D p0ToP1 = mP1 - mP0; // Wektor od punktu początkowego do punktu końcowego

    float l2 = p0ToP1.Mag2(); // Kwadrat długości wektora od punktu początkowego do punktu końcowego
    float dot = p0ToP.Dot(p0ToP1); // Iloczyn skalarny dwóch wektorów
    float t = dot / l2; // Parametr t, różnica iloczyna skalarnego wektorów przez kwadrat długośc wektora pocz-koniec

    if(limitToSegment){
        t = std::fmax(0, std::fmin(1.0f, t)); // Ograniczenie wartości t do przedziału [0, 1]
    }
    return mP0 + p0ToP1 * t; // Zwraca najbliższy punkt na linii
}


float Line2D::Length() const{
    return mP1.Distance(mP0);
}
