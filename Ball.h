#pragma once
#include "Vector.h"

class Ball
{
public:

	Vector position;
	Vector speed;
	float radius;

	Ball();
	Ball(Vector _position, Vector _speed, float _radius);
	~Ball();

	void move();
	void drawFilled();
	void drawEmpty();
	void checkMargin(Ball b);
};

