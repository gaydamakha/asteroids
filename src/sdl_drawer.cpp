#include "sdl_drawer.h"

SdlDrawer::SdlDrawer(SDL_Renderer* renderer)
{
	this->renderer = renderer;
}

void SdlDrawer::setSdlDrawColor(const Color& color) const
{
	SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], color[3]);
}

void SdlDrawer::fillScreen(const Color& color) const
{
	setSdlDrawColor(color);
	SDL_RenderClear(renderer);
}

void SdlDrawer::drawShape(const Vec2d& position, const Polygone& shape, const Color& color) const
{
	setSdlDrawColor(color);
	//TODO: verify that getVertices is available (when polymorphism for Shape will be enabled)
	auto vertices = shape.getVertices();
	for (int i = vertices.size() ; i > 0; --i)
	{
		auto v1 = *vertices[i % vertices.size()] + position;
		auto v2 = *vertices[i - 1] + position;
		SDL_RenderDrawLineF(renderer, v1.getX(), v1.getY(), v2.getX(), v2.getY());
		v1 = v2;
	}
}