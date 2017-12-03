#ifndef WALL_H
#define WALL_H

#include <string> // C++ standard string class
#include "GameElement.h"


class Wall : public GameElement {
public:
	Wall(int = 0, int = 0, const int = 0, const int = 0, std::string=" ");
	virtual ~Wall() = default; // virtual destructor

	void setWallSide(std::string);
	std::string getWallSide();

	virtual std::string toString() const override;

private:
	std::string wallSide;
	std::string wall;
};

#endif // Wall_H
