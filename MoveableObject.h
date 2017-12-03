#ifndef MoveableObject_H
#define MoveableObject_H

#include <string> // C++ standard string class
#include "GameElement.h"


class MoveableObject : public GameElement {
public:
	MoveableObject( int = 0, int = 0, const int = 0, const int = 0, double = 0.0, double = 0.0 );
	virtual ~MoveableObject() = default; // virtual destructor

	void setXSpeed(double);
	void setYSpeed(double);

	double getXPosition();
	double getYPosition();
	double getXSpeed();
	double getYSpeed();


	virtual std::string toString() const override;
	virtual double move();

protected:
	double xpos;
	double ypos;
	double xspe;
	double yspe;
};

#endif // MoveableObject_H
