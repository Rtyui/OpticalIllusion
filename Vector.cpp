#include "Vector.h"


Vector::Vector()
{
}

Vector::Vector(float _x, float _y){
	x = _x;
	y = _y;
}


Vector::~Vector()
{
}

void Vector::addVector(Vector v){
	x += v.x;
	y += v.y;
}

void Vector::operator=(Vector v){
	x = v.x;
	y = v.y;
}

void Vector::reverse(){
	x = -x;
	y = -y;
}