#pragma once

#include <cstdint>
#include <SDL3/SDL.h>

class Renderer
{
public:
    bool Initialize(SDL_Window* window);
    void Shutdown();

    void BeginFrame();
    void EndFrame();

    void DrawRectangle(
        float x,
        float y,
        float width,
        float height,
        std::uint8_t r,
        std::uint8_t g,
        std::uint8_t b,
        std::uint8_t a = 255
    );

    void DrawTexture(
        SDL_Texture* texture,
        float x,
        float y,
        float width,
        float height
    );

    SDL_Renderer* GetSDLRenderer();

private:
    SDL_Renderer* m_Renderer = nullptr;
};