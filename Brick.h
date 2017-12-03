#ifndef BRICK_H
#define BRICK_H

#include <string> // C++ standard string class
#include "GameElement.h" 

class Brick : public GameElement {
public:
	Brick(int = 0, int = 0, const int = 0, const int = 0, int = 0);
	virtual ~Brick() = default; // virtual destructor

	void setHitsToDestroy(int);
	int getHitsToDestroy();

	virtual std::string toString() const override;

private:
	int hitsToDestroy;
	int hits;
};

#endif // Brick_H
