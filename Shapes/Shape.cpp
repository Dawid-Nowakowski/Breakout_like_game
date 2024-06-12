#include "Shape.h"

void Shape::MoveBy(const Vec2D& deltaOffset){ // przesunięcie "obiektu o wektor
	for(Vec2D& point : mPoints)
	{
		point = point + deltaOffset;
	}
}