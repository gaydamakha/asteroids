#ifndef POLYGONE_FACTORY_H
#define POLYGONE_FACTORY_H

#include <math.h>
#include <Utils.h>
#include "polygone.h"

namespace PolygoneFactory
{
	Polygone* createPolygone(float min_radius, float max_radius, float granularity, float min_angle_vary, float max_angle_vary);
}

#endif