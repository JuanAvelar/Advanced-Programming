#ifndef WALL_H
#define WALL_H

#include <string> // C++ standard string class
#include "GameElement.h"


class Wall : public GameElement {		/**Class wall inheriting from GameElement*/
public:
	enum Wall_type { up, down, right, left }; /**Declares a type of your own, in this case being a wall type*/

public:
	Wall(GameElement::Color color, Wall_type wallside);	/**Public: Constructor elements of wall*/
	~Wall();		/**Non-virtual destructor of wall*/

	void setWallSide(Wall_type);	/**Declaring function setwallside*/
	enum Wall_type getWallSide();	/***/

	void draw(Window *window_wall) const;  /**Declaring draw function*/

	GameElement::ElementDestroyed Bounce(GameElement * ball);  /**Performs bounce on all objects and depends on amount of balls in the game*/

	//std::string toString() const override; 

/** Private variables of class wall*/
private:
	std::string wallSide;		
	std::string wall;
	int _r, _g, _b, _a;
	SDL_Texture *game_wall = nullptr;

protected:
	Wall_type wallside_pick;
	
};

#endif // Wall_H
