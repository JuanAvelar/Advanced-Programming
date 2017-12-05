#include "Ball.h"
#include "Controller.h"
#include <SDL2/SDL_image.h>
#include <iostream>

using namespace std;

// constructor
Ball::Ball(const Window &window, int xposition, int yposition, const int height, const int width, double xspeed, double yspeed, const std::string &image_path)
	: Window(window), MoveableObject(xposition, yposition, height, width, _xdirection, _ydirection, speed) {
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

//function move --> implements abstract class function
double Ball::move() {
	return 0;
	//create the move function --> determined by userinput which we get in the controller
	//return new position
}
