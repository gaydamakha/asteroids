#ifndef SHAPE_VER_H
#define SHAPE_VER_H

#include <Utils.h>
#include <memory>
#include "vec2.h"
#include "iterable_shape.h"

using Vertice = Vec2d;
using VerticesArray = IterableCollection<Vertice>;

class ShapeWithVertices: public IterableShape<Vertice>
{
protected:
	VerticesArray vertices;
public:
	void addVertice(const Vec2d& v)
	{
		vertices.push(Vec2d(v));
	}

	const VerticesArray getVertices() const
	{
		return vertices;
	}

	const VerticesArray getData() const
	{
		return getVertices();
	}

	const void rotate(const Vec2d&, double);

	const void translate(const Vec2d&);
};
#endif // !SHAPE_H
