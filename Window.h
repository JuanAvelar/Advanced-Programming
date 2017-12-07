#pragma once
#include <string>
#include "GameElement.h"
#include <SDL2/SDL.h>
#include <vector>


class Window {
public:
	Window(const std::string &title, int width, int height);
	~Window();

	void pollEvents(SDL_Event &event);
	void clear()const;

	inline bool isClosed() const { return _closed; }

	SDL_Window *_window = nullptr;//should be private

private:
	bool init();

private:
	std::string _title;
	int _width = 800;
	int _height = 600;

	bool _closed = false;

	SDL_Surface *_surface;

protected:
	SDL_Renderer *_renderer = nullptr;
};
