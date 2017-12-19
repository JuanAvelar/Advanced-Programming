#ifndef GameElement_H
#define GameElement_H


#include <string>
#include "Window.h"

/**Creating class GameElement*/
class GameElement {
public:				
	/**Constructor of class GameElement*/
	GameElement(int xpos, int ypos, const int h, const int w);
	/**virtual standard destructor of GameElement*/
	virtual ~GameElement() = default; 
	/**Declares a type of your own, in this case being a derstruction types*/
    enum ElementDestroyed { destroynothing, destroybrick, destroyball};  
	/**Declaring coloursElements*/
	enum Color {yellow, green, red, blue};								  
	/**Declaring sizes of GameElements*/
	enum Size {small, medium, big};										  
	/**Function to set color*/
	int* set_color_rgba(Color color);									 
	/**Function to height of elements*/
	int getHeight() const;	
	/**Function to width of elements*/
	int getWidth() const;
	/**Functions to get X location of elements*/
	int getXLocation();
	/**Functions to get Y location of elements*/
	int getYLocation();
	/**Pure virtual function*/
	virtual void draw(Window* window) const = 0;     
	/**Pure virtual function that returns the type of object destroyed*/
	virtual GameElement::ElementDestroyed Bounce(GameElement * ball) = 0; 
	/**Function to destroy GameElements*/
	void destroyGameElement();  


	//virtual std::string toString() const;

public:
	int xposition, yposition, height, width;
	double xpos, ypos;

	
};

#endif // GameElement_H


