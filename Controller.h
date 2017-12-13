#ifndef Controller_H
#define Controller_H
#include <string>
#include "GameElement.h"
#include <SDL2/SDL.h>
#undef main
#include <vector>
using std::vector;

class Controller {
public:
	// constructor
	Controller(int = 0, int = 0, int = 0);
	virtual ~Controller() = default; // virtual standard destructor

	void launchGame();

	void showGraphicOutput();
	int checkForCollision();
	void bounceOnObject(int);
	void select_brick_level(int level);


private:
	int lifes, score, level;
	
	//vector <GameElement*> vector_elements = {};
};

struct Green {
	int r = 0;
	int g = 255;
	int b = 0;
	int a = 0;
};
struct Yellow {
	int r = 255;
	int g = 255;
	int b = 0;
	int a = 100;
};
struct Red {
	int r = 255;
	int g = 0;
	int b = 0;
	int a = 0;
};

#endif // Controller_H