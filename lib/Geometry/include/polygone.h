#ifndef POLYGONE_H
#define POLYGONE_H

#include <Utils.h>
#include "shape_with_vertices.h"

struct RandomPolygoneDesc
{
	double min_radius;
	double max_radius;
	unsigned granularity;
	double min_angle_vary;
	double max_angle_vary;
};

class Polygone : public ShapeWithVertices
{
public:
	using ShapeWithVertices::ShapeWithVertices;

	Polygone(double, double, unsigned, double, double);

	Polygone(const RandomPolygoneDesc &);

	inline const bool isClosed() const { return true; }
};

#endif
