#pragma once

struct Vector2
{
    float x = 0.0f;
    float y = 0.0f;
};

struct Transform
{
    Vector2 position;
    Vector2 scale = { 1.0f, 1.0f };

    float rotation = 0.0f;
};