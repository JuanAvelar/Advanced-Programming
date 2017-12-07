#include "Window.h"
#include <sstream>
#include <SDL2/SDL_image.h>
#include <iostream>



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
		case SDLK_ESCAPE:
			_closed = true;
			break;
		}
	default:
		break;
	}
}
