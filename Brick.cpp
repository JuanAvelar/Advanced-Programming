#include "Brick.h"
#include <iostream>
#include "Window.h"
#include <sstream>
using namespace std;

// constructor 
Brick::Brick( int xposition, int yposition, const int	height, const int width, int hitsToDestroy, int r, int g, int b, int a)
	: GameElement(xposition, yposition, height, width), _r(r), _g(g), _b(b), _a(a) {
	setHitsToDestroy(hitsToDestroy);
}

void Brick::draw(Window *window_brick) const {
	SDL_Rect brick_draw = { xposition, yposition, width, height };
	if (bricks) {
		SDL_RenderCopy(window_brick->_renderer, bricks, nullptr, &brick_draw);
	}
	else {
		SDL_SetRenderDrawColor(window_brick->_renderer, _r, _g, _b, _a);
		SDL_RenderFillRect(window_brick->_renderer, &brick_draw);
		//std::cout << xposition << std::endl;
	}
}

void Brick::setHitsToDestroy(int hitsToDestroy) {
	hits = hitsToDestroy;
}

int Brick::getHitsToDestroy() {
	return hits;
}



// return a string representation of Brick's information 
string Brick::toString() const {
	return "0";
}