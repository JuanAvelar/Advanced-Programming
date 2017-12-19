#ifndef Platform_H
#define Platform_H

#include <string> // C++ standard string class
#include "MoveableObject.h"

/**Inheritance of Platform class from MovableObject class*/
class Platform : public MoveableObject {  
public:
	/**Constructor of Platrom to define color*/
	Platform(const Window &window, GameElement::Color color); 
	/**Construction of platform*/
	Platform(const Window &window, GameElement::Size size, const std::string &image_path); 
	/**Platform Destructor*/
	~Platform(); 

	//virtual std::string toString() const override;
	/**keyInput function to set events of key pressed*/
	void keyInput(SDL_Event &event);	
	/**Draw function of platform*/
	void draw(Window *platform_window) const; 
	/**Virtual move funtion*/
	virtual void move(GameElement *right_wall, GameElement *left_wall);
	/**Function that returns the type of object destroyed*/
	GameElement::ElementDestroyed Bounce(GameElement * ball);

	/**Private variables of platform Declaration*/
private:
	int _r, _g, _b, _a;
	SDL_Texture *platform = nullptr;
	//empty for now (unless we want to add more later), but should not be necessary
};

#endif // Platform_HH