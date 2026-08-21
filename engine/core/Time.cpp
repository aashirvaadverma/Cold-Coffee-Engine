#include "Time.h"
#include <SDL3/SDL.h>

float Time::s_DeltaTime = 0.0f;
unsigned long long Time::s_LastTime = 0;

void Time::Initialize()
{
    s_LastTime = SDL_GetTicks();
}

void Time::Update()
{
    unsigned long long currentTime = SDL_GetTicks();

    s_DeltaTime =
        static_cast<float>(currentTime - s_LastTime) / 1000.0f;

    s_LastTime = currentTime;
}

float Time::GetDeltaTime()
{
    return s_DeltaTime;
}