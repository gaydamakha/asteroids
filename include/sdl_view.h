#ifndef SDL_VIEW_H
#define SDL_VIEW_H

#include <SDL.h>
#include <Utils.h>
#include "entities/asteroid.h"
#include "game_view.h"

class SdlView : public GameView
{
	int game_width, game_height;
	Vec2d center;
	Color background;
	Drawer* drawer;

	SDL_Renderer* renderer;
	SDL_Window* window;
public:
	SdlView(const std::string& game_name, int game_width, int game_height, const Color& background = BLACK);

	void clear() const;

	void update();

	void showAsteroid(const Asteroid& a) const;
};

#endif