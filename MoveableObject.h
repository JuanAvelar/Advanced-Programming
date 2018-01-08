#ifndef MoveableObject_H
#define MoveableObject_H
#include "GameElement.h"


/**This class leaves an inheritance to all objects that move (ball, platform)*/
class MoveableObject : public GameElement {
public:
	/**Constructor of the movable object (not really used)*/
	MoveableObject(int xposition, int yposition, const int height, const int width);
	/**Virtual Destructor (not really used)*/
	virtual ~MoveableObject() = default; // virtual destructor
	/**Move function used to manage the ball and platform motions inside the boundaries set*/
	virtual void move(GameElement *right_wall, GameElement *left_wall) = 0;

public:
	/**X Direction in which game objects should move in terms of a vector, form 0 to 1*/
	double _xdirection;
	/**Y Direction in which game objects should move in terms of a vector, form 0 to 1*/
	double _ydirection;
	/**Speed of the moving object, 0 or 1, Warning: never different than these two values*/
	double _speed;
};
#endif //MoveableObject_H
