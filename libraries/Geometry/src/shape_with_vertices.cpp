#include "shape_with_vertices.h"

const void ShapeWithVertices::rotate(const Vec2d& center, double angle)
{
	for (auto& point: vertices)
	{
		point->rotate(center, angle);
	}
}

const void ShapeWithVertices::translate(const Vec2d& delta)
{
	for (auto& point: vertices)
	{
		*point += delta;
	}
}