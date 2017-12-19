#ifndef MoveableObject_H
#define MoveableObject_H

#include <string> // C++ standard string class
#include "GameElement.h"

/**Inheritance of MovableObject class from GameElement*/
class MoveableObject : public GameElement {  
public:
	/**Constructor for movable object*/
	MoveableObject(int xposition, int yposition, const int height, const int width, double xdirection, double ydirection, double speed);
	/**virtual destructor of MovableObject*/
	virtual ~MoveableObject() = default; 
	/**Function to set speed of movable objects in X direction*/
	void setXSpeed(double);
	/**Function to set speed of movable objects in Y direction*/
	void setYSpeed(double);
	/**Function to get speeds of movable objects in X direction*/
	double getXPosition();
	/**Function to get speeds of movable objects in Y direction*/
	double getYPosition();
	/**Function to get speeds of movable objects in X direction*/
	double getXSpeed();
	/**Function to get speeds of movable objects in Y direction*/
	double getYSpeed();

	//virtual std::string toString() const override;
	/**Virtual move function*/
	virtual void move(GameElement *right_wall, GameElement *left_wall) = 0;

	double _xdirection;
	double _ydirection;

protected:

	double _speed = 0;
};

#endif // MoveableObject_H
