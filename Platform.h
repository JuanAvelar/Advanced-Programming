#ifndef Platform_H
#define Platform_H

#include <string> // C++ standard string class
#include "MoveableObject.h"

class Platform : public MoveableObject {
public:
	Platform(const Window &window, int = 0, int = 0, const int = 0, const int = 0, double = 0.0, double = 0.0, double = 0.0, double = 0.0);
	virtual ~Platform() = default; // virtual destructor

	virtual std::string toString() const override;
	virtual double move() override;


private:
	//empty for now (unless we want to add more later), but should not be necessary
};

#endif // Platform_H