#include "Utilities.h"


Utilities::Utilities()
{
}


Utilities::~Utilities()
{
}


float Utilities::twoPointsDistance(Vector a, Vector b){
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}