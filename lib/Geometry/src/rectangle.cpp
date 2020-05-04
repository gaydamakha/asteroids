#include "rectangle.h"

Rectangle::Rectangle(double w, double h) : width(w), height(h)
{
    double w2 = w / 2;
    double h2 = h / 2;
    // The center of the shape is Vec2d(0., 0.)
    ShapeWithVertices::addVertice(Vec2d(w2, h2)).addVertice(Vec2d(-w2, h2)).addVertice(Vec2d(-w2, -h2)).addVertice(Vec2d(w2, -h2));
}