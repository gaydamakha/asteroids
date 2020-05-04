#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "vec2.h"
#include "shape_with_vertices.h"

class Rectangle : public ShapeWithVertices
{
    const double width, height;

public:
    Rectangle(double w, double h);

    inline const double getWidth() const { return width; }
    inline const double getHeight() const { return height; }
    inline const bool isClosed() const { return true; }
};

#endif