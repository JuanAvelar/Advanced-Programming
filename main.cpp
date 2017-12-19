/**
*\mainpage Breakout Description
*\section a Inrtoduction:
*Breakout is a game in which various objects are being created and destroyed along the lifecycle of the game.
*
*\section b Game Controls:
* \details Click inside start button to start game.
* \details Buttons:
* \details Up arrow to start Ball bounce/Continue game
* \details Down arrow to pause game
* \details Left arrow to move platform left
* \details Right arrow to move platform right
*
*\author Juan Pablo Avelar S1961756  
*\author Merijn Chantal Schneider S1574973
*\author Merijn Hofsteenge S1939408
*\author Hemmanth Jaladi S1912119
*\date 20th December 2017
*/
#include "Controller.h"
#include "GameElement.h"
#include <iostream>

int main(int argc, char **argv) {
	int lives = 3;
	int score = 0; 
	
	//GameElement game_element(100,100,20,20);
	/**This is a controller*/
	Controller controller( lives, score); /**Create the controller instance*/
	for (int level = 1; level < 4; level++) {  /**For loop to control levels*/
		if (controller.getLives() > 0) {
			controller.launchGame(level);
			//break;//Get rid of this to enter new levels
		}
	}
	
	return 0;
}