#include <SDL.h>
#include <string>
#include "game_model.h"
#include "interface/game_view.h"
#include "interface/sdl_game_view.h"
#include "game_controller.h"
#include "sdl_game_controller.h"
#include "collections/game_levels_collection.h"

//TODO: pass it through config entity
static int game_width = 1000;
static int game_height = 600;
static const std::string game_name = "Asteroids";

int main(int argc, char** argv)
{
	//TODO: read the config file from here
	//TODO: fetch it from config
	GameView* view = new SdlGameView(game_name, game_width, game_height);
	GameModel* game = new GameModel(game_width, game_height, ONE_LEVEL_COLLECTION);
	std::unique_ptr<GameController> controller = std::make_unique<SdlGameController>(game, view);

	controller->run();

	return 0;
}
