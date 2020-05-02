#include <SDL.h>
#include <string>
#include "game_model.h"
#include "game_view.h"
#include "sdl_game_view.h"
#include "game_controller.h"
#include "sdl_game_controller.h"

//TODO: pass it through config entity
static int game_width = 1000;
static int game_height = 600;
static const std::string game_name = "Asteroids";

int main(int argc, char** argv)
{
	GameView* view = new SdlGameView(game_name, game_width, game_height);
	GameModel* game = new GameModel(game_width, game_height);
	std::unique_ptr<GameController> controller = std::make_unique<SdlGameController>(game, view);

	controller->run();

	return 0;
}
