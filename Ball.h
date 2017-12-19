#ifndef Ball_H
#define Ball_H
#include "Window.h"
#include "MoveableObject.h"

/**Inheritance of Ball from MovableObject*/
class Ball : public MoveableObject {  
public:
	/**Ball Constructor*/
	Ball(const Window &window, GameElement::Size size, const std::string &image_path); 
	/**Normal destructor*/
	~Ball();
	virtual void move(GameElement *right_wall, GameElement *left_wall); 
	/**Pure Virtual function for side walls*/
	void serveBall(SDL_Event &event, GameElement *right_wall, GameElement *left_wall);
	/**Accessing ball from GameElement*/
	GameElement::ElementDestroyed Bounce(GameElement * ball); 

	/**Draw function*/
	void draw(Window *ball_window)const;	

	/**Function to get X direction of ball*/
	double getXDirection();
	/**Function to get Y direction of ball*/
		double getYDirection();
	/**Function to set X direction of ball*/
	void setXDirection(double xdirection);
	/**Function to set Y direction of ball*/
	void setYDirection(double ydirection);

	/**Declaring private variables of class Ball.*/
private:
	double xpos, ypos;			
	int _r, _g, _b, _a;
	SDL_Texture *pinball = nullptr;

};

#endif // Ball_HBall_H