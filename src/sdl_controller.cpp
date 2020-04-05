#include <SDL.h>
#include "sdl_controller.h"
#include "timer.h"
#include "sdl_timer.h"

void SdlController::run()
{
	bool quit = false;
	SDL_Event event;
	const Uint8 *keyboardState;

	//TODO: write it in config entity (sort of communication between Model and Controller(Adapter pattern?))

	double init_angle = 270.0;

	model->addShipAtCenter(init_angle);

	model->addRandomAsteroidWithRandomVelocity();

	Timer* timer = new SdlTimer();

	while (!quit)
	{
		//Get number of seconds passed in the previous loop (0 if it's the first iteration)
		double delta = timer->getDelta();

		//Clear the view
		view->clear();

		//Update internal state of the model
		model->update(delta);

		//Handle the events
		//TODO: write and call this->handleKeyboardState();
		keyboardState = SDL_GetKeyboardState(NULL);

		if (keyboardState[SDL_SCANCODE_LEFT])
			model->rotateShipsLeft();
		if (keyboardState[SDL_SCANCODE_RIGHT])
			model->rotateShipsRight();
		if (keyboardState[SDL_SCANCODE_UP])
			model->accelerateShips();
		if (keyboardState[SDL_SCANCODE_SPACE])
			// launch a bullet
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

		//Show all the asteroids
		for (auto &asteroid : model->getAsteroids())
		{
			view->showAsteroid(*asteroid);
		}

		//Show all the ships
		for (auto &ship : model->getShips())
		{
			view->showShip(*ship);
		}

		//TODO: show all the bullets
		view->update();
	}
	SDL_Quit();
}
