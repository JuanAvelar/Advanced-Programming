#ifndef BRICK_H
#define BRICK_H

#include <string> // C++ standard string class
#include "GameElement.h" 
#include "Ball.h"

class Brick : public GameElement {
public:
	Brick( int xposition, int yposition, const int	height, const int width, int hitsToDestroy, int r, int g, int b, int a);
	~Brick(); // virtual destructor

	virtual void Brick::draw(Window *window_brick) const;

	GameElement::ElementDestroyed Bounce(GameElement *ball);

	void removeBrickLife();

	virtual std::string toString() const override;

private:
	int hitsToDestroy;
	int hits;
	int _r, _g, _b, _a;
	SDL_Texture *bricks = nullptr;
};

#endif // Brick_H