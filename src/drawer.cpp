#include <Geometry.h>
#include <Utils.h>
#include "interface/drawer.h"

void Drawer::drawPolygone(const Polygone &polygone, const Color &color) const
{
	setDrawColor(color);
	auto vertices = polygone.getVertices();

	for (auto i = vertices.begin(); i < --vertices.end(); ++i)
	{
		auto v1 = **i;
		auto v2 = **vertices.next(i);
		drawLineF(v1.getX(), v1.getY(), v2.getX(), v2.getY());
	}
	auto last = **(--vertices.end());
	auto first = **vertices.begin();
	drawLineF(last.getX(), last.getY(), first.getX(), first.getY());
}

void Drawer::drawShapeWithVertices(const Vec2d& pos, const ShapeWithVertices &shape, const Color &color) const
{
	setDrawColor(color);
	auto vertices = shape.getVertices();

	for (auto i = vertices.begin(); i < --vertices.end(); ++i)
	{
		auto v1 = **i + pos;
		auto v2 = **vertices.next(i) + pos;
		drawLineF(v1.getX(), v1.getY(), v2.getX(), v2.getY());
	}
}
