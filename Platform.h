#ifndef Platform_H
#define Platform_H

#include <string> // C++ standard string class
#include "MoveableObject.h"


class Platform : public MoveableObject {
public:
	Platform(const Window &window, GameElement::Color color);
	Platform::Platform(const Window &window, GameElement::Size size, const std::string &image_path);
	~Platform(); // destructor

	virtual std::string toString() const override;
	void keyInput(SDL_Event &event);

	void draw(Window *platform_window) const;

	//void move(GameElement *right_wall, GameElement *left_wall);

	bool Bounce(GameElement * ball, bool *Game_lost);

private:
	int _r, _g, _b, _a;
	SDL_Texture *platform = nullptr;
	//empty for now (unless we want to add more later), but should not be necessary
};

#endif // Platform_HH