#ifndef Ball_H
#define Ball_H
#include "Window.h"
#include "MoveableObject.h"

/**Ball generates a ball and manages function accordingly*/
class Ball : public MoveableObject {
public:
	Ball(const Window &window, GameElement::Size size, const std::string &image_path);
	~Ball(); // normal destructor

	virtual void move(GameElement *right_wall, GameElement *left_wall);
	/**Moves the ball when its speed is 0*/

	void draw(Window *ball_window)const;

	GameElement::ElementDestroyed Bounce(GameElement * ball);

};

#endif //Ball_H