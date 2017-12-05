#include <sstream>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "GameElement.h"
#include "Controller.h"
#include "Ball.h"
#include "Platform.h"
#include <vector>

// constructor
Controller::Controller(int lev, int lif, int sco)
	: level(lev), lifes(lif), score(sco) {}//private

/**In this function every function from the game is implemented(top major function)*/
void Controller::launchGame() {
	Window window_c("Breakout", 1000, 600);
	SDL_Event event;
	Ball ball(window_c, 100, 100, 20, 20, 200, 200,"pictures/shiny_pinball.png");
	Platform platform(window_c, 500, 500, 20, 100, 0, 0, 255, 255);

	vector_elements = { &platform };

	//...write function to start the game, make a big start button and when clicked the game starts (first need to get level from LevelsGeneration)
	while (!window_c.isClosed()) {
		//pollEvents(window, rect, rect2);
		//rect.draw();
		//rect2.draw();
		if (SDL_PollEvent(&event)) {
			window_c.pollEvents(event);
		}
		ball.draw();
		platform.draw();
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