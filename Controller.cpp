#include <sstream>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "GameElement.h"
#include "Controller.h"
#include "Ball.h"
#include "Platform.h"
#include "Brick.h"
#include "Wall.h"
#include <vector>
using std::vector;


// constructor
Controller::Controller(int lev, int lif, int sco)
	: level(lev), lifes(lif), score(sco) {}//private

										   /**In this function every function from the game is implemented(top major function)*/
void Controller::launchGame() {
	Window window_c("Breakout", 1000, 600);								/**UI instance*/
	SDL_Event event;													/**Event of keyboard instance*/
	Ball ball(window_c, 100, 100, 20, 20, "pictures/shiny_pinball.png");/**ball instance*/
	Platform platform(window_c, 500, 500, 20, 100, 0, 255, 0, 0);		/**Platform instance*/
	Wall wall(window_c, 590, 0, 600, 10, Wall::right, 255, 0, 0, 0);	/**wall instance*/
	std::cout << "aqui no esta el error\n";
	//Brick brick(window_c,10, 150, 30, 100, 3, 0, 0, 255, 255);
	vector <Brick*> brick;												/**Vector of pointer to brick objects*/
	int number_of_bricks = 0;											/**Counts the number of bricks in the game*/

	switch (level) {
	case 1:
		for (int i = 1; i < 10; i++) {
			for (int f = 0; f < 3; f++) {
				brick.emplace_back(new Brick{ window_c, i * 110 - 100, 150 + f * 40, 30, 100, 3, i * 25, 0, 255 - i * 25, 0 });
				number_of_bricks++;
			}
		}
		break;
	case 2:
		for (int i = 1; i < 10; i++) {
			for (int f = 0; f < 3; f++) {
				brick.emplace_back(new Brick{ window_c, i * 110 - 100, 50 + f * 40, 30, 100, 3, i * 25, 0, 255 - i * 25, 0 });
				number_of_bricks++;
			}
		}
		break;
	}
	
	//...write function to start the game, make a big start button and when clicked the game starts (first need to get level from LevelsGeneration)
	while (!window_c.isClosed()) {
		if (SDL_PollEvent(&event)) {
			platform.move(event);
			window_c.pollEvents(event);
		}
		ball.draw();
		platform.draw();
		//wall.draw();
		for (int i = 1; i < number_of_bricks + 1; i++) {
				//std::cerr << "You are trying to access a direction that does not exist " << sizeof(brick) << "    " << sizeof(brick[0]) << std::endl;
				brick[i - 1]->draw();			
		}
		std::cout << "el error tampoco esta aqui\n";
		window_c.clear();
	}
}

void Controller::endGame() {
	//...write function to end the game
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
//process the user input, we could turn it into an int, e.g. 0 for no input, 1 for left and 2 for right
char Controller::getUserInput() {
	return 0;

}
//get level from level enumeration
void Controller::loadLevel() {

}

/**Constructor of window*/
Window::Window(const std::string &title, int width, int height) :
	_title(title), _width(width), _height(height)
{
	_closed = !init();
}
/**Destructor of window and objects inside*/
Window::~Window() {
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	IMG_Quit();
	SDL_Quit();
}
/**Checks initial conditions to make sense (used by constructor of game window)*/
bool Window::init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cerr << "Failed to initialize SDL.\n";
		return 0;
	}

	if (IMG_Init(IMG_INIT_PNG != IMG_INIT_PNG /*| IMG_INIT_JPG != IMG_INIT_PNG*/)) {
		std::cerr << "Failed to initialize SDL_image.\n";
		return 0;
	}

	_window = SDL_CreateWindow(
		_title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		_width, _height,
		SDL_WINDOW_RESIZABLE);

	if (_window == nullptr) {
		std::cerr << "Failed to create window.\n";
		return 0;
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

	if (_renderer == nullptr) {
		std::cerr << "Failed to create renderer.\n";
		return 0;
	}
	_surface = IMG_Load("pictures/shiny_pinball.png");
	SDL_SetWindowIcon(_window, _surface);

	return true;
}
/**Render backround color*/
void Window::clear()const {
	SDL_RenderPresent(_renderer);
	SDL_SetRenderDrawColor(_renderer, 255, 127, 50, 55);//Here you choose the colors in RBGA of the color of the window
	SDL_RenderClear(_renderer);
}
/**Events of keyboard and mouse*/
void Window::pollEvents(SDL_Event &event) {
	switch (event.type) {
	case SDL_QUIT:
		_closed = true;
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_a:
			std::cout << "You clicked 'A'!\n";
			std::cout << (SDL_GetWindowSurface(_window)->w) << " is width \n";
			break;
		case SDLK_LEFT:
			std::cout << "You clicked left arrow.\n";
			break;
		case SDLK_RIGHT:
			std::cout << "Right.\n";
			break;
		case SDLK_ESCAPE:
			_closed = true;
			break;
		}
	case SDL_MOUSEMOTION:
		std::cout << event.motion.x << ", " << event.motion.y << std::endl;
		break;
	case SDL_MOUSEBUTTONUP:
		std::cout << "You released your mouse.\n";
		break;

	default:
		break;
	}
}