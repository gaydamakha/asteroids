#ifndef SHAPE_VER_H
#define SHAPE_VER_H

#include <memory>
//Another way to include it?
#include <Utils.h>
#include "vec2.h"
#include "shape.h"

//Because circle have no vertice
class ShapeWithVertices: public IterableCollection<std::shared_ptr<Vec2d>>, public Shape
{
public:
	virtual const std::vector<std::shared_ptr<Vec2d>> getVertices() const = 0;
};
#endif // !SHAPE_H
