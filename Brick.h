#ifndef BRICK_H
#define BRICK_H

#include "GameElement.h" 
#include "Ball.h"

class Brick : public GameElement {
public:
	Brick( int xposition, int yposition, const int	height, const int width, int hitsToDestroy, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	~Brick(); // virtual destructor

	virtual void Brick::draw(Window *window_brick) const;

	GameElement::ElementDestroyed Bounce(GameElement *ball);

	void removeBrickLife();

private:
	int hitsToDestroy;
	int hits;
};

#endif // Brick_H