#include "Wall.h"
#include "MoveableObject.h"
using namespace std;

/**Constructor of the wall class. It has a switch for walls on the upper, down, right and left side.*/ 
Wall::Wall(SDL_Color color, Wall_type wallside)
	: GameElement(xposition, yposition, height, width) {
	switch (wallside) {
	case right:
		xposition = 990;
		yposition = 10;
		height = 580;
		width = 10;
		break;
	case up:
		xposition = 0;
		yposition = 0;
		height = 10;
		width = 1000;
		break;
	case left:
		xposition = 0;
		yposition = 10;
		height = 580;
		width = 10;
		break;
	case down:
		xposition = 0;
		yposition = 590;
		height = 10;
		width = 1000;
		break;
	}

	//sets the rgba values to the color input
	_r = Uint8(color.r);
	_g = Uint8(color.g);
	_b = Uint8(color.b);
	_a = Uint8(color.a);
	
	//stores the pick of the wallside
	wallside_pick = wallside;
	Possesed_image = nullptr;
}

/**Standard destructor for the walls.*/
Wall::~Wall() {
	std::cout << "Wall is being destroyed\n";
	SDL_DestroyTexture(Possesed_image);
}

/**Draws the walls into the SDL window*/
void Wall::draw(Window *window_wall) const {
	SDL_Rect fixed_wall = { xposition, yposition, width, height };
	if (Possesed_image) {
		SDL_RenderCopy(window_wall->_renderer, Possesed_image, nullptr, &fixed_wall);
	}
	else {
		SDL_SetRenderDrawColor(window_wall->_renderer, _r, _g, _b, _a);
		SDL_RenderFillRect(window_wall->_renderer, &fixed_wall);
	}
}

/**Function that evaluates if the ball collides with it and makes the ball change direction if it does.*/
GameElement::ElementDestroyed Wall::Bounce(GameElement * ball) {
	//Dynamic cast to access the ball class.
	MoveableObject *lower_inh_ptr = { dynamic_cast<MoveableObject*> (ball)};
		switch (this->wallside_pick) {
		case Wall::up:
			if (ball->yposition < this->yposition + this->height) {
				lower_inh_ptr->_yflip = true;
			}
			return GameElement::destroynothing;
			break;
		case Wall::left:
			if (ball->xposition < this->xposition + this->width) {
				lower_inh_ptr->_xflip = true;
			}
			return GameElement::destroynothing;
			break;
		case Wall::right:
			if ( ball->xposition >(this->xposition - ball->width)) {
				lower_inh_ptr->_xflip = true;
			}
			return GameElement::destroynothing;
			break;
		case Wall::down:
			if (ball->yposition >(this->yposition - ball->height)) {
				delete ball;
				return GameElement::destroyball;
			}
			else {
				return GameElement::destroynothing;
			}
			break;
		default:
			return GameElement::destroynothing;
		}
		

		
}
