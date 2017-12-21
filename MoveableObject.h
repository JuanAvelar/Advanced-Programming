#ifndef MoveableObject_H
#define MoveableObject_H

#include "GameElement.h"


class MoveableObject : public GameElement {
public:
	MoveableObject(int xposition, int yposition, const int height, const int width);
	virtual ~MoveableObject() = default; // virtual destructor

	void setXSpeed(double);
	void setYSpeed(double);

	double getXPosition();
	double getYPosition();
	double getXSpeed();
	double getYSpeed();

	virtual void move(GameElement *right_wall, GameElement *left_wall) = 0;

	double _xdirection;
	double _ydirection;

public:

	double _speed = 0;
};

#endif // MoveableObject_H
