#include "collections/game_levels_collection.h"

const GameLevelsCollection &GameLevelsCollection::push(const json &level_config)
{
	try
	{
		validator.validate(level_config); // validate the document - uses the default throwing error-handler
		std::cout << "Level config validation succeeded" + level_config["level_name"].dump() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Invalid level config: " << e.what() << std::endl;
		return *this;
	}

	IterableCollection<GameLevel>::push(level_config.get<GameLevel>());

	return *this;
}