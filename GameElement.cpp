#include <sstream>
#include <iostream>
#include "GameElement.h"
#include "Controller.h"
#include <SDL2/SDL_image.h>


using namespace std;

/**Constructor of Element object*/
GameElement::GameElement( int xpos, int ypos, const int h, const int w)
	:	 xposition(xpos), yposition(ypos), height(h), width(w) {}

/**Get height of element object*/
int GameElement::getHeight() const {
	return height;
}

/**Get width of element object*/
int GameElement::getWidth() const {
	return width;
}

/**Return the current location of the element (x and y seperately)*/
int GameElement::getXLocation() {
	return xposition;
}

int GameElement::getYLocation() {
	return yposition;
}

/**Function to destroy the game element (Not Implemented)*/
void GameElement::destroyGameElement() {
	
}


// toString GameElements's information
/*string GameElement::toString() const {
	return "0";
}*/
/**Returns a pointer to an array of 4 integers*/
int* GameElement::set_color_rgba(Color color) {
	int _r, _g, _b, _a;
	switch (color) {
	case yellow:
		_r = Yellow().r;
		_g = Yellow().g;
		_b = Yellow().b;
		_a = Yellow().a;
		break;
	case green:
		_r = Green().r;
		_g = Green().g;
		_b = Green().b;
		_a = Green().a;
		break;
	case red:
		_r = Red().r;
		_g = Red().g;
		_b = Red().b;
		_a = Red().a;
		break;
	case blue:
		_r = Blue().r;
		_g = Blue().g;
		_b = Blue().b;
		_a = Blue().a;
		break;
	}
	int array[4] = {_r, _g, _b, _a};
	return (array);
}



