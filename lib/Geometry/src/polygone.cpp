#include "polygone.h"

//Calling parent constructor allows to push in vertices iterable collection
Polygone::Polygone(double min_radius, double max_radius, unsigned granularity, double min_angle_vary, double max_angle_vary) : ShapeWithVertices()
{
	for (double angle = 0; angle < 2 * PI; angle += 2 * PI / granularity)
	{
		auto radius_gen = alea_generator(min_radius, max_radius);
		auto angle_vary_gen = alea_generator(min_angle_vary, max_angle_vary);
		double angle_vary_radians = (2 * PI / granularity) * angle_vary_gen() / 100;
		double rand_angle = angle + angle_vary_radians - (PI / granularity);
		double radius = radius_gen();
		double x = sin(rand_angle) * radius;
		double y = -cos(rand_angle) * radius;
		vertices.push(Vec2d(x, y));
	}
}

//The use of delegating constructor
Polygone::Polygone(const RandomPolygoneDesc &d) : Polygone(d.min_radius, d.max_radius, d.granularity, d.min_angle_vary, d.max_angle_vary) {}
