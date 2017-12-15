#ifndef Platform_H
#define Platform_H

#include <string> // C++ standard string class
#include "MoveableObject.h"

class Platform : public MoveableObject {
public:
	Platform(const Window &window, GameElement::Color color);
	~Platform(); // destructor

	virtual std::string toString() const override;
	void keyInput(SDL_Event &event, GameElement *right_wall, GameElement *left_wall);

	void draw(Window *platform_window) const;

	void platformBounce(GameElement * ball);

private:

	int _r, _g, _b, _a;
	SDL_Texture *platform = nullptr;
	//empty for now (unless we want to add more later), but should not be necessary
};

#endif // Platform_HH