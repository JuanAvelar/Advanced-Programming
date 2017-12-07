#include "Wall.h"
#include <iostream>
#include <SDL2/SDL_image.h>
using namespace std;

// wall side can be either "up", "down", "right", "left"
// constructor 
Wall::Wall( int xposition, int yposition, const int	height, const int width, int r, int g, int b, int a, Wall_type wallside)
	: GameElement(xposition, yposition, height, width), _r(r), _g(g), _b(b), _a(a) {
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
	//wall = wallSide;
}

string Wall::getWallSide() {
	return wall;
}

// return a string representation of Brick's information 
string Wall::toString() const {
	return "0";
	//...
}

