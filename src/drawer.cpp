#include <Geometry.h>
#include <Utils.h>
#include "drawer.h"

void Drawer::drawPolygone(const Vec2d& position, const Polygone& polygone, const Color& color) const
{
	setDrawColor(color);
	auto vertices = polygone.getData();

	for (auto i = vertices.begin(); i < --vertices.end(); ++i)
	{
		auto v1 = **i + position;
		auto v2 = **vertices.next(i) + position;
		drawLineF(v1.getX(), v1.getY(), v2.getX(), v2.getY());
	}	
	auto last = **(--vertices.end()) + position;
	auto first = **vertices.begin() + position;
	drawLineF(last.getX(), last.getY(), first.getX(), first.getY());
}


