#ifndef SHAPE_VER_H
#define SHAPE_VER_H

#include <Utils.h>
#include "vec2.h"
#include "shape.h"

using Vertice = Vec2d;
using VerticesArray = IterableCollection<Vertice>;

class ShapeWithVertices : public Shape
{
protected:
	VerticesArray vertices;

public:
	ShapeWithVertices() {}

	ShapeWithVertices(unsigned size) : vertices(size) {}
	
	ShapeWithVertices(const VerticesArray& v): vertices(v) {}

	ShapeWithVertices& addVertice(const Vec2d &v)
	{
		vertices.push(Vec2d(v));

		return *this;
	}

	VerticesArray& getVertices()
	{
		return vertices;
	}

	const VerticesArray& getVertices() const
	{
		return vertices;
	}

	const ShapeWithVertices& rotate(const Vec2d &, double);

	const ShapeWithVertices& translate(const Vec2d &);
};
#endif // !SHAPE_H
