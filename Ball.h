#ifndef Ball_H
#define Ball_H

#include "MoveableObject.h"


class Ball : public MoveableObject, public Window {
public:
	Ball(const Window &window, int xposition, int yposition, const int height, const int width, const std::string &image_path);
	~Ball(); // normal destructor

	void move() override;

	void serveBall(SDL_Event &event);

	void wallBounce();

	void draw() const;

private:

	int _r, _g, _b, _a;
	SDL_Texture *pinball = nullptr;

};

#endif // Ball_HBall_H