#pragma once
#ifndef Controller_H
#define Controller_H
#include <string>
#include "GameElement.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
using std::vector;

class Controller {
public:
	// constructor
	Controller(int = 0, int = 0, int = 0);
	~Controller() = default; // virtual standard destructor

	void launchGame();

private:
	int lifes, score, level;

	//vector <GameElement*> vector_elements = {};
};

#endif // Controller_H