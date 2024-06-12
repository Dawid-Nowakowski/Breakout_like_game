#include "AARectangle.h"
#include "Utils.h"
#include <cmath>

AARectangle::AARectangle(): AARectangle(Vec2D::Zero, Vec2D::Zero) {}

AARectangle::AARectangle(const Vec2D& topLeft, unsigned int width, unsigned int height) {
    mPoints.push_back(topLeft); // Dodanie lewego górnego punktu do wektora punktów
    mPoints.push_back(Vec2D(topLeft.GetX() + width - 1, topLeft.GetY() + height - 1)); // Dodanie prawego dolnego punktu do wektora punktów
}

AARectangle::AARectangle(const Vec2D& topLeft, const Vec2D& bottomRight) {
    mPoints.push_back(topLeft);
    mPoints.push_back(bottomRight);
}

float AARectangle::GetWidth() const {
    return GetBottomRightPoint().GetX() - GetTopLeftPoint().GetX() + 1;
}

float AARectangle::GetHeight() const {
    return GetBottomRightPoint().GetY() - GetTopLeftPoint().GetY() + 1;
}

void AARectangle::MoveTo(const Vec2D& position) {
    float width = GetWidth();
    float height = GetHeight();

    SetTopLeftPoint(position);
    SetBottomRightPoint(Vec2D(position.GetX() + width - 1, position.GetY() + height - 1));
}

Vec2D AARectangle::GetCenterPoint() const {
    return Vec2D(GetTopLeftPoint().GetX() + GetWidth() / 2.0f, GetTopLeftPoint().GetY() + GetHeight() / 2.0f);
}

bool AARectangle::Intersects(const AARectangle& otherRect) const {
    return !(otherRect.GetBottomRightPoint().GetX() < GetTopLeftPoint().GetX() || // Sprawdzenie, czy którykolwiek bok prostokąta nie przecina się z innym prostokątem
             otherRect.GetTopLeftPoint().GetX() > GetBottomRightPoint().GetX() ||
             otherRect.GetBottomRightPoint().GetY() < GetTopLeftPoint().GetY() ||
             otherRect.GetTopLeftPoint().GetY() > GetBottomRightPoint().GetY());
}

bool AARectangle::ContainsPoint(const Vec2D& point) const {
    bool withinX = point.GetX() >= GetTopLeftPoint().GetX() && point.GetX() <= GetBottomRightPoint().GetX(); // Sprawdzenie, czy punkt znajduje się w osi X prostokąta
    bool withinY = point.GetY() >= GetTopLeftPoint().GetY() && point.GetY() <= GetBottomRightPoint().GetY(); // Sprawdzenie, czy punkt znajduje się w osi Y prostokąta

    return withinX && withinY; // true jesli punkt znajduje się wewnątrz prostokąta
}

AARectangle AARectangle::Inset(const AARectangle& rect, Vec2D& insets) {
    return AARectangle(rect.GetTopLeftPoint() + insets, rect.GetWidth() - 2 * insets.GetX(), rect.GetHeight() - 2 * insets.GetY()); // Tworzenie nowego prostokąta z wcięciami
}

std::vector<Vec2D> AARectangle::GetPoints() const {
    std::vector<Vec2D> points; // Inicjalizacja wektora punktów

    points.push_back(mPoints[0]); // Dodanie lewego górnego punktu
    points.push_back(Vec2D(mPoints[1].GetX(), mPoints[0].GetY())); // Dodanie prawego górnego punktu
    points.push_back(mPoints[1]); // Dodanie prawego dolnego punktu
    points.push_back(Vec2D(mPoints[0].GetX(), mPoints[1].GetY())); // Dodanie lewego dolnego punktu

    return points;
}