#include "Controller.h"
#include "GameElement.h"
#include <iostream>


int main(int argc, char **argv) {
	int lives = 3;
	int score = 0; 
	
	//GameElement game_element(100,100,20,20);

	Controller controller( lives, score); //create the controller instance
	for (int level = 1; level < 3; level++) {
		controller.launchGame(level);
		break;//Get rid of this to enter new levels
	}
	//test comment
	//second test comment
	

	return 0;

}