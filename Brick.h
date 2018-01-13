#ifndef Brick_H
#define Brick_H
#include "Window.h"
#include "GameElement.h" 
#include "Ball.h"
/**Brick generates a brick and manages functions accordingly */
class Brick : public GameElement {
public:
	Brick( int xposition, int yposition, const int	height, const int width, int hitsToDestroy, Uint8 r, Uint8 g, Uint8 b, Uint8 a, bool powerups);
	~Brick(); // virtual destructor
	
	virtual void draw(Window *window_brick) const;

	GameElement::ElementDestroyed Bounce(GameElement *ball);

private:
	/**Hits it takes to delete each break*/
	int hits;
};

#endif // Brick_H