/**
*\mainpage Breakout description
*\section a Why?
*Breakout is a game in which various objects are being created and destroyed along the lifecycle of the game
*
*\section b How?
*
*
*
*\author Juan Pablo Avelar
*\date 16 december 2017
*/
#include "Controller.h"
#include "GameElement.h"
#include <iostream>

int main(int argc, char **argv) {
	int lives = 3;
	int score = 0; 
	
	//GameElement game_element(100,100,20,20);
	/**This is a controller*/
	Controller controller( lives, score); //create the controller instance
	for (int level = 1; level < 4; level++) {
		controller.launchGame(level);
		//break;//Get rid of this to enter new levels
	}
	//test comment
	//second test comment
	return 0;
}