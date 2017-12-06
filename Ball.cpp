#include "Ball.h"
#include "Controller.h"
#include <SDL2/SDL_image.h>
#include <iostream>

using namespace std;

// constructor
Ball::Ball(const Window &window, int xposition, int yposition, const int height, const int width, const std::string &image_path)
	: Window(window), MoveableObject(xposition, yposition, height, width, _xdirection, _ydirection, 0.0) {
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
	xposd = xposition;
	yposd = yposition;
	xdir = xdirection;
	ydir = ydirection;
	ballspeed = speed;
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


void Ball::ballServe(SDL_Event &event) {
	if (ballspeed == 0) {
		switch (event.type) {
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_LEFT:
				if (xposition > 30) {
					xposition -= 100;
					xposd = xposition;
				}
				break;
			case SDLK_RIGHT:
				if (xposition < 930) {
					xposition += 100;
					xposd = xposition;
				}
				break;
			case SDLK_UP:
				ballspeed += 3;
				break;
			}
		default:
			break;
		}

	}
	else {}
}
//function move --> implements abstract class function
double Ball::move() {
	std::cout << "speed = " << ballspeed << endl;
	if (ballspeed != 0) {
		std::cout << xdir << endl << ydir << endl << speed << endl << xdir*speed << endl;
		xposd += xdir*speed;
		yposd += ydir*speed;
		xposition = (int)round(xposd);
		yposition = (int)round(yposd);
		std::cout << "xposd = " << xposd << endl << "yposd = " << yposd << endl << "xposition = " << xposition << endl << "yposition = " << yposition << endl;
		return 0;
	}
	else {
		return 0;
	}
	//create the move function --> determined by userinput which we get in the controller
	//return new position
}
