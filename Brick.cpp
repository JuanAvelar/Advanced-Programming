#include "Brick.h"
#include "MoveableObject.h"
#include <iostream>
using namespace std;

// constructor 
Brick::Brick(const Window &window, int xposition, int yposition, const int	height, const int width, int hitsToDestroy, int r, int g, int b, int a)
	:Window(window), GameElement(xposition, yposition, height, width), _r(r), _g(g), _b(b), _a(a) {
	hits = hitsToDestroy;
}

void Brick::draw() const {
	if (hits > 0) {
		SDL_Rect brick_draw = { xposition, yposition, width, height };
		if (bricks) {
			SDL_RenderCopy(_renderer, bricks, nullptr, &brick_draw);
		}
		else {
			SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
			SDL_RenderFillRect(_renderer, &brick_draw);
			//std::cout << xposition << std::endl;
		}
	}
}

// *called upon to display the hits to destroy
int Brick::getHitsToDestroy() {
	return hits;
}

// *reduces the brick life (used if a brick is hit)
void Brick::removeBrickLife() {
	hits--;
}

//*function to make the brick bounce with a lot of stuff in it. The ball will reverse its direction if it is within 5% of the boundary, 
// so at corners it will reverse both x and y direction
void Brick::brickBounce(MoveableObject &ball) {
	//first we need to check if the ball hits the side or the top/bottom
	if (hits > 0) {
		//ball hits sides: --> then change the xdirection. Also remove a life of the brick.
		if (ball.getXLocation() + ball.getWidth() > this->getXLocation() && ball.getXLocation() + ball.getWidth() < this->getXLocation() + 0.05*this->getWidth() &&
			ball.getYLocation() + ball.getHeight() > this->getYLocation() && ball.getYLocation() < this->getYLocation() + this->getHeight()
			|| ball.getXLocation() < this->getXLocation() + this->getWidth() && ball.getXLocation() > this->getXLocation() + 0.95*this->getWidth() &&
			ball.getYLocation() + ball.getHeight() > this->getYLocation() && ball.getYLocation() < this->getYLocation() + this->getHeight()) {
			ball.setXDirection(-ball.getXDirection());
			this->removeBrickLife();
		}
		// ball hits the top/bottom: --> then change the ydirection. Also remove a life of the brick.

		if (ball.getYLocation() + ball.getHeight() > this->getYLocation() && ball.getYLocation() + ball.getHeight() < this->getYLocation() + 0.05*this->getHeight() &&
			ball.getXLocation() + ball.getWidth() > this->getXLocation() && ball.getXLocation() < this->getXLocation() + this->getWidth()
			||
			ball.getYLocation() < this->getYLocation() + this->getHeight() && ball.getYLocation() > this->getYLocation() + 0.95*this->getHeight() &&
			ball.getXLocation() + ball.getWidth() > this->getXLocation() && ball.getXLocation() < this->getXLocation() + this->getWidth()) {

			double ydir = ball.getYDirection();
			ball.setYDirection(-ydir);
			this->removeBrickLife();
		}
		else {}
	}
	else {}

}


