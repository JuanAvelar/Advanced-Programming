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
#include <ctime>
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
	Ball* ball = new Ball{ window_c, GameElement::small, "pictures/shiny_pinball.png" };		/**ball instance*/
	Platform* platform= new Platform{ window_c, GameElement::small, "pictures/start.png" };												/**Platform instance*/
	
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
	Start_menu(&event, &window_c);

	//...write function to start the game, make a big start button and when clicked the game starts (first need to get level from LevelsGeneration)
	while (!window_c.isClosed() && !Game_lost) {
		if (SDL_PollEvent(&event)) {
			event_flag = true;
			poll(event, &window_c, &Game_elements);//checks if the window has changed its size
		}
		//std::cout << "busy" << std::endl;
		timeElapsed = SDL_GetTicks();//Gets time since the first time sdl library was accessed
		
		if ((timeElapsed % cycle_time < cycle_time*duty_cycle_percentage) && !you_shall_not_pass) {//in this if output is updated time in milliseconds
			if (iterator == iterations_per_cycle - 1) {	you_shall_not_pass = true;}//The cycle repeated 3 times in the same millisecond this is to ensure it just iterates n times in that millisecond
			for (auto moving : Moveable_objects) {moving->move(right_wall, left_wall);}			
			bounceOnObject(&Game_elements, &Moveable_objects, &window_c);
			iterator++;
		}
		else if (timeElapsed % cycle_time > cycle_time/2 && timeElapsed % cycle_time < cycle_time / 2 + time_for_graphic_output) {
			showGraphicOutput(&window_c, &Game_elements);
			 //std::cout << time << std::endl; 
		}
		else if (timeElapsed % cycle_time > cycle_time*duty_cycle_percentage) {//waits until moving the ball is done
			if (you_shall_not_pass) {
				you_shall_not_pass = false;
				iterator = 0;
			}
			if (event_flag) {
				for (int i = 0; i < (signed)Moveable_objects.size() - 1; i++){
					Ball *ball_pointer = dynamic_cast<Ball*> (Game_elements[i]);
				platform->keyInput(event, ball_pointer);//platform moves when an event happens
			}
					window_c.pollEvents(event);//checks for events happening in the window such as keyboard and change window size
					event_flag = false;
			}
		}
		if (Game_elements.size() < 5 + Moveable_objects.size()) { break; }//when number of elements is less than 6 plus the amount of balls, break because all the bricks have been cleared.
			
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
void Controller::bounceOnObject(vector <GameElement*>* Game_elements, vector <MoveableObject*>* Moveable_objects, Window * window_c) {
	/**vector to state which game elements will be erased after the range based for*/
	for (int c = 0; c < (signed)Moveable_objects->size()-1;c++) {
		for (int i = 0; i < (signed)(Game_elements->size()); i++) {//check for a brick collision
			if (i != c && (*Game_elements)[i] != nullptr && (*Game_elements)[c] != nullptr) {//skips the collision between the ball and the same ball, because it is phisically not possible
				GameElement::ElementDestroyed Element_destructed = (*Game_elements)[i]->Bounce((*Game_elements)[c]);//the element in c is the ball //Returns true if brick is destroyed
				if (Element_destructed == GameElement::destroybrick) { 
					(*Game_elements)[i] = nullptr;
				}//if brick is destroyed then it gets rid of the vector element
				if (Element_destructed == GameElement::destroyball) {
					//the size of Moveable_objects is the amount of balls + 1 (platform)
					if (Moveable_objects->size() < 3) {
						lives--;

						if (lives < 1) {
							Game_lost = true;
							(*Game_elements)[c] = nullptr;//Setting it to null ptr, it cannot be erased until the pc is out of the second for loop
							(*Moveable_objects)[c] = nullptr;
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
						(*Moveable_objects)[c] = nullptr;
						//Moveable_objects->erase(Moveable_objects->begin() + c);
						//delete also place of the number of ball
					}
				}
			}
			
		}
		//evaluates whether the direction of the balls needs to be changed and if so does so
	}

	//erasing elements from vector if they are nullptr
	int it_1 = 0;
	while (it_1 < signed(Game_elements->size())) {//manual iteration to prevent undefined behavior
		//std::cout << it_1 << std::endl;
		if ((*Game_elements)[it_1] == nullptr) {
			Game_elements->erase(Game_elements->begin() + it_1);//erase previously defined vector spaces to be whiped

			int it_2 = 0;
			while (it_2 < (signed)(Moveable_objects->size() - 1)) {//a while loop is used to compare the numbers inside Moveable_objects and all stuff to be erased, if it matches then position is erased from vector.
				if ((*Moveable_objects)[it_2] == nullptr) {
					Moveable_objects->erase(Moveable_objects->begin() + it_2);
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
	//correcting direction of the ball and management of powerups.
	for (int c = 0; c < (signed)Moveable_objects->size()-1; c++) {
		if ((*Moveable_objects)[c]->_yflip == true) {
			(*Moveable_objects)[c]->_ydirection = -(*Moveable_objects)[c]->_ydirection;
		}
		if ((*Moveable_objects)[c]->_xflip == true) {
			(*Moveable_objects)[c]->_xdirection = -(*Moveable_objects)[c]->_xdirection;
		}
		//reset the change of direction to be false as to not endlessly change direction
		(*Moveable_objects)[c]->_yflip = false;
		(*Moveable_objects)[c]->_xflip = false;
		
		//Manage powerups individually
		if ((*Moveable_objects)[c]->powerUp == GameElement::biggerBall) {
			(*Moveable_objects)[c]->height += 10;
			(*Moveable_objects)[c]->width += 10;	
		}
		if ((*Moveable_objects)[c]->powerUp == GameElement::biggerPlatform) {
			(*Moveable_objects)[Moveable_objects->size() - 1]->width += 50;
			(*Moveable_objects)[Moveable_objects->size() - 1]->xposition -= 25;
		}
		if ((*Moveable_objects)[c]->powerUp == GameElement::extraBall) {	
			Moveable_objects->emplace(Moveable_objects->begin()+c+1, new Ball{ (*window_c), GameElement::small, "pictures/shiny_pinball.png" });
			Game_elements->emplace(Game_elements->begin() + c + 1, (*Moveable_objects)[c+1] );
		}
		(*Moveable_objects)[c]->powerUp = GameElement::none;
	}
}


//You must disinherit the window object to the rest of the objects
void Controller::set_brick_level(int level, vector <GameElement*>* elements) {
	srand((unsigned int)time(0)); //Ensures that the powerup locations will be random each time starting up the game.
	switch (level) {
	case 1:
		for (int i = 1; i < 10; i++) {
			for (int f = 0; f < 3; f++) {
				bool powerups = true;
				elements->emplace_back(new Brick{ i * 110 - 100, 150 + f * 40, 30, 100, 1, Uint8(255), Uint8(0), Uint8(255), Uint8(0), powerups });
			}
		}
		break;
	case 2:
		for (int i = 1; i < 10; i++) {
			for (int f = 0; f < 4; f++) {
				bool powerups = true;
				elements->emplace_back(new Brick{ i * 110 - 100, 50 + f * 40, 30, 100, 1, Uint8(255), Uint8(0), Uint8(255), Uint8(0), powerups });

			}
		}
		break;
	case 3:
		for (int i = 1; i < 10; i++) {
			for (int f = 0; f < 5; f++) {
				bool powerups = true;
				elements->emplace_back(new Brick{ i * 110 - 100, 50 + f * 40, 30, 100, 1, Uint8(255), Uint8(0), Uint8(255), Uint8(0), powerups });

			}
		}
		break;
	}
}

/**Destroys all bricks if level is lost*/
void Controller::destroy_level(int level, vector <GameElement*>* elements) {
	(void)level;
	for (int i = 0; i < signed(elements->size()); i++) {
		delete (*elements)[i];
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