#ifndef MoveableObject_H
#define MoveableObject_H
#include "GameElement.h"



class MoveableObject : public GameElement {
public:
	MoveableObject(int xposition, int yposition, const int height, const int width);
	virtual ~MoveableObject() = default; // virtual destructor

	virtual void move(GameElement *right_wall, GameElement *left_wall) = 0;

public:
	double _xdirection;
	double _ydirection;
	double _speed = 0;
};

#endif // MoveableObject_H
