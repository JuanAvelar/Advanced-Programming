#ifndef WALL_H
#define WALL_H

#include <string> // C++ standard string class
#include "GameElement.h"

/**Class wall inheriting from GameElement*/
class Wall : public GameElement {		
public:
	/**Declares a type of your own, in this case being a wall types*/
	enum Wall_type { up, down, right, left }; 

public:
	/**Public: Constructor elements of wall*/
	Wall(GameElement::Color color, Wall_type wallside);	
	/**Non-virtual destructor of wall*/
	~Wall();		
	/**Declaring function setwallside*/
	void setWallSide(Wall_type);	
	/**Declares a type of your own, in this case being a side wall types*/
	enum Wall_type getWallSide();	
	/**Declaring draw function of wall*/
	void draw(Window *window_wall) const;  
	/**Performs bounce on all objects and depends on amount of balls in the game*/
	GameElement::ElementDestroyed Bounce(GameElement * ball);  

	//std::string toString() const override; 

/** Private variables declaration of class wall*/
private:
	std::string wallSide;		
	std::string wall;
	int _r, _g, _b, _a;
	SDL_Texture *game_wall = nullptr;

protected:
	Wall_type wallside_pick;
	
};

#endif // Wall_H
