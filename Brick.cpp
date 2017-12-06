#include "Brick.h"
#include "MoveableObject.h"
#include <iostream>
using namespace std;

// constructor 
Brick::Brick(const Window &window, int xposition, int yposition, const int	height, const int width, int hitsToDestroy, int r, int g, int b, int a)
	:Window(window), GameElement(xposition, yposition, height, width), _r(r), _g(g), _b(b), _a(a) {
	setHitsToDestroy(hitsToDestroy);
}

void Brick::draw() const {
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




MoveableObject Brick::bounceOnObject(MoveableObject ball) {
	//first we need to check if the ball hits the side or the top/bottom

	//ball hits side: --> then change the ydirection
	if (ball.getXLocation() + ball.getWidth() < this->getXLocation() ||
		ball.getXLocation() > this->getXLocation() + this->getWidth()) {
		double xdir = ball.getXDirection();
		ball.setYDirection(-xdir);
	}
	//else { //ball hits top/bottom --> change xdirection
	//	double xdir = ball.getXDirection();
	//	ball.setYDirection(-xdir);
	//}

	//this->removeBrickLife();

	return ball;
}


bool Brick::isDestructible() {
	return true;
}
