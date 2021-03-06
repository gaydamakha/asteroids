#ifndef DRAWER_H
#define DRAWER_H

#include <Utils.h>
#include <Geometry.h>

class Drawer
{
private:
	virtual void setDrawColor(const Color &color) const = 0;

public:
	virtual void fillScreen(const Color &background) const = 0;

	virtual void drawLineF(double, double, double, double, const Color &color = GREEN) const = 0;

	virtual void drawSquare(double, const Vec2d &, const Color &) const = 0;

	// void drawPolygone(const Polygone &, const Color &) const;
	void drawShape(const std::shared_ptr<Shape> shape, const Color &color) const;
	void drawShape(const Vec2d& pos, const std::shared_ptr<Shape> shape, const Color &color) const;
};

#endif