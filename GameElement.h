#ifndef GameElement_H
#define GameElement_H


#include <string>
#include "Window.h"

class GameElement {
public:				
	/**Constructor of class GameElement*/
	GameElement(int xpos, int ypos, const int h, const int w);
	virtual ~GameElement() = default; /**virtual standard destructor*/

    enum ElementDestroyed { destroynothing, destroybrick, destroyball };  /**Declares a type of your own, in this case being a derstruction types*/
	enum Color {yellow, green, red, blue};								  /**Declaring coloursElements*/	
	enum Size {small, medium, big};										  /**Declaring sizes of GameElements*/	
	
																		  /**Declaring different GameElements*/
	int* set_color_rgba(Color color);

	int getHeight() const;
	int getWidth() const;

	int getXLocation();
	int getYLocation();

	virtual void draw(Window* window) const = 0;     /**pure virtual function*/

	virtual GameElement::ElementDestroyed Bounce(GameElement * ball) = 0; /**Pure virtual function that returns the type of object destroyed*/

	void destroyGameElement();  /**Function to destroy GameElements*/


	//virtual std::string toString() const;

public:
	int xposition, yposition, height, width;
	double xpos, ypos;

	
};

#endif // GameElement_H


