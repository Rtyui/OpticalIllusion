#pragma once
class Vector
{
public:

	float x;
	float y;

	Vector();
	Vector(float _x, float _y);
	~Vector();

	void addVector(Vector v);
	void operator=(Vector v);
	void reverse();
};

