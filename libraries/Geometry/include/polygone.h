#ifndef POLYGONE_H
#define POLYGONE_H

#include <Utils.h>
#include "shape_with_vertices.h"

struct RandomPolygoneDesc
{
	const double min_radius;
	const double max_radius;
	const double granularity;
	const double min_angle_vary;
	const double max_angle_vary;
};

class Polygone : public ShapeWithVertices
{
public:
	using ShapeWithVertices::ShapeWithVertices;

	Polygone(double, double, double, double, double);

	Polygone(const RandomPolygoneDesc&);

	const bool isCircular() const;
};

#endif
