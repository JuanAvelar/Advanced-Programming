#include "Brick.h"
#include <iostream>
#include "Window.h"
#include <sstream>
using namespace std;

/**Constructor  of Brick*/
Brick::Brick( int xposition, int yposition, const int	height, const int width, int hitsToDestroy, int r, int g, int b, int a)
	: GameElement(xposition, yposition, height, width), _r(r), _g(g), _b(b), _a(a) {
	hits = hitsToDestroy;
}
/**Destructor of Brick*/
Brick::~Brick() {
	std::cout << "Brick is being destroyed\n";
}
/**Brick Draw funtion to set postion and characteristic sof ball*/
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
/**Bounce function of brick that overrides the virtual function of GameElement*/
GameElement::ElementDestroyed Brick::Bounce(GameElement * ball) {
	Ball *lower_inh_ptr = dynamic_cast<Ball*> (ball);//lower inheritance pointer of type ball

	//first we need to check if the ball hits the side or the top/bottom
	if (hits > 0) {
		/**If ball hits sides: --> then change the xdirection. Also remove a life of the brick.*/
		if (ball->getXLocation() + ball->getWidth() > this->getXLocation() && ball->getXLocation() + ball->getWidth() < this->getXLocation() + 0.05*this->getWidth() &&
			ball->getYLocation() + ball->getHeight() > this->getYLocation() && ball->getYLocation() < this->getYLocation() + this->getHeight()
			|| ball->getXLocation() < this->getXLocation() + this->getWidth() && ball->getXLocation() > this->getXLocation() + 0.95*this->getWidth() &&
			ball->getYLocation() + ball->getHeight() > this->getYLocation() && ball->getYLocation() < this->getYLocation() + this->getHeight()) {
			lower_inh_ptr->setXDirection(-lower_inh_ptr->getXDirection());
			this->removeBrickLife();
		}
		/**If ball hits the top/bottom: --> then change the ydirection. Also remove a life of the brick.*/

		if (ball->getYLocation() + ball->getHeight() > this->getYLocation() && ball->getYLocation() + ball->getHeight() < this->getYLocation() + 0.05*this->getHeight() &&
			ball->getXLocation() + ball->getWidth() > this->getXLocation() && ball->getXLocation() < this->getXLocation() + this->getWidth()
			||
			ball->getYLocation() < this->getYLocation() + this->getHeight() && ball->getYLocation() > this->getYLocation() + 0.95*this->getHeight() &&
			ball->getXLocation() + ball->getWidth() > this->getXLocation() && ball->getXLocation() < this->getXLocation() + this->getWidth()) {

			double ydir = lower_inh_ptr->getYDirection();
			lower_inh_ptr->setYDirection(-ydir);
			this->removeBrickLife();
		}
		return GameElement::destroynothing;
	}
	else {
		delete this;
		return GameElement::destroybrick;
	}
}

void Brick::removeBrickLife() {
	hits--;
}

// return a string representation of Brick's information 
/*string Brick::toString() const {
	return "0";
}*/