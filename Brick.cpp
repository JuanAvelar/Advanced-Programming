#include "Brick.h"
#include "Window.h"
using namespace std;

// constructor 
Brick::Brick( int xposition, int yposition, const int	height, const int width, int hitsToDestroy, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
	: GameElement(xposition, yposition, height, width){
	hits = hitsToDestroy;
	_r = r;
	_g = g;
	_b = b;
	_a = a;
	Possesed_image = nullptr;
}

Brick::~Brick() {
	std::cout << "Brick is being destroyed\n";
}

void Brick::draw(Window *window_brick) const {
	SDL_Rect brick_draw = { xposition, yposition, width, height };
	if (Possesed_image) {
		SDL_RenderCopy(window_brick->_renderer, Possesed_image, nullptr, &brick_draw);
	}
	else {
		SDL_SetRenderDrawColor(window_brick->_renderer, _r, _g, _b, _a);
		SDL_RenderFillRect(window_brick->_renderer, &brick_draw);
	}
}
/** This function will check the point of colission of the ball with a brick. Depending on this point of colission (which will be on a ring of 1 pixel wide around the brick) the x direction, y direction or both will change*/
GameElement::ElementDestroyed Brick::Bounce(GameElement * ball) {
	Ball *lower_inh_ptr = dynamic_cast<Ball*> (ball);//lower inheritance pointer of type ball

	//first we need to check if the ball hits the side or the top/bottom
	if (hits > 0) {

		//ball hits sides: --> then change the xdirection. Also remove a life of the brick.
		if (ball->xposition + ball->width > this->xposition && ball->xposition + ball->width < this->xposition + 2 && //the 2 is used to set a 1 pixel boundary around the brick (1<2)
			ball->yposition + ball->height > this->yposition && ball->yposition < this->yposition + this->height
			|| ball->xposition < this->xposition + this->width && ball->xposition > this->xposition + this->width-2 &&
			ball->yposition + ball->height > this->yposition && ball->yposition < this->yposition + this->height) {
			
			lower_inh_ptr->_xdirection =-lower_inh_ptr->_xdirection; //flip x direction
			hits--;
		}
		// ball hits the top/bottom: --> then change the ydirection. Also remove a life of the brick.

		if (ball->yposition + ball->height > this->yposition && ball->yposition + ball->height < this->yposition + 2 &&
			ball->xposition + ball->width > this->xposition && ball->xposition < this->xposition + this->width
			||
			ball->yposition < this->yposition + this->height && ball->yposition > this->yposition + this->height-2 &&
			ball->xposition + ball->width > this->xposition && ball->xposition < this->xposition + this->width) {

			lower_inh_ptr->_ydirection = -lower_inh_ptr->_ydirection; //flip y direction
			hits--;
		}
		return GameElement::destroynothing;
	}
	else {
		delete this;
		return GameElement::destroybrick;
	}
}
