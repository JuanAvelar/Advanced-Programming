#include "Wall.h"
#include "Window.h"
#include "MoveableObject.h"
#include "Controller.h"
#include <iostream>
#include <SDL2/SDL_image.h>
using namespace std;

// wall side can be either "up", "down", "right", "left"
// constructor 
Wall::Wall(SDL_Color color, Wall_type wallside)
	: GameElement(xposition, yposition, height, width) {
	switch (wallside) {
	case right:
		xposition = 990;
		yposition = 10;
		height = 580;
		width = 10;
		break;
	case up:
		xposition = 0;
		yposition = 0;
		height = 10;
		width = 1000;
		break;
	case left:
		xposition = 0;
		yposition = 10;
		height = 580;
		width = 10;
		break;
	case down:
		xposition = 0;
		yposition = 590;
		height = 10;
		width = 1000;
		break;
	}

	_r = Uint8(color.r);
	_g = Uint8(color.g);
	_b = Uint8(color.b);
	_a = Uint8(color.a);
	wallside_pick = wallside;
}

Wall::~Wall() {
	std::cout << "Wall is being destroyed\n";
	SDL_DestroyTexture(game_wall);
}

void Wall::draw(Window *window_wall) const {
	SDL_Rect fixed_wall = { xposition, yposition, width, height };
	if (game_wall) {
		SDL_RenderCopy(window_wall->_renderer, game_wall, nullptr, &fixed_wall);
	}
	else {
		SDL_SetRenderDrawColor(window_wall->_renderer, _r, _g, _b, _a);
		SDL_RenderFillRect(window_wall->_renderer, &fixed_wall);
	}
}

enum Wall::Wall_type Wall::getWallSide()
{
	return wallside_pick;
}

GameElement::ElementDestroyed Wall::Bounce(GameElement * ball) {
	MoveableObject *lower_inh_ptr = { dynamic_cast<MoveableObject*> (ball)};
	int layer[4] = { 0, 0, 0, 0 };
		switch (this->getWallSide()) {
		case Wall::up:
			layer[0] = this->getYLocation() + 10;
			if (ball->yposition < layer[0]) {
				lower_inh_ptr->_ydirection = -(lower_inh_ptr->_ydirection);
			}
			return GameElement::destroynothing;
			break;
		case Wall::left:
			layer[1] = this->getXLocation() + 10;
			if (ball->xposition < layer[1]) {
				lower_inh_ptr->_xdirection = -(lower_inh_ptr->_xdirection);
			}
			return GameElement::destroynothing;
			break;
		case Wall::right:
			layer[2] = this->getXLocation();
			if ( ball->xposition >(layer[2] - ball->getWidth())) {
				lower_inh_ptr->_xdirection = -(lower_inh_ptr->_xdirection);
			}
			return GameElement::destroynothing;
			break;
		case Wall::down:
			layer[3] = this->getYLocation();
			if (ball->yposition >(layer[3] - ball->getHeight())) {
				delete ball;
				return GameElement::destroyball;
			}
			else {
				return GameElement::destroynothing;
			}
			break;
		default:
			return GameElement::destroynothing;
		}
		

		
}
