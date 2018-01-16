#ifndef Controller_H
#define Controller_H
#include "Window.h"
#include "GameElement.h"
#include "MoveableObject.h"
#include <SDL2/SDL.h>
#undef main
#include <vector>
#include <array>
using std::vector;
/**Game controller manages all iterative functions and logic functions to set variables or delete objects*/
class Controller {
public:
	/**Controller constructor*/
	Controller( int liv, int sco);
	/**Controller destructor*/
	~Controller(); 
	/**All game logic and elements are chosen there*/
	void launchGame(int level);
	/**In this for loop all objects belonging to Game_elements are drawn, it take the pointer of the window as argument*/
	void showGraphicOutput(Window * window_foo, vector <GameElement*>* elements);
	/**Function to manage bouncing and deleting of objects. Also allows balls to change directions and implements powerups with the bouncing.*/
	void bounceOnObject( vector <GameElement*>* Game_elements, vector <MoveableObject*>* Moveable_objects, Window *window_c);
	/**Function to generate brick setting for each level*/
	void setBrickLevel(int level, vector <GameElement*>* elements);
	/**Handles events of the user input*/
	void poll(SDL_Event &event, Window * window, vector <GameElement*>* elements);
	/**Destroys all game objects*/
	void destroyLevel(int level, vector <GameElement*>* elements);
	/**Does a pause until you click the big button*/
	void startMenu(SDL_Event *event, Window *window_c);
	/**lives that the user has before exiting the game*/
	int lives;

private:
	/**score of the game should be displayed when exiting the game*/
	int	score;
	/**Time passed in milliseconds*/
	int timeElapsed = 0;
	/**Second time to compare*/
	int new_time = 0;
	/**window sizes in X and Y to resize*/
	int xprevious_wsize = 1000;
	/**window sizes in X and Y to resize*/
	int yprevious_wsize = 600;
	/**Game lost tells if game cannot continue due to loss of lives*/
	bool Game_lost = false;
	/**Boolean to see if a key event occurs*/
	bool event_flag;
	/**Mouse position array of 2 elements representing the position of the mouse in the window in X Y coordinates*/
	std::array<double, 2> mouse_position = {0,0};
	/**Boolean to jump the start menu function*/
	bool Start_game = false;

	//Global variables

	/**Flag to ensure a certain number of iteration within a cycle*/
	bool you_shall_not_pass = 0;
	/**Tells the number of iterations, after selected amount of iterations in iterations_per_cycle -> you_shall_not_pass = true, and iterate no more*/
	int iterator = 0;
public:
	/**Green color to use when selecting a new object*/
	SDL_Color Green =	 { 0  ,255,0  ,0  };
	/**Yellow color to use when selecting a new object*/
	SDL_Color Yellow =	 { 255,255,0  ,100};
	/**Red color to use when selecting a new object*/
	SDL_Color Red =		 { 255,0  ,0  ,0  };
	/**Blue color to use when selecting a new object*/
	SDL_Color Blue =	 { 0  ,0  ,255,0  };
	/**White color to use when selecting a new object*/
	SDL_Color White =	 { 255,255,255,255};
};
#endif // Controller_H