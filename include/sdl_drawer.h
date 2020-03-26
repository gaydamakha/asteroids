#ifndef SDL_DRAWER_H
#define SDL_DRAWER_H

#include <SDL.h>
#include <Geometry.h>
#include <Utils.h>
#include "drawer.h"

class SdlDrawer : public Drawer
{
	SDL_Renderer* renderer;
private:
	void setSdlDrawColor(const Color& color) const;
public:
	SdlDrawer(SDL_Renderer* renderer);

	void fillScreen(const Color& color) const;

	void drawShape(const Vec2d& position, const Polygone& shape, const Color& color) const;
};

#endif