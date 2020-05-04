#include "interface/components/sdl_button.h"

bool SdlButton::isPressed()
{
    int mouse_x, mouse_y;
    if (SDL_GetMouseState(&mouse_x, &mouse_y) & SDL_BUTTON(SDL_BUTTON_LEFT))
    {
        return Button::isPressed(mouse_x, mouse_y);
    }
    return false;
}