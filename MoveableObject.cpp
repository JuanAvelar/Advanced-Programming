#include "MoveableObject.h"
using namespace std;

// constructor
MoveableObject::MoveableObject( int xposition, int yposition, const int height, const int width, double xspeed, double yspeed)
	: GameElement(xposition, yposition, height, width) {
}

void MoveableObject::setXSpeed(double xspeed) {
	_xspeed = xspeed;
}

void MoveableObject::setYSpeed(double yspeed) {
	_yspeed = yspeed;
}

double MoveableObject::getXPosition() {
	return xposition;
}

double MoveableObject::getYPosition() {
	return yposition;
}

double MoveableObject::getXSpeed() {
	return _xspeed;
}

double MoveableObject::getYSpeed() {
	return _yspeed;
}

// return a string representation of Brick's information 
string MoveableObject::toString() const {
	return "0";
};

//virtual function move, has to be defined for the child classes
double MoveableObject::move() {
	return 0;
};

