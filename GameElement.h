#ifndef GameElement_H
#define GameElement_H
#include "Window.h"
#include <string>
#include <iostream>
/**Game Element manages each element of the game seperately, each must contain its own texture to add the possibility 
to draw an PNG image instead of a rectangle with a color*/
class GameElement {
public:				
	/**Constructor it has X Y coordinates and height/width as inputs*/
	GameElement(int xpos, int ypos, const int h, const int w);
	/**Virtual Standard destructor*/
	virtual ~GameElement() = default; // virtual standard destructor
	/**Enum type that tells if the things destroyed is a brick or aa ball or nothing (used in the bounce function)*/
	enum ElementDestroyed { destroynothing, destroybrick, destroyball };
	/**Size of the game elements (Input of most of the elements constructor, select height and width in a switch case inside each constructor)*/
	enum Size { small, medium, big };
	/**Draw virtual function, it draws the element using the pointer Renderer of the window class, it detects if an image is used or just a colored rectangle*/
	virtual void draw(Window* window) const = 0;//pure virtual
	/**Virtual function to manage bouncing objects throughout the game, it also manages the destruction of objects in each situation*/
	virtual GameElement::ElementDestroyed Bounce(GameElement * ball) = 0;

public:
	/**position Left most part of the object*/
	int		xposition,
	/**position Top most part of the object*/
			yposition,
	/**Height of the game element in amount of pixels*/
			height, 
	/**Width of the game element in amount of pixels*/
			width;
	/**Same as xposition but double to manage more accuracy*/
	double	xpos, 
	/**Same as yposition but double to manage more accuracy*/
			ypos;
	/**Red RGBA*/
	Uint8	_r, 
	/**Green RGBA*/
			_g, 
	/**Blue RGBA*/
			_b, 
	/**Absence of light RGBA*/
			_a;
protected:
	/**A pointer to an image texture used to draw a PNG image representing the game element chosen*/
	SDL_Texture *Possesed_image;
};
#endif // GameElement_H