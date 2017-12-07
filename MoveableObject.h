#pragma once
#ifndef MoveableObject_H
#define MoveableObject_H

#include "GameElement.h"


class MoveableObject : public GameElement {
public:
	MoveableObject(int xposition, int yposition, const int height, const int width, double xdirection, double ydirection, double speed);
	virtual ~MoveableObject() = default; // virtual destructor

	void setXDirection(double);
	void setYDirection(double);
	void setSpeed(double);

	double getXDirection();
	double getYDirection();
	double getSpeed();


	virtual void move();

protected:
	double _xdirection = 0;
	double _ydirection = 0;
	double _speed = 0;
};

#endif // MoveableObject_H
