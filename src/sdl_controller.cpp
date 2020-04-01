#include <SDL.h>
#include "sdl_controller.h"

void SdlController::run()
{
	bool quit = false;
	SDL_Event event;
	//TODO: write it in config entity (sort of communication between Model and Controller(Adapter pattern?))

	double init_angle = 270.0;

	model->addShipAtCenter(init_angle);

	model->addRandomAsteroidWithRandomVelocity();

	while (!quit)
	{
		SDL_Delay(5);
		view->clear();

		model->update();

		SDL_PollEvent(&event);
		// while (SDL_PollEvent(&event))
		// {
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			// touche clavier
			case SDLK_LEFT:
				model->rotateShipsLeft();
				break;
			case SDLK_RIGHT:
				model->rotateShipsRight();
				break;
			case SDLK_UP:
				model->accelerateShips();
				break;
			case SDLK_ESCAPE:
				quit = true;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
		// }

		for (auto &asteroid : model->getAsteroids())
		{
			view->showAsteroid(*asteroid);
		}

		for (auto &ship : model->getShips())
		{
			view->showShip(*ship);
		}

		view->update();
	}
	SDL_Quit();
}
