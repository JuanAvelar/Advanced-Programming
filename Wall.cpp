#include "Wall.h"
#include "Window.h"
#include <iostream>
#include <SDL2/SDL_image.h>
using namespace std;

// wall side can be either "up", "down", "right", "left"
// constructor 
Wall::Wall( GameElement::Color color, Wall_type wallside)
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
	int *ptr;
	ptr = set_color_rgba(color);
	_r = *ptr;
	_g = *(ptr + 1);
	_b = *(ptr + 2);
	_a = *(ptr + 3);
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

void Wall::setWallSide(Wall_type wallSide) {
		
}

enum Wall::Wall_type Wall::getWallSide()
{
	return wallside_pick;
}



// return a string representation of Brick's information 
string Wall::toString() const {
	return "0";
	//...
}

