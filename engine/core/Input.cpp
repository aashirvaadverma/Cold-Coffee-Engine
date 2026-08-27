#include "Input.h"

bool Input::IsKeyDown(Key key)
{
    const bool* keyboardState = SDL_GetKeyboardState(nullptr);

    SDL_Scancode scancode;

    switch (key)
    {
        case Key::W:
            scancode = SDL_SCANCODE_W;
            break;

        case Key::A:
            scancode = SDL_SCANCODE_A;
            break;

        case Key::S:
            scancode = SDL_SCANCODE_S;
            break;

        case Key::D:
            scancode = SDL_SCANCODE_D;
            break;

        case Key::SPACE:
            scancode = SDL_SCANCODE_SPACE;
            break;

        case Key::Escape:
            scancode = SDL_SCANCODE_ESCAPE;
            break;

        default:
            return false;
    }

    return keyboardState[scancode];
}