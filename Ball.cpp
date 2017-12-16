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
	xposition = 530;
	yposition = 480;
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
	//initial directions of the ball
	_xdirection = 0.5*sqrt(2);
	_ydirection = -0.5*sqrt(2);
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
void Ball::move() {

	if (_speed != 0) {
		xpos += _xdirection*_speed;
		ypos += _ydirection*_speed;
		xposition = int(xpos);
		yposition = int(ypos);
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
			case SDLK_LEFT:
				if (xposition > left_wall->getXLocation()+ 20 + 30) {
					xposition -= 50;
				}
				break;
			case SDLK_RIGHT:
				if (xposition < (right_wall->getXLocation() - getWidth() -20) + 30) {
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

//reverses the ball direction if it hits a wall, destroys the ball if it hits the bottom wall
void Ball::wallBounce(GameElement * wall1, GameElement * wall2, GameElement * wall3, GameElement * wall4, bool *Game_lost) {
	Wall *lower_inh_ptr[4] = { dynamic_cast<Wall*> (wall1) , dynamic_cast<Wall*> (wall2) , dynamic_cast<Wall*> (wall3), dynamic_cast<Wall*> (wall4)};
	int layer[4] = {0,0,0,0};
	for (int i = 0; i < 4; i++) {
		switch (lower_inh_ptr[i]->getWallSide()) {
		case Wall::up:
			layer[0] = lower_inh_ptr[i]->getYLocation() + 10;
			break;
		case Wall::left:
			layer[1] = lower_inh_ptr[i]->getXLocation() + 10;
			break;
		case Wall::right:
			layer[2] = lower_inh_ptr[i]->getXLocation();
			break;
		case Wall::down:
			layer[3] = lower_inh_ptr[i]->getYLocation();
			break;
		}
	}
	if (xposition < layer[1] || xposition >(layer[2] - getWidth())) {
		_xdirection = -_xdirection;
	}

	if (yposition < layer[0]) {
		_ydirection = -_ydirection;
	}
	if (yposition >(layer[3] - getHeight())) {
		*Game_lost = true;
		std::cout << "You suck!" << std::endl << "Git gud n00b xddd" << std::endl;
	}
	else {}
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