#ifndef Brick_H
#define Brick_H
#include "Window.h"
#include "GameElement.h" 
#include "Ball.h"

class Brick : public GameElement {
public:
	Brick( int xposition, int yposition, const int	height, const int width, int hitsToDestroy, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	~Brick(); // virtual destructor

	virtual void draw(Window *window_brick) const;

	GameElement::ElementDestroyed Bounce(GameElement *ball);

private:
	int hits;
};

#endif // Brick_H