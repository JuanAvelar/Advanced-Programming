#include "Wall.h"
#include "MoveableObject.h"
#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

// wall side can be either "up", "down", "right", "left"

// constructor 
Wall::Wall(const Window window, int xposition, int yposition, const int	height, const int width, Wall_type wallSide, int r, int g, int b, int a)
	:Window(window), GameElement(xposition, yposition, height, width)//, _r(r), _g(g), _b(b), _a(a) 
{
	//setWallSide(wallSide);
	std::cout << "aqui esta el error\n";
}

//void Wall::draw() const {
//	SDL_Rect fixed_wall = { xposition, yposition, width, height };
//	if (game_wall) {
//		SDL_RenderCopy(_renderer, game_wall, nullptr, &fixed_wall);
//	}
//	else {
//		SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
//		SDL_RenderFillRect(_renderer, &fixed_wall);
//	}
//}

void Wall::setWallSide(Wall_type wallSide) {
	//wall = wallSide;
}

Wall::Wall_type Wall::getWallSide() {
	return wall;
}

// return a string representation of Brick's information 
string Wall::toString() const {
	return "0";
	//...
}


MoveableObject Wall::bounceOnObject(MoveableObject ball) {
	//change ball ...
	Wall_type side = this->getWallSide();
	double xdir, ydir;
	switch (side)
	{
	case left: //left
			   //invert the xdirection of the movement
		xdir = ball.getXDirection();
		ball.setXDirection(-xdir);
		break;
	case right: //right
				//invert the xdirection of the movement
		xdir = ball.getXDirection();
		ball.setXDirection(-xdir);
		break;
	case up: //top
			 //invert the xdirection of the movement
		ydir = ball.getYDirection();
		ball.setYDirection(-ydir);
		break;
	case down: //bottom
			   //invert the xdirection of the movement
		ydir = ball.getYDirection();
		ball.setYDirection(-ydir);
		break;
	default:
		break;
	}


	return ball;
}