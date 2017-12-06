#ifndef Ball_H
#define Ball_H

#include <string> // C++ standard string class
#include "MoveableObject.h"
#include "Controller.h"
#include "Ball.h"

class Ball : public MoveableObject, public Window {
public:
	Ball(const Window &window, int xposition, int yposition, const int height, const int width, const std::string &image_path);
	~Ball(); // normal destructor

	virtual std::string toString() const override;
	virtual double move() override;
	void serveBall(SDL_Event &event);
	double getXDirection();
	double getYDirection();
	void setXDirection(double xdirection);
	void setYDirection(double ydirection);

	void wallBounce();

	MoveableObject bounceOnObject(MoveableObject) ;

	void draw() const;

private:
	double xposd, yposd;
	int _r, _g, _b, _a;
	SDL_Texture *pinball = nullptr;

};

#endif // Ball_H
