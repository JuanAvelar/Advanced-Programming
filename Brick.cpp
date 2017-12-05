#include "Brick.h"
using namespace std;

// constructor 
Brick::Brick(int xposition, int yposition, const int	height, const int width, int hitsToDestroy)
	: GameElement(xposition, yposition, height, width) {
	setHitsToDestroy(hitsToDestroy);
}

void Brick::setHitsToDestroy(int hitsToDestroy) {
	hits = hitsToDestroy;
}

int Brick::getHitsToDestroy() {
	return hits;
}



// return a string representation of Brick's information 
string Brick::toString() const {
	return "0";
}
