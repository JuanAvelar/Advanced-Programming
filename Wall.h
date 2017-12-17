#ifndef WALL_H
#define WALL_H

#include <string> // C++ standard string class
#include "GameElement.h"


class Wall : public GameElement {
public:
	enum Wall_type { up, down, right, left };

public:
	Wall(GameElement::Color color, Wall_type wallside);
	~Wall(); // nonvirtual destructor

	void setWallSide(Wall_type);
	enum Wall_type getWallSide();

	void Wall::draw(Window *window_wall) const;

	bool Bounce(GameElement * ball, bool *Game_lost);

	std::string toString() const override;

private:
	std::string wallSide;
	std::string wall;
	int _r, _g, _b, _a;
	SDL_Texture *game_wall = nullptr;

protected:
	Wall_type wallside_pick;
	
};

#endif // Wall_H
