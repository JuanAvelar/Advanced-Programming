#ifndef Controller_H
#define Controller_H
#include <string>
#include "Window.h"
#include "GameElement.h"
#include "MoveableObject.h"
#include <SDL2/SDL.h>
#undef main
#include <vector>
using std::vector;

/**Creating Class Controller*/
class Controller {
public:
	/**Constructor for controller*/
	Controller( int liv, int sco);
	/**Virtual standard destructor of controller*/
	virtual ~Controller() = default;
	/**Initaiating game launch function*/
	void launchGame(int level); 

	/**Display graphics on window*/
	void showGraphicOutput(Window * window_foo, vector <GameElement*>* elements);
	/**Collisions between all objects*/
	void bounceOnObject(vector <int>* number_of_ball, vector <GameElement*>* Game_elements, vector <MoveableObject*>* Moveable_objects, Window *window_c);
	/**Defines the position of all bricks according to level*/
	void set_brick_level(int level, vector <GameElement*>* elements);
	/**Polls input events that have to do with changing the window size*/
	void poll(SDL_Event &event, Window * window, vector <GameElement*>* elements);
	/**Destroys all elements*/
	void Controller::destroy_level(int level, vector <GameElement*>* elements);
	/**Defining start menu*/
	void Controller::Start_menu(SDL_Event *event, Window *window_c);


	/**Function to get the amount of lifes left in the main*/
	int getLives();

private:
	int lives, score; 
	/**Time passed in milliseconds*/
	int time = 0;
	/**Second time to compare*/
	int new_time = 0;
	/**Window sizes in X and Y to resize*/
	int xprevious_wsize = 1000;
	int yprevious_wsize = 600;
	bool Game_lost = false;
	/**Boolean to see if an event occurs*/
	bool event_flag;
	double mouse_position[2];
	bool Start_game = false;

	//Global variables

	/**Map of bits to check further collisions*/
	bool map_array[1000][600];
	/**Flag to ensure just one iteration per milisecond*/
	bool you_shall_not_pass = 0;
	int iterator = 0;
};
/**Green Struct*/
struct Green {
	int r = 0;
	int g = 255;
	int b = 0;
	int a = 0;
};
/**Yellow Struct*/
struct Yellow {
	int r = 255;
	int g = 255;
	int b = 0;
	int a = 100;
};
/**Red struct*/
struct Red {
	int r = 255;
	int g = 0;
	int b = 0;
	int a = 0;
};
/**Blue struct*/
struct Blue {
	int r = 0;
	int g = 0;
	int b = 255;
	int a = 0;
};

#endif // Controller_H