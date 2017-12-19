#include "MoveableObject.h"
using namespace std;

/**MovableObject constructor*/
MoveableObject::MoveableObject( int xposition, int yposition, const int height, const int width, double xdirection, double ydirection, double speed)
	: GameElement(xposition, yposition, height, width) {
}

/**Setting speeds and directions of movable objects*/
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

// return a string representation of Brick's information 
/*string MoveableObject::toString() const {
	return "0";
};*/
