#include "Wall.h"
using namespace std;

// wall side can be either "up", "down", "right", "left"

// constructor 
Wall::Wall(int xposition, int yposition, const int	height, const int width, const Wall_type wallSide)
	: GameElement(xposition, yposition, height, width) {
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
