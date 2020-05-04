#ifndef SDL_BUTTON_H
#define SDL_BUTTON_H

#include <SDL.h>
#include "button.h"

class SdlButton : public Button
{
public:
    using Button::Button;

    bool isPressed();
};

#endif