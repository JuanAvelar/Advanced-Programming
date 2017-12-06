#ifndef WALL_H
#define WALL_H

#include <string> // C++ standard string class
#include "GameElement.h"


class Wall : public GameElement, public Window {
public:
	enum Wall_type { up, down, right, left };

public:
	Wall(const Window window, int xposition, int yposition, const int height, const int width, const Wall_type wallSide, int r, int g, int b, int a);
	virtual ~Wall() = default; // virtual destructor

	void setWallSide(Wall_type);
	std::string getWallSide();
	void Wall::draw() const;

	virtual std::string toString() const override;

private:
	std::string wallSide;
	std::string wall;
	int _r, _g, _b, _a;
	SDL_Texture *game_wall = nullptr;
	
};

#endif // Wall_H
