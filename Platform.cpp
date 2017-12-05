#include "Platform.h"

using namespace std;

// constructor
Platform::Platform(const Window &window, int xposition, int yposition, const int height, const int width,int r, int g, int b, int a)
	:Window(window), MoveableObject( xposition, yposition, height, width, _xdirection, _ydirection, speed) , _r(r), _g(g), _b(b), _a(a) {
	//... no extra attributes to include?
}

/*Platform::~Platform() {
	//SDL_DestroyTexture(platform);
}*/

void Platform::draw() const {
	SDL_Rect platform_draw = { xposition, yposition, width, height };
	if (platform) {
		SDL_RenderCopy(_renderer, platform, nullptr, &platform_draw);
	}
	else {
		SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
		SDL_RenderFillRect(_renderer, &platform_draw);
	}
}

// return a string representation of Moveable Object's information --> implements abstract class function
string Platform::toString() const {
	return "0";
	// make string output
}

//function move --> implements abstract class function
double Platform::move() {
	return 0;
	//create the move function --> determined by userinput which we get in the controller
}
