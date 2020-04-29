#include <Geometry.h>
#include <Utils.h>
#include "drawer.h"

void Drawer::drawPolygone(const Polygone& polygone, const Color& color) const
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
