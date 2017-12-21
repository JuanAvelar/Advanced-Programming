#include "MoveableObject.h"
using namespace std;

// constructor
MoveableObject::MoveableObject( int xposition, int yposition, const int height, const int width)
	: GameElement(xposition, yposition, height, width) {
}

void MoveableObject::setXSpeed(double xspeed) {
	_xdirection = xspeed;
}

void MoveableObject::setYSpeed(double yspeed) {
	_ydirection = yspeed;
}

double MoveableObject::getXPosition() {
	return xposition;
}

double MoveableObject::getYPosition() {
	return yposition;
}

double MoveableObject::getXSpeed() {
	return _xdirection*_speed;
}

double MoveableObject::getYSpeed() {
	return _ydirection*_speed;
}
