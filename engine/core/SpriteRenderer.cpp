#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer()
{
}

Color& SpriteRenderer::GetColor()
{
    return m_Color;
}

void SpriteRenderer::SetTexture(Texture* texture)
{
    m_Texture = texture;
}

Texture* SpriteRenderer::GetTexture() const
{
    return m_Texture;
}