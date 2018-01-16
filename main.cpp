/**
*\mainpage Breakout Description
*\section a Introduction:
*Breakout is a game in which various objects are being created and destroyed along the lifecycle of the game.
*
*\section b Game Controls:
* \details Click inside start button to start game.
* \details Keys:
* \details Up arrow to start Ball Bounce/Continue game
* \details Down arrow to Pause game
* \details Left arrow to move Platform Left
* \details Right arrow to move Platform Right
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

int main() {
	int lives = 3;
	int score = 0; 
	/**Create the controller instance*/
	Controller controller( lives, score); 
	/**For loop to control levels*/
	for (int level = 1; level < 4; level++) {  
		if (controller.lives > 0) {
			controller.launchGame(level);
		}
	}
	return 0;
}