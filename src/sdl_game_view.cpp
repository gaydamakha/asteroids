#include <string>
#include "interface/sdl_game_view.h"
#include "interface/sdl_drawer.h"
#include "entities/asteroid.h"

SdlGameView::SdlGameView(const std::string &game_name, int game_width, int game_height, const Color &background)
        : GameView(game_name, game_width, game_height, background) {
    assert(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS) == 0);
    window = SDL_CreateWindow(game_name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, game_width,
                              game_height,
                              SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_RenderSetLogicalSize(renderer, game_width, game_height);
    SDL_RenderSetIntegerScale(renderer, SDL_TRUE);
    if (renderer == NULL) {
        std::cerr << "Error while creating renderer!" << std::endl;
        return;
    }
    // SDL_GetRendererOutputSize(renderer, &this->game_width, &this->game_height);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
    drawer = std::make_unique<SdlDrawer>(renderer);
    //Inverse letters by Y axis
    for (auto &letter : font.getFont()) {
        for (auto &symbol : (*letter).getSymbols()) {
            for (auto &vertice : (*symbol).getVertices()) {
                (*vertice) = Vec2d(vertice->getX(), -vertice->getY());
            }
        }
    }
    //Inverse corners by Y axis
    left_up_corner = {left_up_corner.getX(), game_height - left_up_corner.getY()};
    right_up_corner = {right_up_corner.getX(), game_height - right_up_corner.getY()};
    highscores_stat_pos = {highscores_stat_pos.getX(), game_height - highscores_stat_pos.getY()};
}

void SdlGameView::update(const GameModel &game_model) {
    GameView::update(game_model);
    SDL_RenderPresent(renderer);
}
