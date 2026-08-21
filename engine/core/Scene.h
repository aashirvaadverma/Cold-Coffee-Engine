#pragma once

#include <memory>
#include <vector>

#include "GameObject.h"

class Renderer;

class Scene
{
public:
    GameObject& CreateObject();

    void Update(float deltaTime);
    void Render(Renderer& renderer);

    std::vector<std::unique_ptr<GameObject>>& GetObjects();

private:
    std::vector<std::unique_ptr<GameObject>> m_Objects;
};