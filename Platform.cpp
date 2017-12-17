#include "Platform.h"
#include "Window.h"
#include "Ball.h"
#include <iostream>
#include <sstream>
#include <SDL2/SDL_image.h>
using namespace std;

// constructor
Platform::Platform(const Window &window, GameElement::Color color)
	: MoveableObject(xposition, yposition, height, width, _xdirection, _ydirection, _speed) {
	//... no extra attributes to include?
	int *ptr;
	ptr = set_color_rgba(color);
	_r = *ptr;
	_g = *(ptr + 1);
	_b = *(ptr + 2);
	_a = *(ptr + 3);
	xposition = 500;
	yposition = 500;
	height = 20;
	width = 100;
}

// constructor
Platform::Platform(const Window &window, GameElement::Size size, const std::string &image_path)
	: MoveableObject(xposition, yposition, height, width, _xdirection, _ydirection, _speed) {
	//... no extra attributes to include?
	auto surface = IMG_Load(image_path.c_str());
	if (!surface) {
		std::cerr << "Failed to create surface.\n";
	}
	platform = SDL_CreateTextureFromSurface(window._renderer, surface);
	if (!platform) {
		std::cerr << "Failed to create texture\n";
	}
	SDL_FreeSurface(surface);
	xposition = 500;
	yposition = 500;
	switch (size) {
	case small:
		height = 20;
		width = 100;
		break;
	case medium:
		height = 20;
		width = 130;
		break;
	case big:
		height = 20;
		width = 160;
		break;
	};
}

Platform::~Platform() {
SDL_DestroyTexture(platform); //this is only for the images
std::cout << "Platform is being destroyed\n";
}

void Platform::draw(Window *platform_window) const {
	SDL_Rect platform_draw = { xposition, yposition, width, height };
	if (platform) {
		SDL_RenderCopy(platform_window->_renderer, platform, nullptr, &platform_draw);
	}
	else {
		SDL_SetRenderDrawColor(platform_window->_renderer, _r, _g, _b, _a);
		SDL_RenderFillRect(platform_window->_renderer, &platform_draw);
	}
}

// return a string representation of Moveable Object's information --> implements abstract class function
string Platform::toString() const {
	return "0";
	// make string output
}

//function move --> implements abstract class function
void Platform::keyInput(SDL_Event &event, GameElement *right_wall, GameElement *left_wall) {
	switch (event.type) {

	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_LEFT:
			if (xposition > left_wall->getXLocation()+10) {
				xposition -= 50;
			}
			break;
		case SDLK_RIGHT:
			if (xposition < right_wall->getXLocation()-getWidth()) {
				xposition += 50;
			}
			break;
		}
	default:
		break;
	}

	//create the move function --> determined by userinput which we get in the controller
}

bool Platform::Bounce(GameElement * ball, bool *Game_lost) {
	Ball *lower_inh_ptr = dynamic_cast<Ball*> (ball);//lower inheritance pointer of type ball

	//if ball hits the top, output direction will totally depend on the impact position
	//if ball hits the side, ball bounces of with same angle

	//ball hits top: --> then change the ydirection
	if (ball->getYLocation() + ball->getHeight() > this->getYLocation() && ball->getYLocation() + ball->getHeight() < this->getYLocation() + this->getHeight() &&
		ball->getXLocation() + ball->getWidth() > this->getXLocation() && ball->getXLocation() < this->getXLocation() + this->getWidth())//|| ball.getXLocation() > this->getXLocation() + this->getWidth()) 
	{

		//remap values form left to right edge of platform to values for xdir between -0.9 and 0.9
		double collisionPoint = (-0.9 + 1.8 * (((double)ball->getXLocation() + 0.5 * (double)ball->getWidth() - (double)this->getXLocation()) / (double)getWidth()));
		//output = output_start + ((output_end - output_start) / (input_end - input_start)) * (input - input_start)

		//set the new directions for the ball
		lower_inh_ptr->setXDirection(collisionPoint);
		//set the y direction based on the total direction length being 1
		lower_inh_ptr->setYDirection(-sqrt(1 - pow(collisionPoint, 2)));
	}
	return 0;
}
