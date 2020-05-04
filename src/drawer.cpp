#include <Geometry.h>
#include <Utils.h>
#include "interface/drawer.h"

//TODO: unify it
// void Drawer::drawPolygone(const Polygone &polygone, const Color &color) const
// {
// 	setDrawColor(color);
// 	auto vertices = polygone.getVertices();

// 	for (auto i = vertices.begin(); i < --vertices.end(); ++i)
// 	{
// 		auto v1 = **i;
// 		auto v2 = **vertices.next(i);
// 		drawLineF(v1.getX(), v1.getY(), v2.getX(), v2.getY());
// 	}
// 	auto last = **(--vertices.end());
// 	auto first = **vertices.begin();
// 	drawLineF(last.getX(), last.getY(), first.getX(), first.getY());
// }

void Drawer::drawShape(const std::shared_ptr<Shape> shape, const Color &color) const
{
	this->drawShape(Vec2d(0, 0), shape, color);
}

void Drawer::drawShape(const Vec2d &pos, const std::shared_ptr<Shape> shape, const Color &color) const
{
	if (std::shared_ptr<Circle> s = std::dynamic_pointer_cast<Circle>(shape))
	{
		std::cout << "I don't know draw the circle (" << std::endl;
		return;
	}
	else if (std::shared_ptr<ShapeWithVertices> s = std::dynamic_pointer_cast<ShapeWithVertices>(shape))
	{
		setDrawColor(color);
		auto &vertices = s->getVertices();
		for (auto i = vertices.begin(); i < --vertices.end(); ++i)
		{
			auto v1 = **i + pos;
			auto v2 = **vertices.next(i) + pos;
			drawLineF(v1.getX(), v1.getY(), v2.getX(), v2.getY());
		}
		if (s->isClosed())
		{
			auto last = **(--vertices.end());
			auto first = **vertices.begin();
			drawLineF(last.getX(), last.getY(), first.getX(), first.getY());
		}
	}
	else
	{
		std::cout << "I don't know this shape (" << std::endl;
		return;
	}
}
