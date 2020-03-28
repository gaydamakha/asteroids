#ifndef POLYGONE_H
#define POLYGONE_H

#include <vector>
#include <Utils.h>
#include "vec2.h"
#include "shape_with_vertices.h"

class Polygone : public ShapeWithVertices
{
public:
	using ShapeWithVertices::ShapeWithVertices;

	const bool isCircular() const;
};

#endif
