#include "Platform.h"

using namespace std;

// constructor
Platform::Platform(const Window &window, int xposition, int yposition, const int height, const int width, int r, int g, int b, int a)
	:Window(window), MoveableObject(xposition, yposition, height, width, _xdirection, _ydirection, _speed), _r(r), _g(g), _b(b), _a(a) {
	//... no extra attributes to include?
}

/*Platform::~Platform() {
//SDL_DestroyTexture(platform); //this is only for the images
}*/

void Platform::draw() const {
	SDL_Rect platform_draw = { xposition, yposition, width, height };
	if (platform) {
		SDL_RenderCopy(_renderer, platform, nullptr, &platform_draw);
	}
	else {
		SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
		SDL_RenderFillRect(_renderer, &platform_draw);
	}
}

// return a string representation of Moveable Object's information --> implements abstract class function
string Platform::toString() const {
	return "0";
	// make string output
}

//function move --> implements abstract class function
void Platform::move(SDL_Event &event) {
	switch (event.type) {

	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_LEFT:
			if (xposition > 0) {
				xposition -= 100;
			}
			break;
		case SDLK_RIGHT:
			if (xposition < 900) {
				xposition += 100;
			}
			break;
		}
	default:
		break;
	}

	//create the move function --> determined by userinput which we get in the controller
}


MoveableObject Platform::bounceOnObject(MoveableObject ball) {
	//if ball hits the top, output direction will totally depend on the impact position
	//if ball hits the side, ball bounces of with same angle

	//ball hits side: --> then change the ydirection
	if (ball.getXLocation() + ball.getWidth() < this->getXLocation() ||
		ball.getXLocation() > this->getXLocation() + this->getWidth()) {
		double ydir = ball.getYDirection();
		ball.setYDirection(-ydir);
	}
	else { //ball hits the top

		   //calculate impact place wrt platform (middle=0%, left=-100%, right=100%)
		   // we first need to know the middle of the ball
		int middle_ball = ball.getXLocation() + ball.getWidth();

		int leftEdgePlatform = this->getXLocation();
		int rightEdgePlatform = leftEdgePlatform + this->getWidth();

		//remap values form left to right edge of platform to values between -1 and 1
		double collisionPoint = -1 + (2 / (rightEdgePlatform - leftEdgePlatform)) * (middle_ball - leftEdgePlatform);
		//output = output_start + ((output_end - output_start) / (input_end - input_start)) * (input - input_start)

		//set the new directions for the ball
		ball.setXDirection(collisionPoint);
		ball.setYDirection(1 - collisionPoint);

	}

	return ball;
}
