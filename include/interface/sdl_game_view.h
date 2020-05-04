#ifndef SDL_VIEW_H
#define SDL_VIEW_H

#include <SDL.h>
#include <Utils.h>
#include "game_view.h"

class SdlGameView : public GameView
{
	SDL_Renderer* renderer;
	SDL_Window* window;
public:
	SdlGameView(const std::string &game_name, int game_width, int game_height, const Color &background = BLACK);

	void update(const GameModel &game_model) override;
};

#endif