#include "Application.h"
#include "Input.h"
#include "Time.h"

bool Application::Initialize()
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("SDL initialization failed: %s", SDL_GetError());
        return false;
    }

    Time::Initialize();

    m_Window = SDL_CreateWindow(
        "Cold Coffee Engine",
        1280,
        720,
        0
    );

    if (!m_Window)
    {
        SDL_Log("Window creation failed: %s", SDL_GetError());
        return false;
    }

    if (!m_Renderer.Initialize(m_Window))
    {
        return false;
    }

    if (!m_AssetManager.Initialize(m_Renderer.GetSDLRenderer()))
    {
        return false;
    }

    // CREATE PLAYER FIRST
    m_Player = &m_Scene.CreateObject();

    m_Player->GetTransform().position = { 540.0f, 260.0f };
    m_Player->GetTransform().scale = { 200.0f, 120.0f };

    m_Player->SetPlayerControlled(true);

    m_Player->GetSpriteRenderer().GetColor() =
        { 180, 120, 70, 255 };

    // THEN LOAD THE TEXTURE
    Texture* playerTexture =
        m_AssetManager.LoadTexture("Assets/player.png");

    if (!playerTexture)
    {
        SDL_Log("Failed to load player texture.");
        return false;
    }

    // THEN GIVE TEXTURE TO PLAYER
    m_Player->GetSpriteRenderer().SetTexture(playerTexture);
    

    // CREATE ENEMY
    m_Enemy = &m_Scene.CreateObject();

    m_Enemy->GetTransform().position = { 900.0f, 400.0f };
    m_Enemy->GetTransform().scale = { 150.0f, 100.0f };

    m_Enemy->GetSpriteRenderer().GetColor() =
        { 70, 120, 180, 255 };

    // CREATE PLATFORM
    GameObject& platform = m_Scene.CreateObject();

    platform.GetTransform().position = { 350.0f, 550.0f };
    platform.GetTransform().scale = { 500.0f, 50.0f };

    platform.GetSpriteRenderer().GetColor() =
        { 100, 180, 100, 255 };

    // CREATE SECOND PLATFORM
    GameObject& platform2 = m_Scene.CreateObject();

    platform2.GetTransform().position = { 800.0f, 420.0f };
    platform2.GetTransform().scale = { 300.0f, 50.0f };

    platform2.GetSpriteRenderer().GetColor() =
        { 180, 150, 80, 255 };

    
    m_Running = true;

    return true;
}

void Application::Run()
{
    SDL_Event event;

    while (m_Running)
    {
        Time::Update();

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                m_Running = false;
            }
        }

        m_Scene.Update(Time::GetDeltaTime());

        m_Renderer.BeginFrame();

        m_Scene.Render(m_Renderer);

        m_Renderer.EndFrame();
    }
}

void Application::Shutdown()
{
    m_AssetManager.Shutdown();

    m_Renderer.Shutdown();

    if (m_Window)
    {
        SDL_DestroyWindow(m_Window);
        m_Window = nullptr;
    }

    SDL_Quit();
}