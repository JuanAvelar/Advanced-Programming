#ifndef Platform_H
#define Platform_H

#include <string> // C++ standard string class
#include "MoveableObject.h"


class Platform : public MoveableObject {  /**Inheritance of platform from Movableobject*/
public:
	Platform(const Window &window, GameElement::Color color);	/**Platform constructor (only colour)*/
	Platform(const Window &window, GameElement::Size size, const std::string &image_path); /**Platform constructor including size and path of image*/
	~Platform(); // destructor

//	virtual std::string toString() const override;			/*?*/
	void keyInput(SDL_Event &event);						/** Function to assaign input keys for platform movement*/

	void draw(Window *platform_window) const;				/*?*/

	virtual void move(GameElement *right_wall, GameElement *left_wall);  /*?*/

	GameElement::ElementDestroyed Bounce(GameElement * ball);

private:
	int _r, _g, _b, _a;
	SDL_Texture *platform = nullptr;
	//empty for now (unless we want to add more later), but should not be necessary
};

#endif // Platform_HH