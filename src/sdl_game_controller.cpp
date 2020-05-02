#include <SDL.h>
#include "sdl_game_controller.h"
#include "timer.h"
#include "sdl_timer.h"

void SdlGameController::run()
{
	bool quit = false;
	SDL_Event event;
	const Uint8 *keyboardState;

	//TODO: remove it and pass a config instead (in the main method)
	game_model->addShipAtCenter();
	game_model->addAsteroid(AsteroidSize::BIG);
	game_model->addAsteroid(AsteroidSize::MEDIUM);
	game_model->addAsteroid(AsteroidSize::SMALL);

	while (!quit)
	{
		//Handle the events
		//TODO: write and call this->handleKeyboardState();
		keyboardState = SDL_GetKeyboardState(NULL);

		if (keyboardState[SDL_SCANCODE_LEFT])
			game_model->rotateShipLeft();
		if (keyboardState[SDL_SCANCODE_RIGHT])
			game_model->rotateShipRight();
		if (keyboardState[SDL_SCANCODE_UP])
			game_model->accelerateShip();
		if (keyboardState[SDL_SCANCODE_SPACE])
			game_model->shoot();
		if (keyboardState[SDL_SCANCODE_ESCAPE])
			quit = true;

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			}
		}

		//Clear the view
		game_view->clear();
		//Update internal state of the model
		game_model->update();

		game_view->update(*game_model);
	}
	SDL_Quit();
}
