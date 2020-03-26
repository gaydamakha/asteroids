#ifndef DRAWER_H
#define DRAWER_H

#include <Utils.h>

class Drawer
{
public:
	virtual void fillScreen(const Color& background) const = 0;

	virtual void drawShape(const Vec2d& position, const Polygone& shape, const Color& color) const = 0;
};

#endif