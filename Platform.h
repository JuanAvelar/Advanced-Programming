#ifndef Platform_H
#define Platform_H
#include "Window.h"
#include "MoveableObject.h"
#include "Ball.h"

/**Platform generates a rectangle with an image and manages function accordingly*/
class Platform : public MoveableObject {
public:
	Platform(const Window &window, GameElement::Size size, const std::string &image_path);
	~Platform(); // destructor

	void keyInput(SDL_Event &event);

	void draw(Window *platform_window) const;

	void move(GameElement *right_wall, GameElement *left_wall);

	GameElement::ElementDestroyed Bounce(GameElement * ball);
};

#endif // Platform_H