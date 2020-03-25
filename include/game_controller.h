#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "game_model.h"
#include "game_view.h"

class GameController
{
protected:
	GameModel* model;
	GameView* view;
public:
	GameController(GameModel* model, GameView* view)
	{
		this->view = view;
		this->model = model;
	}

	virtual void run() = 0;
};

#endif