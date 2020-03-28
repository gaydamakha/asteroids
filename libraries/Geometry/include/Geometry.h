#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "polygone.h"
#include "polygone_factory.h"
#include "shape.h"
#include "shape_with_vertices.h"
#include "vec2.h"

namespace Geometry
{
    inline double degtorad(double angle)
    {
        return angle / 180.0 * M_PI;
    }
}

#endif