#ifndef WALL_H
#define WALL_H

#include "GameElement.h"


class Wall : public GameElement {
public:
	enum Wall_type { up, down, right, left };

public:
	Wall(SDL_Color color, Wall_type wallside);
	~Wall(); // nonvirtual destructor

	enum Wall_type getWallSide();

	void Wall::draw(Window *window_wall) const;

	GameElement::ElementDestroyed Bounce(GameElement * ball);

protected:
	Wall_type wallside_pick;
	
};

#endif // Wall_H
