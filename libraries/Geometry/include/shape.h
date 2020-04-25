#ifndef SHAPE_H
#define SHAPE_H

#include "vec2.h"

class Shape
{
public:
	virtual const bool isCircular() const { return false; }

	virtual const void translate(const Vec2d &) {}

	virtual const void rotate(const Vec2d &, double) {}
};

#endif