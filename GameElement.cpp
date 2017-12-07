#include <sstream>
#include <iostream>
#include "GameElement.h"
#include <SDL2/SDL_image.h>


using namespace std;

// constructor
GameElement::GameElement(int xpos, int ypos, const int h, const int w)
	: xposition(xpos), yposition(ypos), height(h), width(w) {}

//get height of element
int GameElement::getHeight() const {
	return height;
}

//get width of element
int GameElement::getWidth() const {
	return width;
}


//return the current location of the element (x an y seperately)
int GameElement::getXLocation() {
	return xposition;
}

int GameElement::getYLocation() {
	return yposition;
}

