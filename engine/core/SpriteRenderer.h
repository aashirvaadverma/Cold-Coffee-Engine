#pragma once

#include <cstdint>

#include "Texture.h"

struct Color
{
    std::uint8_t r = 255;
    std::uint8_t g = 255;
    std::uint8_t b = 255;
    std::uint8_t a = 255;
};

class SpriteRenderer
{
public:
    SpriteRenderer();

    Color& GetColor();

    void SetTexture(Texture* texture);
    Texture* GetTexture() const;

private:
    Color m_Color;
    Texture* m_Texture = nullptr;
};