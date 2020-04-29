#ifndef SHAPE_VER_H
#define SHAPE_VER_H

#include <Utils.h>
#include <memory>
#include "vec2.h"
#include "iterable_shape.h"

using Vertice = Vec2d;
using VerticesArray = IterableCollection<Vertice>;

class ShapeWithVertices : public IterableShape<Vertice>
{
protected:
	VerticesArray vertices;

public:
	ShapeWithVertices() {}
	
	ShapeWithVertices(std::initializer_list<Vec2d> v): vertices(v) {}

	const ShapeWithVertices addVertice(const Vec2d &v)
	{
		vertices.push(Vec2d(v));

		return *this;
	}

	const VerticesArray getVertices()
	{
		return vertices;
	}

	const VerticesArray getVertices() const
	{
		return vertices;
	}

	const VerticesArray getData()
	{
		return getVertices();
	}

	const VerticesArray getData() const
	{
		return getVertices();
	}

	const void rotate(const Vec2d &, double);

	const void translate(const Vec2d &);
};
#endif // !SHAPE_H
