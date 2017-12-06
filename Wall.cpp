#include "Wall.h"
#include <iostream>
using namespace std;

// wall side can be either "up", "down", "right", "left"

// constructor 
Wall::Wall(const Window window, int xposition, int yposition, const int	height, const int width, Wall_type wallSide, int r, int g, int b, int a)
	:Window(window), GameElement(xposition, yposition, height, width), _r(r), _g(g), _b(b), _a(a) {
	//setWallSide(wallSide);
	std::cout << "aqui esta el error\n";
}

void Wall::draw() const {
	SDL_Rect fixed_wall = { xposition, yposition, width, height };
	if (game_wall) {
		SDL_RenderCopy(_renderer, game_wall, nullptr, &fixed_wall);
	}
	else {
		SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
		SDL_RenderFillRect(_renderer, &fixed_wall);
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

