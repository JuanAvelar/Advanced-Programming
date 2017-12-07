#pragma once
#include <sstream>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "GameElement.h"
#include "Controller.h"
#include "Ball.h"
#include "Platform.h"
#include "Brick.h"
#include "Window.h"
#include <vector>
using std::vector;


// constructor
Controller::Controller(int lev, int lif, int sco)
	: level(lev), lifes(lif), score(sco) {}//private

/**In this function every function from the game is implemented(top major function)*/
void Controller::launchGame() {
	labelstart:
	Window window_c("Breakout", 1000, 600);								/**UI instance*/
	SDL_Event event;													/**Event of keyboard instance*/
	Ball ball(window_c, 530, 479, 20, 20, "pictures/shiny_pinball.png");/**ball instance*/
	Platform platform(window_c, 500, 500, 20, 100, 0, 255, 0, 0);		/**Platform instance*/
	vector <Brick*> brick;												/**Vector of pointer to brick objects*/
	int number_of_bricks = 0;											/**Counts the number of bricks in the game*/

	switch (level) {
	case 1:
		for (int i = 1; i < 10; i++) {
			for (int f = 0; f < 3; f++) {
				brick.emplace_back(new Brick{ window_c, i * 110 - 100, 150 + f * 40, 30, 100, 1, i * 25, 0, 255 - i * 25, 0 });
				number_of_bricks++;
			}
		}
		break;
	case 2:
		for (int i = 1; i < 10; i++) {
			for (int f = 0; f < 4; f++) {
				brick.emplace_back(new Brick{ window_c, i * 110 - 100, 50 + f * 40, 30, 100, 1, i * 25, 0, 255 - i * 25, 0 });
				number_of_bricks++;
			}
		}
		break;
	}
	
	//...write function to start the game, make a big start button and when clicked the game starts (first need to get level from LevelsGeneration)
	while (!window_c.isClosed()) {
		if (SDL_PollEvent(&event)) {
			ball.serveBall(event);
			platform.move(event);
			window_c.pollEvents(event);
		}
		ball.wallBounce();
		platform.platformBounce(ball);
		ball.move();
		ball.draw();
		platform.draw();
		int bricksleft = 0;
		for (int i = 1; i < number_of_bricks + 1; i++) {
			brick[i - 1]->brickBounce(ball);
			brick[i - 1]->draw();
			bricksleft += brick[i - 1]->getHitsToDestroy();
		}
		if (bricksleft == 0) {
			level++;
			window_c.~Window();
			ball.~Ball();
			platform.~Platform();
			brick.clear();
			event.~SDL_Event();
			if (level > 2) {
				std::cout << "Congratulation, you win!" << std::endl;
				system("pause");
				break;
			}
			goto labelstart;

		}
		window_c.clear();
	}
}
