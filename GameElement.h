#ifndef GameElement_H
#define GameElement_H

#include <string>
#include "Controller.h"

class GameElement {
public:								  
	// constructor
	GameElement(int = 0, int = 0, const int = 0, const int = 0);
	virtual ~GameElement() = default; // virtual standard destructor

	int getHeight() const;
	int getWidth() const;

	int getXLocation();
	int getYLocation();

	void destroyGameElement();
	virtual std::string toString() const;

protected:
	int xposition, yposition, height, width;
};

#endif // GameElement_H


