#ifndef Platform_H
#define Platform_H
#include "Window.h"
#include "MoveableObject.h"


class Platform : public MoveableObject {
public:
	Platform( SDL_Color color);
	Platform(const Window &window, GameElement::Size size, const std::string &image_path);
	~Platform(); // destructor

	void keyInput(SDL_Event &event);

	void draw(Window *platform_window) const;

	virtual void move(GameElement *right_wall, GameElement *left_wall);

	GameElement::ElementDestroyed Bounce(GameElement * ball);
};

#endif // Platform_H