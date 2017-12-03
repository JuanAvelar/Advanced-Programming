#include "MoveableObject.h"
using namespace std;

// constructor
MoveableObject::MoveableObject( int xposition, int yposition, const int height, const int width, double xspeed, double yspeed)
	: GameElement(xposition, yposition, height, width) {
}

void MoveableObject::setXSpeed(double xspeed) {
	xspe = xspeed;
}

void MoveableObject::setYSpeed(double yspeed) {
	yspe = yspeed;
}

double MoveableObject::getXPosition() {
	return xpos;
}

double MoveableObject::getYPosition() {
	return ypos;
}

double MoveableObject::getXSpeed() {
	return xspe;
}

double MoveableObject::getYSpeed() {
	return yspe;
}

// return a string representation of Brick's information 
string MoveableObject::toString() const {
	return "0";
};

//virtual function move, has to be defined for the child classes
double MoveableObject::move() {
	return 0;
};

