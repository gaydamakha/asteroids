#include <SDL.h>
#include "sdl_controller.h"

void SdlController::run()
{
	bool quit = false;
	while (!quit)
	{
		view->clear();
		SDL_Event event;
		while (!quit && SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					// touche clavier
				case SDLK_LEFT:; break;
				case SDLK_RIGHT:; break;
				case SDLK_ESCAPE: quit = true; break;
				default: break;
				}
				break;
			case SDL_MOUSEMOTION:	/*x += event.motion.xrel;*/	break;
			case SDL_MOUSEBUTTONDOWN:
				//printf("mouse click %d \n", event.button.button);
				break;
			default: break;
			}
		}

		model->update();

		if (SDL_BUTTON(SDL_BUTTON_LEFT))
		{ 
			model->addRandomAsteroidWithRandomVelocity();
		}

		for (auto& asteroid : model->getAsteroids())
		{
			view->showAsteroid(*asteroid);
		}

		view->update();
	}
	SDL_Quit();
}
