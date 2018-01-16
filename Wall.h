#ifndef Wall_H
#define Wall_H
#include "Window.h"
#include "GameElement.h"

/**Wall generates a colored rectangle and manages functions accordingly*/
class Wall : public GameElement {
public:
	/**introduces 4 types of walls*/
	enum Wall_type { up, down, right, left };

public:
	Wall(SDL_Color color, Wall_type wallside);
	~Wall(); // nonvirtual destructor


	void draw(Window *window_wall) const;

	GameElement::ElementDestroyed Bounce(GameElement * ball);

private:
	/**Type of wall used, selected when wall is generated in a game launch function*/
	Wall_type wallside_pick;
	
};

#endif // Wall_H
