#ifndef POLYGONE_FACTORY_H
#define POLYGONE_FACTORY_H

#include <cmath>
#include <Utils.h>
#include "vec2.h"

//TODO: replace pointer by smart pointers
namespace PolygoneFactory
{
template <typename... T>
Polygone *create(const Vec2d &position, T const &... points);

Polygone *createRandom(const Vec2d &position, float min_radius, float max_radius, float granularity, float min_angle_vary, float max_angle_vary);
} // namespace PolygoneFactory

template <typename... T>
Polygone *PolygoneFactory::create(const Vec2d &position, T const &... points)
{
	static_assert(AllVec2d<T...>::value, "All values should be Vec2d");
	Polygone *polygone = new Polygone();
	std::vector<Vec2d> ps = {{points...}};
	for (auto point : ps)
	{
		polygone->addVertice(point + position);
	}

	return polygone;
}

#endif