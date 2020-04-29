#include <Utils.h>
#include <Geometry.h>

Polygone *PolygoneFactory::createRandom(
	const Vec2d &position,	//Position
	float min_radius,		//Minimum length of a vector from the center of the polygone
	float max_radius,		//Maximum length of a vector from the center of the polygone
	float granularity,		//Number of points
	float min_angle_vary,	//Minimum variation of the angle
	float max_angle_vary)	//Maximum variation of the angle
{
	Polygone *polygone = new Polygone();
	for (double angle = 0; angle < 2 * PI; angle += 2 * PI / granularity)
	{
		auto radius_gen = alea_generator(min_radius, max_radius);
		auto angle_vary_gen = alea_generator(min_angle_vary, max_angle_vary);

		double angle_vary_radians = (2 * PI / granularity) * angle_vary_gen() / 100;
		double rand_angle = angle + angle_vary_radians - (PI / granularity);
		double radius = radius_gen();
		double x = sin(rand_angle) * radius;
		double y = -cos(rand_angle) * radius;
		polygone->addVertice(Vec2d(x, y) + position);
	}

	return polygone;
}
