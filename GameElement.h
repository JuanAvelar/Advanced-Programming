#ifndef GameElement_H
#define GameElement_H


#include <string>
#include "Window.h"

class GameElement {
public:				
	// constructor
	GameElement(int xpos, int ypos, const int h, const int w);
	virtual ~GameElement() = default; // virtual standard destructor

	enum ElementDestroyed { destroynothing, destroybrick, destroyball };
	enum Color {yellow, green, red, blue};
	enum Size {small, medium, big};

	int* set_color_rgba(Color color);

	int getHeight() const;
	int getWidth() const;

	int getXLocation();
	int getYLocation();

	virtual void draw(Window* window) const = 0;//pure virtual

	virtual GameElement::ElementDestroyed Bounce(GameElement * ball) = 0;

	void destroyGameElement();




	

	virtual std::string toString() const;

public:
	int xposition, yposition, height, width;
	double xpos, ypos;

	
};

#endif // GameElement_H


