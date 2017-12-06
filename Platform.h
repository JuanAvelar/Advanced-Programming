#pragma once
#ifndef Platform_H
#define Platform_H

#include <string> // C++ standard string class
#include "MoveableObject.h"
#include "Controller.h"

class Platform : public MoveableObject, public Window {
public:
	Platform(const Window &window, int xposition, int yposition, const int height, const int width, int r, int g, int b, int a);
	virtual ~Platform() = default; // virtual destructor

	virtual std::string toString() const override;
	void move(SDL_Event &event);
	MoveableObject bounceOnObject(MoveableObject ball) override;

	void draw() const;

private:

	int _r, _g, _b, _a;
	SDL_Texture *platform = nullptr;
	//empty for now (unless we want to add more later), but should not be necessary
};

#endif // Platform_H
