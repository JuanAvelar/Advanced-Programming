#include "Window.h"
#include "Controller.h"
#include <SDL2/SDL_image.h>
#include <iostream>
#include <sstream>

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
	std::cout << "Why is window being destroyed??\n";
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
	/**Defining characteristics of window*/
	_window = SDL_CreateWindow(
		_title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		_width, _height,
		SDL_WINDOW_RESIZABLE);

	/**Checking if window is created*/
	if (_window == nullptr) { 
		std::cerr << "Failed to create window.\n";
		return 0;
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

	/**checking if renderer is created*/
	if (_renderer == nullptr) { 
		std::cerr << "Failed to create renderer.\n";
		return 0;
	}/**Loading image surface*/
	_surface = IMG_Load("pictures/shiny_pinball.png");
	SDL_SetWindowIcon(_window, _surface);
	SDL_SetWindowMinimumSize(_window, 1000, 600);
	//SDL_SetWindowMaximumSize(_window, 1001, 601);

	return true;
}
/**Render backround color*/
void Window::clear()const {
	/**Use this function to update the screen with any rendering performed since the previous call.*/
	SDL_RenderPresent(_renderer);					
	/**Use this function to set the color used for drawing operations*/
	SDL_SetRenderDrawColor(_renderer, 0, 0, 50, 55);
	/**Use this function to clear the current rendering target with the drawing color.*/
	SDL_RenderClear(_renderer);						
}
/**Events of keyboard and mouse to close window*/
void Window::pollEvents(SDL_Event &event) {
	switch (event.type) {
	case SDL_QUIT:
		_closed = true;
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_ESCAPE:
			_closed = true;
			break;
		default:
			break;
		}
	default:
		break;
	}
};
