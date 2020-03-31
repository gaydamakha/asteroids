#ifndef SHAPE_H
#define SHAPE_H
#include "vec2.h"

class Shape
{
public:
	virtual const bool isCircular() const = 0;

	virtual const void translate(const Vec2d&) = 0;

	virtual const void rotate(const Vec2d&, double) = 0;
};

#endif