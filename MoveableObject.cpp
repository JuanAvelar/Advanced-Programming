#include "MoveableObject.h"
using namespace std;

// constructor
MoveableObject::MoveableObject( int xposition, int yposition, const int height, const int width, double xdirection, double ydirection, double speed)
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

// return a string representation of Brick's information 
string MoveableObject::toString() const {
	return "0";
};

//function to move the ball, xposd and yposd are double for the rounding
void MoveableObject::move(GameElement *right_wall, GameElement *left_wall) {

	if (_speed != 0) {
		if (xposition > left_wall->xposition + left_wall->width - 2 && _xdirection < 0) {
			xpos += _xdirection*_speed;
			ypos += _ydirection*_speed;
			xposition = int(xpos);
			yposition = int(ypos);
		}
		else if  (xposition + getWidth() < right_wall->xposition + right_wall->width && _xdirection > 0) {
			xpos += _xdirection*_speed;
			ypos += _ydirection*_speed;
			xposition = int(xpos);
			yposition = int(ypos);
		}
	}
	else {
		xpos = double(xposition);
		ypos = double(yposition);
	}
	//create the move function --> determined by userinput which we get in the controller
	//return new position
}

