#pragma once

#include <SDL3/SDL.h>

enum class Key
{
    W,
    A,
    S,
    D,
    Escape
};

class Input
{
public:
    static bool IsKeyDown(Key key);
};