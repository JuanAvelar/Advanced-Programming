#include "Wall.h"
using namespace std;

// wall side can be either "up", "down", "right", "left"

// constructor 
Wall::Wall(const Window window, int xposition, int yposition, const int	height, const int width, const Wall_type wallSide, int r, int g, int b, int a)
	: Window(window),GameElement(xposition, yposition, height, width) {
	setWallSide(wallSide);
}

void Wall::setWallSide(Wall_type wallSide) {
	wall = wallSide;
}

string Wall::getWallSide() {
	return wall;
}

// return a string representation of Brick's information 
string Wall::toString() const {
	return "0";
	//...
}

