#pragma once


class Vector2
{
public:
	Vector2(float p_x, float p_y);
	~Vector2();

	Vector2 Get() const;
	void Set(Vector2 newPosition);

	float x, y;

	Vector2& operator+(Vector2& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}
};


