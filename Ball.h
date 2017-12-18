#ifndef Ball_H
#define Ball_H
#include "Window.h"
#include "MoveableObject.h"


class Ball : public MoveableObject {
public:
	Ball(const Window &window, GameElement::Size size, const std::string &image_path);
	~Ball(); // normal destructor

	virtual void move(GameElement *right_wall, GameElement *left_wall);

	void serveBall(SDL_Event &event, GameElement *right_wall, GameElement *left_wall);

	GameElement::ElementDestroyed Bounce(GameElement * ball);

	void draw(Window *ball_window)const;

	double getXDirection();
	double getYDirection();
	void setXDirection(double xdirection);
	void setYDirection(double ydirection);

private:
	double xpos, ypos;
	int _r, _g, _b, _a;
	SDL_Texture *pinball = nullptr;

};

#endif // Ball_HBall_H