#pragma once

#ifndef BRICK_H
#define BRICK_H

#include "GameElement.h" 
#include "MoveableObject.h"
#include "SDL2/SDL_image.h"

class Brick : public GameElement, public Window {
public:
	Brick(const Window &window, int xposition, int yposition, const int	height, const int width, int hitsToDestroy, int r, int g, int b, int a);
	virtual ~Brick() = default; // virtual destructor

	int getHitsToDestroy();

	void Brick::draw() const;
	void removeBrickLife();

	virtual void brickBounce(MoveableObject &ball) ;


private:
	int hitsToDestroy;
	int hits;
	int _r, _g, _b, _a;
	SDL_Texture *bricks = nullptr;
};

#endif // Brick_H