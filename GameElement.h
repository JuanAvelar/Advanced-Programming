#pragma once
#ifndef GameElement_H
#define GameElement_H

#include <string>
#include "Window.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class GameElement {
public:
	// constructor
	GameElement(int = 0, int = 0, const int = 0, const int = 0);
	virtual ~GameElement() = default; // virtual standard destructor

	int getHeight() const;
	int getWidth() const;

	int getXLocation();
	int getYLocation();

protected:
	int xposition, yposition, height, width;
};

#endif // GameElement_H


