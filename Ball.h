#ifndef Ball_H
#define Ball_H
#include "Window.h"
#include "MoveableObject.h"


class Ball : public MoveableObject {  /**Inheritance of Ball from MovableObject*/
public:
	Ball(const Window &window, GameElement::Size size, const std::string &image_path); /**Ball Constructor*/
	~Ball(); /**Normal destructor*/

	virtual void move(GameElement *right_wall, GameElement *left_wall); /**Pure Virtualfunction for side walls*/

	void serveBall(SDL_Event &event, GameElement *right_wall, GameElement *left_wall);

	GameElement::ElementDestroyed Bounce(GameElement * ball); /**Accessing ball from GameElement*/

	/**Draw function*/
	void draw(Window *ball_window)const;	

	/**Functions to get and set directions of ball*/
	double getXDirection();
	double getYDirection();
	void setXDirection(double xdirection);
	void setYDirection(double ydirection);

	/**Declaring private variables of Ball class*/
private:
	double xpos, ypos;			
	int _r, _g, _b, _a;
	SDL_Texture *pinball = nullptr;

};

#endif // Ball_HBall_H