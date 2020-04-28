#ifndef SDL_DRAWER_H
#define SDL_DRAWER_H

#include <SDL.h>
#include "drawer.h"

class SdlDrawer : public Drawer
{
	SDL_Renderer *renderer;

private:
	void setDrawColor(const Color &color) const;

public:
	SdlDrawer(SDL_Renderer *renderer);

	void fillScreen(const Color &color) const;

	void drawLineF(double, double, double, double, const Color &) const;

	void drawSquare(double, const Vec2d &, const Color &) const;
};

#endif