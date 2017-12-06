#include "MoveableObject.h"
using namespace std;

// constructor
MoveableObject::MoveableObject(int xposition, int yposition, const int height, const int width, double xdirection, double ydirection, double speed)
	: GameElement(xposition, yposition, height, width) {
	setXDirection(xdirection);
	setYDirection(ydirection);
	setSpeed(speed);
}

void MoveableObject::setXDirection(double xdirection) {
	_xdirection = xdirection;
}

void MoveableObject::setYDirection(double ydirection) {
	_ydirection = ydirection;
}


double MoveableObject::getXDirection() {
	return _xdirection;
}

double MoveableObject::getYDirection() {
	return _ydirection;
}

double MoveableObject::getSpeed() {
	return _speed;
}

void MoveableObject::setSpeed(double speed) {
	_speed = speed;
}

// return a string representation of Brick's information 
string MoveableObject::toString() const {
	return "0";
};

//virtual function move, has to be defined for the child classes
double MoveableObject::move() {
	return 0;
};


MoveableObject MoveableObject::bounceOnObject(MoveableObject ball) {
	//change ball ...
	return ball;
}