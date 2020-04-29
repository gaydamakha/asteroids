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

	//TODO: remove it and pass a config instead (in the main method)
	model->addShipAtCenter();
	model->addAsteroid(AsteroidSize::BIG);
	model->addAsteroid(AsteroidSize::MEDIUM);
	model->addAsteroid(AsteroidSize::SMALL);

	while (!quit)
	{
		//Clear the view
		view->clear();
		//Update internal state of the model
		model->update();
		//Handle the events
		//TODO: write and call this->handleKeyboardState();
		keyboardState = SDL_GetKeyboardState(NULL);

		if (keyboardState[SDL_SCANCODE_LEFT])
			model->rotateShipLeft();
		if (keyboardState[SDL_SCANCODE_RIGHT])
			model->rotateShipRight();
		if (keyboardState[SDL_SCANCODE_UP])
			model->accelerateShip();
		if (keyboardState[SDL_SCANCODE_SPACE])
			// TODO: launch a bullet
			model->shoot();
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

		//Show the ship
		view->showShip(model->getShip());

		// //Show all the bullets
		for (auto &bullet: model->getBullets())
		{
			view->showBullet(*bullet);
		}

		view->update();
	}
	SDL_Quit();
}
