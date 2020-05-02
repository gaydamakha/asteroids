#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "game_model.h"
#include "game_view.h"

class GameController
{
protected:
	std::unique_ptr<GameModel> game_model;
	std::unique_ptr<GameView> game_view;
public:
	GameController(GameModel* game_model, GameView* game_view)
	{
		this->game_model = std::unique_ptr<GameModel>(game_model);
		this->game_view = std::unique_ptr<GameView>(game_view);
	}

	virtual void run() = 0;
};

#endif