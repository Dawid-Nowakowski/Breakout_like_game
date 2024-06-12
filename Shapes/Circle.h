#ifndef SHAPES_CIRCLE_H_
#define SHAPES_CIRCLE_H_

#include "Shape.h"

class Circle: public Shape {
public:
    Circle();
    Circle(const Vec2D& center, float radius);

    inline virtual Vec2D GetCenterPoint() const override {return mPoints[0];}
    inline float GetRadius() const {return mRadius;} // promień okręgu
    inline void SetRadius(float radius) {mRadius = radius;}
    inline void MoveTo(const Vec2D& position) {mPoints[0] = position;} // Przesuwa środek okręgu do nowej pozycji

    bool Intersects(const Circle& otherCircle) const; // sprawzdza czy okręgi się przecinają
    bool ContainsPoint(const Vec2D& point) const; // sprawdza czy punkt znajduje się wewnątrz okręgu

private:
    float mRadius;
};

#endif