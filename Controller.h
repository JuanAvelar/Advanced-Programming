#ifndef Controller_H
#define Controller_H
#include <string>
#include "GameElement.h"
#include <SDL2/SDL.h>
#undef main
#include <vector>
using std::vector;

class Controller {
public:
	// constructor
	Controller(int = 0, int = 0, int = 0);
	virtual ~Controller() = default; // virtual standard destructor

	void launchGame();

	void endGame();
	void showGraphicOutput();
	int checkForCollision();
	void bounceOnObject(int);
	char getUserInput();
	void loadLevel();

private:
	int lifes, score, level;

	//vector <GameElement*> vector_elements = {};
};

class Window{
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

#endif // Controller_H