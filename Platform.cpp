#include "Platform.h"
#include "Window.h"
#include "Ball.h"
#include "Controller.h"
#include <SDL2/SDL_image.h>
using namespace std;

// constructor
Platform::Platform(SDL_Color color)
	: MoveableObject(xposition, yposition, height, width) {	
	_r = color.r;
	_g = color.g;
	_b = color.b;
	_a = color.a;
	xposition = 500;
	yposition = 500;
	height = 10;
	width = 100;
	_xdirection = 0;
	_ydirection = 0;
	_speed = 1.0;
	xpos = double(xposition);
	ypos = double(yposition);
	Possesed_image = nullptr;
}

// constructor
Platform::Platform(const Window &window, GameElement::Size size, const std::string &image_path)
	: MoveableObject(xposition, yposition, height, width) {
	//... no extra attributes to include?
	auto surface = IMG_Load(image_path.c_str());
	if (!surface) {
		std::cerr << "Failed to create surface.\n";
	}
	Possesed_image = SDL_CreateTextureFromSurface(window._renderer, surface);
	if (!Possesed_image) {
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
		height = 300;
		width = 300;
		xposition = 350;
		yposition = 150;
		break;
	};
}

Platform::~Platform() {
SDL_DestroyTexture(Possesed_image); //this is only for the images
std::cout << "Platform is being destroyed\n";
}

void Platform::draw(Window *platform_window) const {
	SDL_Rect platform_draw = { xposition, yposition, width, height };
	if (Possesed_image) {
		SDL_RenderCopy(platform_window->_renderer, Possesed_image, nullptr, &platform_draw);
	}
	else {
		SDL_SetRenderDrawColor(platform_window->_renderer, _r, _g, _b, _a);
		SDL_RenderFillRect(platform_window->_renderer, &platform_draw);
	}
}


//function move --> implements abstract class function
void Platform::keyInput(SDL_Event &event) {
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
		case SDLK_LEFT:
			_xdirection = -1.0;
			break;
		case SDLK_RIGHT:
			_xdirection = 1.0;
			break;
		default:
			break;
		}
	}
	if (event.type == SDL_KEYUP){
		switch (event.key.keysym.sym) {
		case SDLK_LEFT:
			if (_xdirection < 0) {
				_xdirection = 0;
			}
			break;
		case SDLK_RIGHT:
			if (_xdirection > 0) {
				_xdirection = 0;
			}
			break;
		default:
			break;
		}
	
	}

}

GameElement::ElementDestroyed Platform::Bounce(GameElement * ball) {
	Ball *lower_inh_ptr = dynamic_cast<Ball*> (ball);//lower inheritance pointer of type ball
	//if ball hits the top, output direction will totally depend on the impact position
	//if ball hits the side, ball bounces of with same angle

	//ball hits top: --> then change the ydirection
	if ((ball->yposition + ball->height > this->yposition && ball->yposition + ball->height < this->yposition + 2 || lower_inh_ptr->_speed == 0) &&
		ball->xposition + ball->width > this->xposition && ball->xposition < this->xposition + this->width 
		)
	{

		//remap values form left to right edge of platform to values for xdir between -0.9 and 0.9
		double collisionPoint = (-0.9 + 1.8 * (((double)ball->xposition + (double)ball->width  - (double)this->xposition) / ((double)width+(double)ball->width)));
		//output = output_start + ((output_end - output_start) / (input_end - input_start)) * (input - input_start)

		//set the new directions for the ball
		lower_inh_ptr->_xdirection = collisionPoint;
		//set the y direction based on the total direction length being 1
		lower_inh_ptr->_ydirection = -sqrt(1 - pow(collisionPoint, 2));
	}
	return GameElement::destroynothing;
}

void Platform::move(GameElement *right_wall, GameElement *left_wall) {
	if (xposition > left_wall->xposition + right_wall->width && _xdirection < 0) {
		xposition -= 1;
	}
	if (xposition+width < right_wall->xposition && _xdirection > 0) {
		xposition += 1;
	}

}