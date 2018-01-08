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

	void draw(Window *ball_window)const;

	GameElement::ElementDestroyed Bounce(GameElement * ball);

};

#endif //Ball_H