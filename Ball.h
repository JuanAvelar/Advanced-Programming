#ifndef Ball_H
#define Ball_H
#include "Window.h"
#include "MoveableObject.h"

/**Ball generates a ball and manages function accordingly. Input parameters are a window ptr, the size of the ball(big, medium, small), the path to the image you want to use in "" .*/
class Ball : public MoveableObject {
public:
	Ball(const Window &window, GameElement::Size size, const std::string &image_path);
	~Ball(); // normal destructor

	void move(GameElement *right_wall, GameElement *left_wall);

	void draw(Window *ball_window)const;

	void keyInput(SDL_Event &event);

	GameElement::ElementDestroyed Bounce(GameElement * ball);

};

#endif //Ball_H