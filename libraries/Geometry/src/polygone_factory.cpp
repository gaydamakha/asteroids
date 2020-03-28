#include <Utils.h>
#include <Geometry.h>

Polygone* PolygoneFactory::createPolygone(
		const Vec2d& position,
		float min_radius,
		float max_radius,
		float granularity,
		float min_angle_vary,
		float max_angle_vary)
	{
		Polygone* polygone = new Polygone();
		for (double angle = 0; angle < 2 * M_PI; angle += 2 * M_PI / granularity)
		{
			auto radius_gen = alea_generator(min_radius, max_radius);
			auto angle_vary_gen = alea_generator(min_angle_vary, max_angle_vary);

		    double angle_vary_radians = (2 * M_PI / granularity) * angle_vary_gen() / 100;
			double rand_angle = angle + angle_vary_radians - (M_PI / granularity);
			double radius = radius_gen();
			double x = sin(rand_angle) * radius;
			double y = -cos(rand_angle) * radius;
			polygone->addVertice(Vec2d(x, y) + position);
		}

		return polygone;
	}
