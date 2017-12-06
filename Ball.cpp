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
	_speed = 0;
	xposd = (double) xposition;
	yposd = (double) yposition;
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

// return a string representation of Moveable Object's information --> implements abstract class function
string Ball::toString() const {
	return "0";
	// make string output
}

double Ball::getYDirection() {
	return _ydirection;
}

double Ball::getXDirection() {
	return _xdirection;
}

void Ball::setXDirection(double xdirection) {
	_xdirection = xdirection;
}

void Ball::setYDirection(double ydirection) {
	_ydirection = ydirection;
}


void Ball::serveBall(SDL_Event &event) {
	std::cout << "speed = " << _speed << endl;
	if (_speed == 0) {
		switch (event.type) {

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_LEFT:
				if (xposition > 0+30) {
					xposition -= 50;
				}
				break;
			case SDLK_RIGHT:
				if (xposition < (1000-getWidth())+30) {
					xposition += 50;
				}
				break;
			case SDLK_UP:
				_speed = 0.3;
				break;
			}
		default:
			break;
		}
		xposd = (double)xposition;
		yposd = (double)yposition;
	}
	else {}

}
//function move --> implements abstract class function
double Ball::move() {
	if (_speed != 0) {
		xposd += _xdirection*_speed;
		yposd += _ydirection*_speed;
		xposition = (int)round(xposd);
		yposition = (int)round(yposd);
	}
	
	return 0;
	//create the move function --> determined by userinput which we get in the controller
	//return new position
}

void Ball::wallBounce() {
	if (xposition < 0 || xposition > (1000-getWidth())) {
		_xdirection = -_xdirection;
	}
	
	if (yposition < 0) {
	_ydirection = -_ydirection;
}
	if (yposition > (600-getHeight())) {
		Ball::~Ball();
	}

}

MoveableObject Ball::bounceOnObject(MoveableObject ball) {
	//change ball ...
	return ball;
}
