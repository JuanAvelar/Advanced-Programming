#include "Ball.h"
#include "Controller.h"
#include "Wall.h"
#include <SDL2/SDL_image.h>
#include <iostream>

using namespace std;

// constructor
Ball::Ball(const Window &window, GameElement::Size size, const std::string &image_path)
	: MoveableObject(xposition, yposition, height, width, _xdirection, _ydirection, _speed) {
	//... no extra attributes to include?
	auto surface = IMG_Load(image_path.c_str());
	if (!surface) {
		std::cerr << "Failed to create surface.\n";
	}
	pinball = SDL_CreateTextureFromSurface(window._renderer, surface);
	if (!pinball) {
		std::cerr << "Failed to create texture\n";
	}
	SDL_FreeSurface(surface);
	
	switch (size) {
	case small:
		height = 20;
		width = 20;
		break;
	case medium:
		height = 60;
		width = 60;
		break;
	case big:
		height = 120;
		width = 120;
		break;
	};
	xposition = 530;
	yposition = 500-height;
	//initial directions of the ball
	_xdirection = 0.01;
	_ydirection = 1.0;
	_speed = 0;
}

Ball::~Ball() {
	SDL_DestroyTexture(pinball);
	std::cout << "Ball is being destroyed\n";
}

void Ball::draw(Window *ball_window) const {
	SDL_Rect ball = { xposition, yposition, width, height };
	if (pinball) {
		SDL_RenderCopy(ball_window->_renderer, pinball, nullptr, &ball);
	}
	else {
		SDL_SetRenderDrawColor(ball_window->_renderer, _r, _g, _b, _a);
		SDL_RenderFillRect(ball_window->_renderer, &ball);
	}
}

//function to move the ball, xposd and yposd are double for the rounding
void Ball::move(GameElement *right_wall, GameElement *left_wall) {

	if (_speed != 0) {
		if (xposition > left_wall->xposition + left_wall->width - 2 && xposition < right_wall->xposition) {
			xpos += _xdirection*_speed;
			ypos += _ydirection*_speed;
			xposition = int(xpos);
			yposition = int(ypos);
		}
	}
	else {
		xpos = double(xposition);
		ypos = double(yposition);
	}
	//create the move function --> determined by userinput which we get in the controller
	//return new position
}

//function for when the ball is still attached to the platform. left and right makes the ball follow the platform and the up key will launch it.
void Ball::serveBall(SDL_Event &event, GameElement *right_wall, GameElement *left_wall) {
	if (_speed == 0) {
		switch (event.type) {

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_a:
				if (xposition > left_wall->getXLocation()+left_wall->getWidth() + 30) {
					xposition -= 50;
				}
				break;
			case SDLK_d:
				if (xposition < (right_wall->getXLocation()) - 70) {
					xposition += 50;
				}
				break;
			case SDLK_UP:
				_speed = 1.0;
				break;
			}
		default:
			break;
		}
	}
}


GameElement::ElementDestroyed Ball::Bounce(GameElement * ball) {
	Ball *lower_inh_ptr = { dynamic_cast<Ball*> (ball) };
	int layer[4] = { this->getXLocation() , this->getXLocation() , this->getYLocation() , this->getYLocation() };

	if (ball->xposition == layer[0]) {//right collision
		lower_inh_ptr->_xdirection = -(lower_inh_ptr->_xdirection);
	}
	if (ball->xposition == (layer[1] + getWidth())) {//left collision
		lower_inh_ptr->_xdirection = -(lower_inh_ptr->_xdirection);
	}
	if (ball->yposition == layer[2]) {//up collision
		lower_inh_ptr->_ydirection = -(lower_inh_ptr->_ydirection);
	}
	if (ball->yposition == (layer[3] + getHeight())) {//down collision
		lower_inh_ptr->_ydirection = -(lower_inh_ptr->_ydirection);
	}
	return GameElement::destroynothing;
}

//* return functions for the x and y direction
double Ball::getYDirection() {
	return _ydirection;
}

double Ball::getXDirection() {
	return _xdirection;
}

// * function to set the x and y direction
void Ball::setXDirection(double xdirection) {
	_xdirection = xdirection;
}

void Ball::setYDirection(double ydirection) {
	_ydirection = ydirection;
}