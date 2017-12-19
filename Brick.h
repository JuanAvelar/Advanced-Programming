#ifndef BRICK_H
#define BRICK_H

#include <string> // C++ standard string class
#include "GameElement.h" 
#include "Ball.h"

/**Inheritance of Brick class from GameElement*/
class Brick : public GameElement { 
public:
	/**Constructor for brick*/
	Brick( int xposition, int yposition, const int	height, const int width, int hitsToDestroy, int r, int g, int b, int a);
	/**Normal Destructor of Bricks*/
	~Brick(); 
	/**Virtual Draw function of Brick class*/
	virtual void draw(Window *window_brick) const;  
	/**Bounce function of brick that overrides the virtual function of GameElement*/
	GameElement::ElementDestroyed Bounce(GameElement *ball);
	/**Fucntion that contains conditions to remove brick life*/
	void removeBrickLife(); 

	//virtual std::string toString() const override;
	/**Private Variables of Brick class*/
private:
	int hitsToDestroy;
	int hits;
	int _r, _g, _b, _a;
	SDL_Texture *bricks = nullptr;
};

#endif // Brick_H