#ifndef WALL_H
#define WALL_H

#include <string> // C++ standard string class
#include "GameElement.h"


class Wall : public GameElement {
public:
	enum Wall_type { up, down, right, left };

public:
	Wall( int xposition, int yposition, const int height, const int width, int r, int g, int b, int a, Wall_type wallside);
	~Wall(); // nonvirtual destructor

	void setWallSide(Wall_type);
	std::string getWallSide();

	void Wall::draw(Window *window_wall) const;

	std::string toString() const override;

private:
	std::string wallSide;
	std::string wall;
	int _r, _g, _b, _a;
	SDL_Texture *game_wall = nullptr;
	
};

#endif // Wall_H
