#include <SDL.h>
#include <string>
#include "game_model.h"
#include "game_view.h"
#include "sdl_view.h"
#include "game_controller.h"
#include "sdl_controller.h"

static int game_width = 1000;
static int game_height = 600;
static const std::string game_name = "Asteroids";

int main(int argc, char** argv)
{
	GameView* view = new SdlView(game_name, game_width, game_height);
	GameModel* game = new GameModel(game_width, game_height);
	GameController* controller = new SdlController(game, view);

	controller->run();

	delete controller;
	delete view;
	delete game;

	return 0;
}
