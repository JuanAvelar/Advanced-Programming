#ifndef Window_H
#define Window_H
#include <string>
#include <SDL2/SDL.h>
#include <vector>

/**Manages the window attributes aswell as all pointers involving rendering, (textures are not part of this class)*/
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

public:
	/**Virtual Destroyer of window*/
	virtual ~Window();
private:
	/**Boolean function to know if window is correctly initialized */
	bool init();

private:
	/**This will be the title of the window*/
	std::string _title;
	/**Width of the only window*/
	int _width = 800;
	/**Height of the only window*/
	int _height = 600;
	/**Variable that tells if the window is closed or still open*/
	bool _closed = false;
	/**A pointer to a structure that contains a collection of pixels used in software blitting*/
	SDL_Surface *_surface;

public:
	/**Render pointer, called when something needs to be drawn, NOTE: there can only be one renderer pointer per window*/
	SDL_Renderer *_renderer = nullptr;
};

#endif // Window_H