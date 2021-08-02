#include "Vector2.h"

Vector2::Vector2(float p_x, float p_y)
	: x(p_x), y(p_y)
{
}

Vector2::~Vector2()
{
}

Vector2 Vector2::Get() const
{
	return Vector2(x, y);
}

void Vector2::Set(Vector2 newPosition)
{
	x = newPosition.x;
	y = newPosition.y;
}
