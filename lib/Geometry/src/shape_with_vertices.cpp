#include "shape_with_vertices.h"

const ShapeWithVertices& ShapeWithVertices::rotate(const Vec2d& center, double angle)
{
	for (auto& point: vertices)
	{
		point->rotate(center, angle);
	}

	return *this;
}

const ShapeWithVertices& ShapeWithVertices::translate(const Vec2d& delta)
{
	for (auto& point: vertices)
	{
		*point += delta;
	}

	return *this;
}