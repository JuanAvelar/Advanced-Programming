#pragma once
#include <string>
#include <SDL2/SDL.h>
#include <vector>

/**Declaring class Window*/
class Window {  
public:
	/**Window constructor*/
	Window(const std::string &title, int width, int height);

	/**Poll events function to coordinate key events*/
	void pollEvents(SDL_Event &event);
	/**Function to set background color on window and update*/
	void clear()const; 
	/**Returns if the window is closed or not*/
	inline bool isClosed() const { return _closed; }

	/**Declaring window to null pointer*/
	SDL_Window *_window = nullptr;//should be private

	/**Virtual Destroyer of window*/
public:
	virtual ~Window();
	/**Boolean to know if window is initialised or not */
private:
	bool init();

private:

	std::string _title;
	int _width = 800;
	int _height = 600;

	bool _closed = false;

	SDL_Surface *_surface;

	/**Declaring renderer and setting to null pointer*/
public:
	SDL_Renderer *_renderer = nullptr;
};