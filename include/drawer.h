#ifndef DRAWER_H
#define DRAWER_H

#include <Utils.h>

class Drawer
{
private:
	virtual void setDrawColor(const Color& color) const {};
public:
	virtual void fillScreen(const Color& background) const = 0;

	virtual void drawLineF(double, double, double, double) const = 0;

	void drawPolygone(const Polygone& polygone, const Color& color) const;
};

#endif