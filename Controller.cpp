#include <sstream>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <iomanip>
#include "GameElement.h"
#include "Controller.h"
#include "Ball.h"
#include "Platform.h"
#include "Brick.h"
#include "Wall.h"
#include "Window.h"
#include <vector>
#define window_height 600
#define window_width 1000
using std::vector;

//Global variables
int number_of_bricks = 0;	/**Counts the number of bricks in the game*/
vector <GameElement*> Game_elements;

// constructor
Controller::Controller(int lev, int lif, int sco)
	: level(lev), lifes(lif), score(sco) {}//private

										   /**In this function every function from the game is implemented(top major function)*/
void Controller::launchGame() {
	Window window_c("Breakout", window_width, window_height);								/**UI instance*/
	SDL_Event event;													/**Event of keyboard instance*/
	Ball* ball = new Ball{ window_c, 100, 100, 20, 20, "pictures/shiny_pinball.png" };/**ball instance*/
	Platform* platform= new Platform{ window_c, 500, 500, 20, 100, Green().r, Green().g, Green().b, Green().a };		/**Platform instance*/
	std::cout << "aqui no esta el error\n";
	vector <Brick*> brick;												/**Vector of pointer to brick objects*/
	
	Wall* walls = new Wall{ 990, 0, 600, 10, Yellow().r, Yellow().g, Yellow().b, Yellow().a, Wall::up };			/**wall instance*/
	
	//...write function to start the game, make a big start button and when clicked the game starts (first need to get level from LevelsGeneration)
	while (!window_c.isClosed()) {
		if (SDL_PollEvent(&event)) {
			platform->move(event);
			window_c.pollEvents(event);
		}
		ball->draw(&window_c);
		platform->draw(&window_c);
		walls->draw(&window_c);
		for (int i = 1; i < number_of_bricks + 1; i++) {
				Game_elements[i - 1]->draw(&window_c);	
				std::cout << i;
		}
		window_c.clear();
	}
}


void Controller::showGraphicOutput() {
	// function to show all the graphics, will be updated often
}

int Controller::checkForCollision() {
	return 0;
	//function that checks if the ball hits another object, need to think of what is a logical return? maybe an int (e.g. 0 for no colossion, 1 for brick, 2 for wall, 3 for platform)?
	//if colission takes place, call for bounceOnObject to handle colission
}
//gets input from checkForColission
void Controller::bounceOnObject(int obj) {

}

//You must disinherit the window object to the rest of the objects
void Controller::select_brick_level(int level) {
	switch (level) {
	case 1:
		for (int i = 1; i < 10; i++) {
			for (int f = 0; f < 3; f++) {
				Game_elements.emplace_back(new Brick{ i * 110 - 100, 150 + f * 40, 30, 100, 3, i * 25, 0, 255 - i * 25, 0 });
				number_of_bricks++;
			}
		}
		break;
	case 2:
		for (int i = 1; i < 10; i++) {
			for (int f = 0; f < 3; f++) {
				Game_elements.emplace_back(new Brick{ i * 110 - 100, 50 + f * 40, 30, 100, 3, i * 25, 0, 255 - i * 25, 0 });
				number_of_bricks++;
			}
		}
		break;
	}
}