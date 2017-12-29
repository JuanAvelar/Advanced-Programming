#ifndef GameElement_H
#define GameElement_H

#include "Window.h"

class GameElement {
public:				
	// constructor
	GameElement(int xpos, int ypos, const int h, const int w);
	virtual ~GameElement() = default; // virtual standard destructor

	enum ElementDestroyed { destroynothing, destroybrick, destroyball };
	enum Size { small, medium, big };

	int getHeight() const;
	int getWidth() const;

	int getXLocation();
	int getYLocation();

	virtual void draw(Window* window) const = 0;//pure virtual

	virtual GameElement::ElementDestroyed Bounce(GameElement * ball) = 0;

	void destroyGameElement();

public:
	int xposition, yposition, height, width;
	double xpos, ypos;
	Uint8 _r, _g, _b, _a;
//protected:
	SDL_Texture *Possesed_image;
	
};

#endif // GameElement_H


