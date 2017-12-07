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


// *Draw the platform*
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


//function move --> implements abstract class function
void Platform::move(SDL_Event &event) {
	switch (event.type) {

	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_LEFT:
			if (xposition > 0) {
				xposition -= 50;
			}
			break;
		case SDLK_RIGHT:
			if (xposition < (1000-getWidth())) {
				xposition += 50;
			}
			break;
		}
	default:
		break;
	}

	//create the move function --> determined by userinput which we get in the controller
}



void Platform::platformBounce(MoveableObject &ball) {
	//if ball hits the top, output direction will totally depend on the impact position
	//if ball hits the side, ball bounces of with same angle

	//ball hits top: --> then change the ydirection
	
	
	if (ball.getYLocation() + ball.getHeight() > this->getYLocation() && ball.getYLocation() + ball.getHeight() < this->getYLocation() + this->getHeight() && 
		ball.getXLocation() + ball.getWidth() > this->getXLocation() && ball.getXLocation() < this->getXLocation() + this->getWidth() )//|| ball.getXLocation() > this->getXLocation() + this->getWidth()) 
	{

		//remap values form left to right edge of platform to values for xdir between -0.9 and 0.9
		double collisionPoint = (-0.9 + 1.8 * (((double)ball.getXLocation()+ 0.5 * (double)ball.getWidth()-(double)this->getXLocation())/(double)getWidth()));
		//output = output_start + ((output_end - output_start) / (input_end - input_start)) * (input - input_start)

		//set the new directions for the ball
		ball.setXDirection(collisionPoint);
		//set the y direction based on the total direction length being 1
		ball.setYDirection(-sqrt(1 - pow(collisionPoint,2)));
	}
}

