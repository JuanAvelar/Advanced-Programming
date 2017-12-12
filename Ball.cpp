#include "Ball.h"
#include "Controller.h"
#include <SDL2/SDL_image.h>
#include <iostream>

using namespace std;

// constructor
Ball::Ball(const Window &window, int xposition, int yposition, const int height, const int width, const std::string &image_path)
	: Window(window), MoveableObject(xposition, yposition, height, width, _xdirection, _ydirection, _speed) {
	//... no extra attributes to include?
	auto surface = IMG_Load(image_path.c_str());
	if (!surface) {
		std::cerr << "Failed to create surface.\n";
	}
	pinball = SDL_CreateTextureFromSurface(_renderer, surface);
	if (!pinball) {
		std::cerr << "Failed to create texture\n";
	}
	SDL_FreeSurface(surface);

	//initial directions of the ball
	_xdirection = 0.5*sqrt(2);
	_ydirection = -0.5*sqrt(2);
}

Ball::~Ball() {
	SDL_DestroyTexture(pinball);
}

void Ball::draw() const {
	SDL_Rect ball = { xposition, yposition, width, height };
	if (pinball) {
		SDL_RenderCopy(_renderer, pinball, nullptr, &ball);
	}
	else {
		SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
		SDL_RenderFillRect(_renderer, &ball);
	}
}

//function to move the ball, xposd and yposd are double for the rounding
void Ball::move() {

	if (_speed != 0) {
		xposition += _xdirection*_speed;
		yposition += _ydirection*_speed;
	}

	else {}
	//create the move function --> determined by userinput which we get in the controller
	//return new position
}

//function for when the ball is still attached to the platform. left and right makes the ball follow the platform and the up key will launch it.
void Ball::serveBall(SDL_Event &event) {
	if (_speed == 0) {
		switch (event.type) {

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_LEFT:
				if (xposition > 0 + 30) {
					xposition -= 50;
				}
				break;
			case SDLK_RIGHT:
				if (xposition < (1000 - getWidth()) + 30) {
					xposition += 50;
				}
				break;
			case SDLK_UP:
				_speed = 0.1;
				break;
			}
		default:
			break;
		}
		
	}
	else {}

}