#include "Platform.h"
#include "Ball.h"
#include <SDL2/SDL_image.h>
using namespace std;


/**Constructor of the platform using an image, also used for the start button.*/
Platform::Platform(const Window &window, GameElement::Size size, const std::string &image_path)
	: MoveableObject(xposition, yposition, height, width) {
	//loading of the image
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

	//initial directions are 0, speed is constant
	_xdirection = 0;
	_ydirection = 0;
	_speed = 1.0;


	//switch to use different sizes (small is standard platform size, big is used for the start button)
	switch (size) {
	case small:
		height = 10;
		width = 100;
		break;
	case medium:
		height = 10;
		width = 200;
		break;
	case big:
		height = 300;
		width = 300;
		xposition = 350;
		yposition = 150;
		break;
	};
}

/**Standard destructor of the platform class*/
Platform::~Platform() {
SDL_DestroyTexture(Possesed_image); //this is only for the images
std::cout << "Platform is being destroyed\n";
}

/**Function that draws the platform into the SDL window*/
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


/**Function that implements the keyboard input for movement of the platform. Key pressdown sets a direction of the platform (left or right) and key release resets the direction to 0.*/
void Platform::keyInput(SDL_Event &event) {
	//Key is pressed
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
	//Key is released
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

/**Function that evaluates when the platform is hit by the ball and sets a new direction according to where on the platform it is hit (left side = left, right side = right, middle is straight up)*/
GameElement::ElementDestroyed Platform::Bounce(GameElement * ball) {
	Ball *lower_inh_ptr = dynamic_cast<Ball*> (ball);//lower inheritance pointer of type ball
	//if the ball hits the top, output direction will depend on the impact position

	//evaluate when the ball hits the platform top
	if ((ball->yposition + ball->height > this->yposition && ball->yposition + ball->height < this->yposition + 2 || lower_inh_ptr->_speed == 0) &&
		ball->xposition + ball->width > this->xposition && ball->xposition < this->xposition + this->width 
		)
	{

		//remap values form left to right edge of platform to values for xdir between -0.9 and 0.9
		double collisionPoint = (-0.9 + 1.8 * (((double)ball->xposition + (double)ball->width  - (double)this->xposition) / ((double)width+(double)ball->width)));
		
		//set the new directions for the ball
		lower_inh_ptr->_xdirection = collisionPoint;
		//set the y direction based on the total direction length being 1 (pythagoras)
		lower_inh_ptr->_ydirection = -sqrt(1 - pow(collisionPoint, 2));
	}
	return GameElement::destroynothing;
}

/**Function that looks at the direction of the platform and moves it accordingly.*/
void Platform::move(GameElement *right_wall, GameElement *left_wall) {
	if (xposition > left_wall->xposition + right_wall->width && _xdirection < 0) {
		xposition -= 1;
	}
	if (xposition+width < right_wall->xposition && _xdirection > 0) {
		xposition += 1;
	}

}