#ifndef POLYGONE_FACTORY_H
#define POLYGONE_FACTORY_H

#include <math.h>
#include <Utils.h>
// #include "polygone_factory.h"
#include "vec2.h"

namespace PolygoneFactory
{
	template<typename ...Points>
	Polygone* createPolygone(const Vec2d& position, Points const&... points);

	Polygone* createRandomPolygone(const Vec2d& position, float min_radius, float max_radius, float granularity, float min_angle_vary, float max_angle_vary);
}


template<typename ...T>
Polygone* PolygoneFactory::createPolygone(const Vec2d& position, T const&... points)
{
	static_assert(AllVec2d<T...>::value, "All values should be Vec2d");
	Polygone* polygone = new Polygone();
	std::vector<Vec2d> ps = {{ points ...}};
	for (auto point: ps)
	{
		polygone->addVertice(point + position);
	}

	return polygone;
}

#endif