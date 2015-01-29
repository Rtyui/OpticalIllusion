#include <iostream>
using namespace std;
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <cmath>

#include "Vector.h"
#include "Ball.h"

#define M_PI       3.14159265358979323846
#define MYERROR 0.00005
#define DISPLAY_WIDTH 1280
#define DISPLAY_HEIGHT 720
#define BALLS_NUMBER 1024
#define BALLS_RADIUS 5
#define BALLS_SPEED 9

int main(){
	ALLEGRO_DISPLAY *display;
	ALLEGRO_TIMER *timer;
	ALLEGRO_EVENT_QUEUE *queue;
	ALLEGRO_EVENT event;

	al_init();
	al_init_primitives_addon();
	al_install_keyboard();
	al_install_mouse();

	display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);
	timer = al_create_timer(1.0 / 60.0);
	queue = al_create_event_queue();

	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_timer_event_source(timer));

	Ball mainBall(Vector(DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2), Vector(0, 0), DISPLAY_HEIGHT * 0.9f / 2);
	int time = 0;
	bool run = true, redraw = false;
	Ball balls[BALLS_NUMBER];

	
	for (int i = 0; i < BALLS_NUMBER; i++){
		if (i == 0){
			balls[i] = Ball(mainBall.position, Vector(cos((M_PI) / BALLS_NUMBER * i) * BALLS_SPEED, -(sin((M_PI) / BALLS_NUMBER * i) * BALLS_SPEED)), BALLS_RADIUS);
		} else
		balls[i] = Ball(mainBall.position, Vector(cos((M_PI) / BALLS_NUMBER * i) * BALLS_SPEED + -1 *(i % 2 == 1) * MYERROR * cos((M_PI) / BALLS_NUMBER * i) / fabs(cos((M_PI) / BALLS_NUMBER * i)), -(sin((M_PI) / BALLS_NUMBER * i) * BALLS_SPEED + -1 * (i % 2 == 1) * ERROR * sin((M_PI) / BALLS_NUMBER * i) / fabs(sin((M_PI) / BALLS_NUMBER * i)))), BALLS_RADIUS);
	}

	al_start_timer(timer);
	while (run){
		al_wait_for_event(queue, &event);

		switch (event.type){

		case(ALLEGRO_EVENT_TIMER) :
			redraw = true;
			for (int i = 0; i < BALLS_NUMBER; i++){
				if (time >= mainBall.radius / (BALLS_NUMBER - 100) * i){
					balls[i].move();
				}
				balls[i].checkMargin(mainBall);
			}
			time++;
			break;
		case(ALLEGRO_EVENT_KEY_DOWN) :
			if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				run = false;
			break;
		}

		if (redraw){
			al_clear_to_color(al_map_rgb(0, 0, 0));

			mainBall.drawEmpty();
			for (int i = 0; i < BALLS_NUMBER; i++){
				balls[i].drawFilled();
			}

			al_flip_display();
		}


	}

	return 0;
}