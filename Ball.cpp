#include "Ball.h"
#include <SDL2/SDL_image.h>

using namespace std;

/** Constructor of the ball class*/
Ball::Ball(const Window &window, GameElement::Size size, const std::string &image_path)
	: MoveableObject(xposition, yposition, height, width) {
	//loading of the image provided in the input
	auto surface = IMG_Load(image_path.c_str());
	if (!surface) {
		std::cerr << "Failed to create surface.\n";
	}
	Possesed_image = SDL_CreateTextureFromSurface(window._renderer, surface);
	if (!Possesed_image) {
		std::cerr << "Failed to create texture\n";
	}
	SDL_FreeSurface(surface);
	
	//switch for multiple sizes of the ball, standard is small
	switch (size) {
	case small:
		height = 20;
		width = 20;
		break;
	case medium:
		height = 60;
		width = 60;
		break;
	case big:
		height = 120;
		width = 120;
		break;
	};
	xposition = 500+30; //initial offcentered platform position
	yposition = 500-height; //initial position (on the platform)

	//initial directions of the ball
	_xdirection = 0.0;
	_ydirection = 1.0;
	_speed = 0.0;
}

/**Standard destructor for the ball class*/
Ball::~Ball() {
	SDL_DestroyTexture(Possesed_image);
	std::cout << "Ball is being destroyed\n";
}

/**Draws the ball object with its image*/
void Ball::draw(Window *ball_window) const {
	SDL_Rect ball = { xposition, yposition, width, height };
	if (Possesed_image) {
		SDL_RenderCopy(ball_window->_renderer, Possesed_image, nullptr, &ball);
	}
	else {
		SDL_SetRenderDrawColor(ball_window->_renderer, _r, _g, _b, _a);
		SDL_RenderFillRect(ball_window->_renderer, &ball);
	}
	if(_speed == 0){
		SDL_SetRenderDrawColor(ball_window->_renderer, Uint8(255), Uint8(255), Uint8(255), Uint8(255));
		SDL_RenderDrawLine(ball_window->_renderer, int(xposition+width/2), int(yposition+height/2), int(xposition+width/2+_xdirection*50), int(yposition+height/2+_ydirection*50));
		//std::cout << _xdirection << std::endl;
	}
}

/**Function to move the ball. It changes position towards the current directions and saves its location in a double variable. That double gets rounded each iteration to get its integer position.*/
void Ball::move(GameElement *right_wall, GameElement *left_wall) {

	if (_speed != 0) {
		if (xposition > left_wall->xposition + left_wall->width - 2 && xposition < right_wall->xposition) {
			xpos += _xdirection*_speed;
			ypos += _ydirection*_speed;
			xposition = int(xpos);
			yposition = int(ypos);
		}
	}
	else {
		xpos = double(xposition);
		ypos = double(yposition);
	}
}

/**Function that returns destroynothing.*/
GameElement::ElementDestroyed Ball::Bounce(GameElement * ball) {
	(void)ball;
	return GameElement::destroynothing;
}

void Ball::keyInput(SDL_Event &event) {
	
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
		case SDLK_UP:
			_speed = 1.0;
			break;
		default:
			break;
		}
	}
}