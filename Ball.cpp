#include "Ball.h"
#include "Utilities.h"
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>


Ball::Ball()
{
}

Ball::Ball(Vector _position, Vector _speed, float _radius){
	radius = _radius;
	position = _position;
	speed = _speed;
}


Ball::~Ball()
{
}

void Ball::move(){
	position.addVector(speed);
}

void Ball::drawFilled(){
	al_draw_filled_circle(position.x, position.y, radius, al_map_rgb(rand() % 255, rand() % 255, rand() % 255));
	//al_draw_filled_circle(position.x, position.y, radius, al_map_rgb(20, 20, 255));
}

void Ball::drawEmpty(){
	al_draw_circle(position.x, position.y, radius, al_map_rgb(255, 0, 0), 1);
}

void Ball::checkMargin(Ball b){
	Utilities u;
	if (u.twoPointsDistance(position, b.position) + radius > b.radius){
		speed.reverse();
	}
}
