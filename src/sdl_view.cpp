#include <string>
#include "sdl_view.h"
#include "sdl_drawer.h"
#include "entities/asteroid.h"

SdlView::SdlView(const std::string& game_name, int game_width, int game_height, const Color& background)
{
	assert(SDL_Init(SDL_INIT_VIDEO) == 0);
	window = SDL_CreateWindow(game_name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, game_width, game_height,
		SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);
	renderer = SDL_CreateRenderer(window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	SDL_GetRendererOutputSize(renderer, &this->game_width, &this->game_height);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
	this->background = background;
	drawer = new SdlDrawer(renderer);
	center = {(double)game_width/2, (double)game_height/2};
}

void SdlView::clear() const
{
	drawer->fillScreen(background);
}

void SdlView::update()
{
	SDL_RenderPresent(renderer);
}

void SdlView::showAsteroid(const Asteroid& a) const
{
	drawer->drawPolygone(a.getShape(), a.getColor());
}

void SdlView::showShip(const Ship& s) const
{
	drawer->drawPolygone(s.getShape(), s.getColor());
	Vec2d p = s.getPosition();
	Vec2d dir = s.getDirection() * 100 + p;
	Vec2d vel = s.getVelocity() * 100 + p;
	Vec2d acc = s.getAcceleration() * 100 + p;

	drawer->drawLineF(p.getX(), p.getY(), dir.getX(), dir.getY(), WHITE);
	drawer->drawLineF(p.getX(), p.getY(), vel.getX(), vel.getY(), BLUE);
	drawer->drawLineF(p.getX(), p.getY(), acc.getX(), acc.getY(), RED);
}