#include "Platform.h"
using namespace std;

// constructor
Platform::Platform(const Window &window, int xposition, int yposition, const int	height, const int width, double xdirection, double ydirection, double xspeed, double yspeed)
	: MoveableObject( xposition, yposition, height, width) {
	//... no extra attributes to include?
}




// return a string representation of Moveable Object's information --> implements abstract class function
string Platform::toString() const {
	return "0";
	// make string output
}

//function move --> implements abstract class function
double Platform::move() {
	return 0;
	//create the move function --> determined by userinput which we get in the controller
}

