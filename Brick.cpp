#include "Brick.h"
#include "MoveableObject.h"
#include <iostream>
using namespace std;

// constructor 
Brick::Brick(const Window &window, int xposition, int yposition, const int	height, const int width, int hitsToDestroy, int r, int g, int b, int a)
	:Window(window), GameElement(xposition, yposition, height, width), _r(r), _g(g), _b(b), _a(a) {
	setHitsToDestroy(hitsToDestroy);
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

void Brick::setHitsToDestroy(int hitsToDestroy) {
	hits = hitsToDestroy;
}

int Brick::getHitsToDestroy() {
	return hits;
}


// return a string representation of Brick's information 
string Brick::toString() const {
	return "0";
}

void Brick::removeBrickLife() {
	hits--;
}


MoveableObject Brick::bounceOnObject(MoveableObject &ball) {
	//first we need to check if the ball hits the side or the top/bottom
	if (hits > 0) {
		//ball hits left side: --> then change the xdirection
		if (ball.getXLocation() + ball.getWidth() > this->getXLocation() && ball.getXLocation() + ball.getWidth() < this->getXLocation() + 0.05*this->getWidth() &&
			ball.getYLocation() + ball.getHeight() > this->getYLocation() && ball.getYLocation() < this->getYLocation() + this->getHeight()
			|| ball.getXLocation() < this->getXLocation() + this->getWidth() && ball.getXLocation() > this->getXLocation() + 0.95*this->getWidth() &&
			ball.getYLocation() + ball.getHeight() > this->getYLocation() && ball.getYLocation() < this->getYLocation() + this->getHeight()) {
			ball.setXDirection(-ball.getXDirection());
			this->removeBrickLife();
		}
		// ball hits the top: --> then change the ydirection

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


	
	

	return ball;
}


bool Brick::isDestructible() {
	return true;
}
