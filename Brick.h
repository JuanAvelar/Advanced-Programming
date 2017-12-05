#ifndef BRICK_H
#define BRICK_H

#include <string> // C++ standard string class
#include "GameElement.h" 

class Brick : public GameElement, public Window {
public:
	Brick(const Window &window, int xposition, int yposition, const int	height, const int width, int hitsToDestroy, int r, int g, int b, int a);
	virtual ~Brick() = default; // virtual destructor

	void setHitsToDestroy(int);
	int getHitsToDestroy();

	void Brick::draw() const;

	virtual std::string toString() const override;

private:
	int hitsToDestroy;
	int hits;
	int _r, _g, _b, _a;
	SDL_Texture *bricks = nullptr;
};

#endif // Brick_H
