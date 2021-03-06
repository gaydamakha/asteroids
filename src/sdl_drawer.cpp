#include "interface/sdl_drawer.h"

SdlDrawer::SdlDrawer(SDL_Renderer* renderer)
{
	this->renderer = renderer;
}

void SdlDrawer::setDrawColor(const Color& color) const
{
	SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], color[3]);
}

void SdlDrawer::fillScreen(const Color& color) const
{
	setDrawColor(color);
	SDL_RenderClear(renderer);
}

void SdlDrawer::drawLineF(double x1, double y1, double x2, double y2, const Color& color) const
{
	setDrawColor(color);
	SDL_RenderDrawLineF(renderer, x1, y1, x2, y2);
}

void SdlDrawer::drawSquare(double side, const Vec2d &position, const Color &color) const
{
	setDrawColor(color);
	SDL_FRect rect;
	rect.x = position.getX();
	rect.y = position.getY();
	rect.h = side;
	rect.w = side;
	SDL_RenderFillRectF(renderer, &rect);
}