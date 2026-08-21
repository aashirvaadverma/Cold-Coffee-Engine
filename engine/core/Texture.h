#pragma once

#include <SDL3/SDL.h>
#include <string>

class Texture
{
public:
    Texture();
    ~Texture();

    bool Load(SDL_Renderer* renderer, const std::string& path);
    void Unload();

    SDL_Texture* GetSDLTexture() const;

    int GetWidth() const;
    int GetHeight() const;

private:
    SDL_Texture* m_Texture = nullptr;

    int m_Width = 0;
    int m_Height = 0;
};