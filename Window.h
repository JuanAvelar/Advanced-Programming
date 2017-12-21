#pragma once
#include <string>
#include <SDL2/SDL.h>
#include <vector>


class Window {
public:
	Window(const std::string &title, int width, int height);


	void pollEvents(SDL_Event &event);
	void clear()const;

	inline bool isClosed() const { return _closed; }

	SDL_Window *_window = nullptr;//should be private
public:
	virtual ~Window();

private:
	bool init();

private:

	std::string _title;
	int _width = 800;
	int _height = 600;
	bool _closed = false;
	SDL_Surface *_surface;

public:
	SDL_Renderer *_renderer = nullptr;
};