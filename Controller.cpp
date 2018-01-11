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
#include <cmath>
#include <vector>
#include <memory>
#include <string>
#define window_height 600
#define window_width 1000
#define iterations_per_cycle 8
#define cycle_time 30				//in milliseconds
#define time_for_graphic_output 10	//in milliseconds
#define duty_cycle_percentage 0.4	//state percentage of time spent to complete motion of the ball and collisions
using std::vector;

// constructor
Controller::Controller( int liv, int sco)
	: lives(liv), score(sco) {
	
}//private

/**In this function every function from the game is implemented(top major function)*/
void Controller::launchGame(int level) {
	std::ostringstream Window_title;
	Window_title << "Breakout: Level " << level;
	Window window_c(Window_title.str(), window_width, window_height);						/**UI instance*/
	SDL_Event event;																		/**Event of keyboard instance*/
	vector <GameElement*> Game_elements;													/** Vector of Game element pointers*/
	vector <MoveableObject*> Moveable_objects;
	Ball* ball = new Ball{ window_c, GameElement::big, "pictures/shiny_pinball.png" };	/**ball instance*/
	Platform* platform= new Platform{ Green };												/**Platform instance*/
	
	Wall* right_wall = new Wall{ Yellow, Wall::right };
	Wall* left_wall = new Wall{ Yellow, Wall::left };
	
	Game_lost = false;																		/**The game is not lost when you begin*/

	Game_elements.emplace_back(ball);											//puts the ball pointer as first 
	Game_elements.emplace_back(platform);										//platform pointer as second
	Game_elements.emplace_back( new Wall{ Yellow, Wall::up });		//wall pointers as third, fourth, fifth, sixth
	Game_elements.emplace_back( right_wall );
	Game_elements.emplace_back( left_wall );
	Game_elements.emplace_back( new Wall{ Yellow, Wall::down });


	Moveable_objects.emplace_back(ball);
	Moveable_objects.emplace_back(platform);

	set_brick_level(level, &Game_elements);													/**Function to generate all bricks depending on the level*/
	
//int number_of_ball[number of balls] = {position1, position2, etc.};//positions in the array of game elements
	vector <int> number_of_ball = { 0};
	Start_menu(&event, &window_c);

	//...write function to start the game, make a big start button and when clicked the game starts (first need to get level from LevelsGeneration)
	while (!window_c.isClosed() && !Game_lost) {
		if (SDL_PollEvent(&event)) {
			event_flag = true;
			poll(event, &window_c, &Game_elements);//checks if the window has changed its size
		}
		//std::cout << "busy" << std::endl;
		time = SDL_GetTicks();//Gets time since the first time sdl library was accessed
		
		if ((time % cycle_time < cycle_time*duty_cycle_percentage) && !you_shall_not_pass) {//in this if output is updated time in milliseconds
			if (iterator == iterations_per_cycle - 1) {	you_shall_not_pass = true;}//The cycle repeated 3 times in the same millisecond this is to ensure it just iterates n times in that millisecond
			for (auto moving : Moveable_objects) {moving->move(right_wall, left_wall);}
			bounceOnObject(&number_of_ball, &Game_elements, &Moveable_objects, &window_c);
			iterator++;
		}
		else if (time % cycle_time > cycle_time/2 && time % cycle_time < cycle_time / 2 + time_for_graphic_output) {
			showGraphicOutput(&window_c, &Game_elements);
			 //std::cout << time << std::endl; 
		}
		else if (time % cycle_time > cycle_time*duty_cycle_percentage) {//waits until moving the ball is done
			if (you_shall_not_pass) {
				you_shall_not_pass = false;
				iterator = 0;
			}
			if (event_flag) {
				Ball *ball_pointer = dynamic_cast<Ball*> (Game_elements[0]);
					platform->keyInput(event, ball_pointer);//platform moves when an event happens
					window_c.pollEvents(event);//checks for events happening in the window such as keyboard and change window size
					event_flag = false;
			}
		}
		if (Game_elements.size() < 6 + number_of_ball.size()) { break; }//when number of elements is less than 7 exit game, because all the bricks have been cleared.
	}
	destroy_level(level, &Game_elements);
	Moveable_objects.clear();
	Game_elements.clear();
}

/**Controller destructor*/
Controller::~Controller() {
}

/**In this for loop all objects belonging to Game_elements are drawn, it take the pointer of the window as argument*/
void Controller::showGraphicOutput(Window *window_foo, vector <GameElement*>* elements) {

	for (int i = 0; i < signed(elements->size()); i++) {
		if ((*elements)[i] == nullptr) { std::cout << "This element is nullptr!" << std::endl; }
		(*elements)[i]->draw(window_foo);		

	}
	window_foo->clear();
}

//gets input from checkForColission
void Controller::bounceOnObject(vector <int>* number_of_ball, vector <GameElement*>* Game_elements, vector <MoveableObject*>* Moveable_objects, Window * window_c) {
	/**vector to state which game elements will be erased after the range based for*/
	for (auto c : *number_of_ball) {
		for (int i = 0; i < signed(Game_elements->size()); i++) {//check for a brick collision
			if (i != c && (*Game_elements)[i] != nullptr && (*Game_elements)[c] != nullptr) {//skips the collision between the ball and the same ball, because it is phisically not possible
				GameElement::ElementDestroyed Element_destructed = (*Game_elements)[i]->Bounce((*Game_elements)[c]);//the element in c is the ball //Returns true if brick is destroyed
				if (Element_destructed == GameElement::destroybrick) { 
					(*Game_elements)[i] = nullptr;
				}//if brick is destroyed then it gets rid of the vector element
				if (Element_destructed == GameElement::destroyball) {
					//the size of number_of_ball is defined in bits, so 1 element is 4, 2 is 8...
					if (number_of_ball->size() < 2) {
						lives--;

						if (lives < 1) {
							Game_lost = true;
							(*Game_elements)[c] = nullptr;//Setting it to null ptr, it cannot be erased until the pc is out of the second for loop
							break;
						}
						else {
							Ball* ball = new Ball{ (*window_c), GameElement::small, "pictures/shiny_pinball.png" };
							(*Game_elements)[c] = ball;//check that all movable objects are first in the game element vector, use: myvector.emplace ( myvector.begin()+ position, newBlabla );
							(*Moveable_objects)[c] = ball;
						}
					}
					else {
						(*Game_elements)[c] = nullptr;
						Moveable_objects->erase(Moveable_objects->begin() + c);
						//delete also place of the number of ball
					}
				}
			}
		}
	}
	//erasing elements from vector
	int it_1 = 0;
	while (it_1 < signed(Game_elements->size())) {
		//std::cout << it_1 << std::endl;
		if ((*Game_elements)[it_1] == nullptr) {
			Game_elements->erase(Game_elements->begin() + it_1);//erase previously defined vector spaces to be whiped

			int it_2 = 0;
			while (it_2 < signed(number_of_ball->size())) {//a while loop is used to compare the numbers inside number_of_ball and all stuff to be erased, if it matches then position is erased from vector.
				if ((*number_of_ball)[it_2] == it_1) {
					number_of_ball->erase(number_of_ball->begin() + it_2);
				}
				else {
					it_2++;
				}
			}//erase the position of the balls in the game elements vector if ball is eliminated
		}
		else {
			it_1++;
		}
	}
}

//You must disinherit the window object to the rest of the objects
void Controller::set_brick_level(int level, vector <GameElement*>* elements) {
	
	switch (level) {
	case 1:
		for (int i = 1; i < 10; i++) {
			for (int f = 0; f < 3; f++) {
				elements->emplace_back(new Brick{ i * 110 - 100, 150 + f * 40, 30, 100, 1, Uint8(i * 25), Uint8( 0), Uint8(255 - i * 25), Uint8(0) });
				
			}
		}
		break;
	case 2:
		for (int i = 1; i < 10; i++) {
			for (int f = 0; f < 4; f++) {
				elements->emplace_back(new Brick{ i * 110 - 100, 50 + f * 40, 30, 100, 1, Uint8(i * 25), Uint8(0), Uint8(255 - i * 25), Uint8(0) });
				
			}
		}
		break;
	}
}

/**Destroys all bricks if level is lost*/
void Controller::destroy_level(int level, vector <GameElement*>* elements) {

	switch (level) {
	case 1:
		for (int i = 0; i < signed(elements->size()) ; i++) {
			delete (*elements)[i];
		}
		break;
	case 2:
		for (int i = 0; i < signed(elements->size()); i++) {
			delete (*elements)[i];
		}
		break;
	}
}

/**Displaces the game to the center of the window*/
void Controller::poll(SDL_Event &event,Window *window, vector <GameElement*>* elements) {
	if (event.type == SDL_WINDOWEVENT) {
		switch (event.window.event) {
			case SDL_WINDOWEVENT_SIZE_CHANGED:
				//std::cout << (SDL_GetWindowSurface(window->_window)->w)  << std::endl;
				//std::cout << (SDL_GetWindowSurface(window->_window)->w)/2-500 << std::endl;
				
			for (int i = 0; i < signed(elements->size()); i++) {
				(*elements)[i]->xposition += (SDL_GetWindowSurface(window->_window)->w)/2 - xprevious_wsize/2;
				(*elements)[i]->yposition += (SDL_GetWindowSurface(window->_window)->h)/2 - yprevious_wsize/2;
				(*elements)[i]->xpos = (*elements)[i]->xposition;
				(*elements)[i]->ypos = (*elements)[i]->yposition;

			}
			xprevious_wsize = (SDL_GetWindowSurface(window->_window)->w);
			yprevious_wsize = (SDL_GetWindowSurface(window->_window)->h);
			break;
		};
		
	};
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
		case SDLK_DOWN:
			std::cout << "Amount of lives: " << lives << std::endl;
			while (event.key.keysym.sym != SDLK_UP) { SDL_PollEvent(&event); }
			break;
		};
	};
}

int Controller::getLives() {
	return lives;
}

void Controller::Start_menu(SDL_Event * event, Window * window_c) {
	if (!Start_game) {
		std::unique_ptr<Platform> Start(new Platform{ *window_c, GameElement::big, "pictures/start.png" });
		while (!window_c->isClosed() && Start_game == false) {
			if (SDL_PollEvent(event)) {
				switch (event->type) {
				case SDL_KEYUP:
					switch (event->key.keysym.sym) {
					case SDLK_ESCAPE:
						Start_game = true;
						break;
					default:
						break;
					}
				case SDL_MOUSEMOTION:
					mouse_position[0] = event->motion.x - Start->xposition - Start->width / 2;
					mouse_position[1] = event->motion.y - Start->yposition - Start->height / 2;
					break;
				case SDL_MOUSEBUTTONUP:
					double radius = sqrt(pow(mouse_position[0], 2) + pow(mouse_position[1], 2)) + 10;
					std::cout << radius << std::endl;
					if (radius < double(Start->width) / 2) {
						Start_game = true;
					}
					break;
				}
			}
			Start->draw(window_c);
			window_c->clear();
		}
	}
}