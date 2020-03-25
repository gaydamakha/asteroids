#ifndef SDL_CONTROLLER_H
#define SDL_CONTROLLER_H

#include "game_controller.h"

class SdlController : public GameController
{
public:
	using GameController::GameController;

	void run();
};

#endif