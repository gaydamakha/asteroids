#ifndef SDL_TIMER_H
#define SDL_TIMER_H

#include <SDL.h>
#include "timer.h"

class SdlTimer : public Timer
{
    Uint32 prev_time;

public:
    SdlTimer()
    {
        prev_time = SDL_GetTicks();
    }

    double getDelta()
    {
        Uint32 cur = SDL_GetTicks();
        Uint32 dif = cur - prev_time;
        prev_time = cur;
        // Divide by 1000 because SDl_GetTicks() returns milliseconds
        return (double)(dif) / 1000.0;
    }

    double getTimestamp() const
    {
        return (double)(SDL_GetTicks()) / 1000.0;
    }
};

#endif