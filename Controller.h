#ifndef Controller_H
#define Controller_H
#include <string>
#include "Window.h"
#include "GameElement.h"
#include <SDL2/SDL.h>
#undef main
#include <vector>
using std::vector;

class Controller {
public:
	// constructor
	Controller( int liv, int sco);
	virtual ~Controller() = default; // virtual standard destructor

	void launchGame(int level);

	void showGraphicOutput(Window * window_foo);
	int checkForCollision();
	void bounceOnObject(int);
	void set_brick_level(int level);
	void poll(SDL_Event &event, Window * window);

private:
	int lives, score;
	/**Time passed in milliseconds*/
	int time = 0;
	/**Second time to compare*/
	int new_time = 0;
	/**window sizes in X and Y to resize*/
	int xprevious_wsize = 1000;
	int yprevious_wsize = 600;

	//Global variables
	/** Vector of Game element pointers*/
	vector <GameElement*> Game_elements;
	/**Map of bits to check further collisions*/
	bool map_array[1000][600];
	/**Flag to ensure just one iteration per milisecond*/
	bool you_shall_not_pass = 0;
	int iterator = 0;
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
struct Blue {
	int r = 0;
	int g = 0;
	int b = 255;
	int a = 0;
};

#endif // Controller_H