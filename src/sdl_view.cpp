#include <string>
#include "sdl_view.h"
#include "sdl_drawer.h"
#include "entities/asteroid.h"

SdlView::SdlView(const std::string &game_name, int game_width, int game_height, const Color &background)
{
	assert(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS) == 0);
	window = SDL_CreateWindow(game_name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, game_width, game_height,
							  SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	assert(renderer != NULL);
	SDL_GetRendererOutputSize(renderer, &this->game_width, &this->game_height);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
	this->background = background;
	drawer = new SdlDrawer(renderer);
	center = {(double)game_width / 2, (double)game_height / 2};
}

void SdlView::clear() const
{
	drawer->fillScreen(background);
}

void SdlView::update()
{
	SDL_RenderPresent(renderer);
}

void SdlView::showAsteroid(const Asteroid &a) const
{
	drawer->drawPolygone(a.getPolygone(), a.getColor());
}

void SdlView::showShip(const Ship &s) const
{
	drawer->drawPolygone(s.getPolygone(), s.getColor());
}

void SdlView::showBullet(const Bullet &b) const
{
	//TODO: replace it by a sprint
	std::shared_ptr<Circle> c = std::static_pointer_cast<Circle>(b.getShape());
	drawer->drawSquare(c->getRadius(), b.getPosition(), b.getColor());
}
