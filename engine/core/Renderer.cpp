#include "Renderer.h"

bool Renderer::Initialize(SDL_Window* window)
{
    m_Renderer = SDL_CreateRenderer(window, nullptr);

    if (!m_Renderer)
    {
        SDL_Log("Renderer creation failed: %s", SDL_GetError());
        return false;
    }

    return true;
}

void Renderer::Shutdown()
{
    if (m_Renderer)
    {
        SDL_DestroyRenderer(m_Renderer);
        m_Renderer = nullptr;
    }
}

void Renderer::BeginFrame()
{
    SDL_SetRenderDrawColor(
        m_Renderer,
        20,
        20,
        20,
        255
    );

    SDL_RenderClear(m_Renderer);
}

void Renderer::EndFrame()
{
    SDL_RenderPresent(m_Renderer);
}

void Renderer::DrawRectangle(
    float x,
    float y,
    float width,
    float height,
    std::uint8_t r,
    std::uint8_t g,
    std::uint8_t b,
    std::uint8_t a
)
{
    SDL_SetRenderDrawColor(
        m_Renderer,
        r,
        g,
        b,
        a
    );

    SDL_FRect rectangle{
        x,
        y,
        width,
        height
    };

    SDL_RenderFillRect(
        m_Renderer,
        &rectangle
    );
}

void Renderer::DrawTexture(
    SDL_Texture* texture,
    float x,
    float y,
    float width,
    float height
)
{
    if (!texture)
        return;

    SDL_FRect destination{
        x,
        y,
        width,
        height
    };

    SDL_RenderTexture(
        m_Renderer,
        texture,
        nullptr,
        &destination
    );
}

SDL_Renderer* Renderer::GetSDLRenderer()
{
    return m_Renderer;
}