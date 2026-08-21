#include "Texture.h"
#include <SDL3_image/SDL_image.h>

Texture::Texture()
{
}

Texture::~Texture()
{
    Unload();
}

bool Texture::Load(SDL_Renderer* renderer, const std::string& path)
{
    Unload();

    SDL_Surface* surface = IMG_Load(path.c_str());

    if (!surface)
    {
        SDL_Log("Failed to load texture: %s", SDL_GetError());
        return false;
    }

    m_Width = surface->w;
    m_Height = surface->h;

    m_Texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_DestroySurface(surface);

    if (!m_Texture)
    {
        SDL_Log("Failed to create texture: %s", SDL_GetError());
        m_Width = 0;
        m_Height = 0;
        return false;
    }

    return true;
}

void Texture::Unload()
{
    if (m_Texture)
    {
        SDL_DestroyTexture(m_Texture);
        m_Texture = nullptr;
    }

    m_Width = 0;
    m_Height = 0;
}

SDL_Texture* Texture::GetSDLTexture() const
{
    return m_Texture;
}

int Texture::GetWidth() const
{
    return m_Width;
}

int Texture::GetHeight() const
{
    return m_Height;
}