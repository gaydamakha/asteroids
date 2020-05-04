#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <nlohmann/json.hpp>
#include <nlohmann/json-schema.hpp>
#include "schemas/config_schema.h"
#include "game_model.h"
#include "game_controller.h"
#include "sdl_game_controller.h"
#include "interface/game_view.h"
#include "interface/sdl_game_view.h"
#include "collections/game_levels_collection.h"

using namespace nlohmann;

static const std::string LEVELS_PATH = CONFIGS_PATH + "levels/";

int get_config(std::string filename, json &config)
{
	std::ifstream i(filename);
	i >> config;

	json_schema::json_validator validator(CONFIG_SCHEMA);

	try
	{
		validator.validate(config); // validate the document - uses the default throwing error-handler
		std::cout << "Config validation succeeded" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Invalid config: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return 0;
}

int load_levels(std::string path, GameLevelsCollection& levels)
{
	json level;
	for (const auto &filename: std::filesystem::directory_iterator(path))
	{
		std::ifstream i(filename.path());
		i >> level;
		levels.push(level);
	}

	return 0;
}

int main(int argc, char **argv)
{
	json config;
	int status;
	if ((status = get_config(CONFIGS_PATH + "asteroids.json", config)) != 0) 
	{
		return status;
	}

	GameLevelsCollection levels;
	if ((status = load_levels(LEVELS_PATH, levels)) != 0) 
	{
		return status;
	}
	
	GameView *view = new SdlGameView(config["game_name"], config["window_width"], config["window_height"]);
	GameModel *game = new GameModel(config["game_width"], config["game_height"], levels);
	std::unique_ptr<GameController> controller = std::make_unique<SdlGameController>(game, view);

	controller->run();

	return 0;
}
