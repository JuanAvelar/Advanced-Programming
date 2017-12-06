#pragma once
#ifndef WALL_H
#define WALL_H

#include <string> // C++ standard string class
#include "GameElement.h"
#include "MoveableObject.h"
#include "Controller.h"


class Wall : public GameElement, public Window {
private:
	enum Wall_type { up, down, right, left };

public:
	Wall(const Window window, int xposition, int yposition, const int height, const int width, const Wall_type wallSide, int r, int g, int b, int a);
	virtual ~Wall() = default; // virtual destructor

	void setWallSide(Wall_type);
	Wall_type getWallSide();
	MoveableObject bounceOnObject(MoveableObject);

	virtual std::string toString() const override;

private:
	Wall_type wallSide;
	Wall_type wall;

};

#endif // Wall_H
