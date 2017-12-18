#ifndef MoveableObject_H
#define MoveableObject_H

#include <string> // C++ standard string class
#include "GameElement.h"


class MoveableObject : public GameElement {
public:
	MoveableObject(int xposition, int yposition, const int height, const int width, double xdirection, double ydirection, double speed);
	virtual ~MoveableObject() = default; // virtual destructor

	void setXSpeed(double);
	void setYSpeed(double);

	double getXPosition();
	double getYPosition();
	double getXSpeed();
	double getYSpeed();

	virtual std::string toString() const override;
	virtual void move(GameElement *right_wall, GameElement *left_wall) = 0;

	double _xdirection;
	double _ydirection;

protected:

	double _speed = 0;
};

#endif // MoveableObject_H
