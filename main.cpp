#include "Controller.h"
#include "GameElement.h"
#include <iostream>


int main(int argc, char **argv) {
	int level = 1;
	int lifes = 3;
	int score = 0; 
	
	GameElement game_element(100,100,20,20);

	Controller controller(level, lifes, score); //create the controller instance
	controller.launchGame();
	
	

	return 0;

}