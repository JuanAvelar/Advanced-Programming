#include "Controller.h"
#include "GameElement.h"
#include <iostream>


int main(int argc, char **argv) {
	int level = 1;
	int lives = 3;
	int score = 0; 
	
	GameElement game_element(100,100,20,20);

	Controller controller(level, lives, score); //create the controller instance
	controller.launchGame();
	//test comment
	//second test comment
	

	return 0;

}