#include "MoveableObject.h"
using namespace std;

/**MovableObject constructor*/
MoveableObject::MoveableObject( int xposition, int yposition, const int height, const int width, double xdirection, double ydirection, double speed)
	: GameElement(xposition, yposition, height, width) {
}

/**Setting speeds of movable objects in X direction*/
void MoveableObject::setXSpeed(double xspeed) {
	_xdirection = xspeed;
}
/**Setting speeds of movable objects in Y direction*/
void MoveableObject::setYSpeed(double yspeed) {
	_ydirection = yspeed;
}
/**To get position of movable objects in X direction*/
double MoveableObject::getXPosition() {
	return xposition;
}
/**To get position of movable objects in Y direction*/
double MoveableObject::getYPosition() {
	return yposition;
}
/**Function to get speeds of movable objects in X direction*/
double MoveableObject::getXSpeed() {
	return _xdirection*_speed;
}
/**Function to get speeds of movable objects in Y direction*/
double MoveableObject::getYSpeed() {
	return _ydirection*_speed;
}

// return a string representation of Brick's information 
/*string MoveableObject::toString() const {
	return "0";
};*/
