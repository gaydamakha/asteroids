#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <map>
#include "game_model.h"
#include "interface/game_view.h"
#include "interface/components/sdl_button.h"

enum class Event
{
	START_GAME,
	EXIT
};

using Menu = std::map<Event, SdlButton>;

class GameController
{
protected:
	std::unique_ptr<GameModel> game_model;
	std::unique_ptr<GameView> game_view;
	Menu launch_menu;
public:
	GameController(GameModel *game_model, GameView *game_view)
	{
		this->game_model = std::unique_ptr<GameModel>(game_model);
		this->game_view = std::unique_ptr<GameView>(game_view);
		auto center = this->game_view->getCenter();
		launch_menu.emplace(std::make_pair(Event::START_GAME, SdlButton({center.getX(), center.getY() - 40}, GREEN, 160, 60, "Play")));
		launch_menu.emplace(std::make_pair(Event::EXIT, SdlButton({center.getX(), center.getY() + 40}, GREEN, 160, 60, "Exit")));
	}

	virtual void run() = 0;
};

#endif