#ifndef SHAPE_H
#define SHAPE_H

#include "vec2.h"

class Shape
{
public:
	virtual const bool isCircular() const { return false; }
	//Moves shape to the needed direction
	virtual const Shape& translate(const Vec2d &) { return *this; }
	//Rotates the shape
	virtual const Shape& rotate(const Vec2d &, double) { return *this; }
};

#endif