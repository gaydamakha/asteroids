#ifndef POLYGONE_H
#define POLYGONE_H

#include <vector>
#include "vec2.h"
#include <Utils.h>
#include "shape_with_vertices.h"

class Polygone : public ShapeWithVertices
{
public:
	using ShapeWithVertices::ShapeWithVertices;

	void addVertice(const Vec2d& v)
	{
		push(std::make_shared<Vec2d>(v));
	}

	const std::vector<std::shared_ptr<Vec2d>> getVertices() const
	{
		return collection;
	}

	void dummy() {}
};

#endif
