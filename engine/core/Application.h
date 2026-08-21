#pragma once

#include <SDL3/SDL.h>
#include "Renderer.h"
#include "Transform.h"
#include "GameObject.h"
#include "Scene.h"
#include "AssetManager.h"

class Application
{
public:
    bool Initialize();
    void Run();
    void Shutdown();

private:
    SDL_Window* m_Window = nullptr;
    Renderer m_Renderer;
    AssetManager m_AssetManager;

    bool m_Running = false;

    Scene m_Scene;
    GameObject* m_Player = nullptr;
    GameObject* m_Enemy = nullptr;

    float m_PlayerSpeed = 300.0f;
};