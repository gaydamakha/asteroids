#include <SDL.h>
#include "sdl_game_controller.h"
#include "timer.h"
#include "sdl_timer.h"

void SdlGameController::run()
{
	bool quit = false;
	SDL_Event event;
	const Uint8 *keyboardState;

	while (!quit)
	{
		//Clear the view
		game_view->clear();
		//Handle the events
		if (!game_model->isBegan())
		{
			//Handle the case when game is already over
			if (game_model->isOver())
			{
				game_view->showText(launch_menu.at(Event::START_GAME).getPosition() + Vec2d(0., -60),"Game over!", GREEN);
			}
			//If game was finished after this update
			for (auto m : launch_menu)
			{
				game_view->showButton(m.second);
			}
			//If mouse is pressed
			for (auto m : launch_menu)
			{
				if (m.second.isPressed())
				{
					Event e = m.first;
					if (e == Event::START_GAME)
						game_model->begin();
					if (e == Event::EXIT)
						quit = true;
				}
			}
		}

		keyboardState = SDL_GetKeyboardState(NULL);

		if (keyboardState[SDL_SCANCODE_RETURN])
			game_model->begin();
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

		//Update internal state of the model
		game_model->update();

		//Update the view
		game_view->update(*game_model);
	}
	SDL_Quit();
}
