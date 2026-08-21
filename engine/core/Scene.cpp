#include "Scene.h"
#include "Renderer.h"

GameObject& Scene::CreateObject()
{
    m_Objects.push_back(std::make_unique<GameObject>());

    return *m_Objects.back();
}

void Scene::Update(float deltaTime)
{
    for (auto& object : m_Objects)
    {
        object->Update(deltaTime);
    }

    // Check collisions between objects
    for (size_t i = 0; i < m_Objects.size(); ++i)
    {
        for (size_t j = i + 1; j < m_Objects.size(); ++j)
        {
            Transform& a = m_Objects[i]->GetTransform();
            Transform& b = m_Objects[j]->GetTransform();

            bool isColliding =
                m_Objects[i]->GetCollider().CheckCollision(a, b);

            if (isColliding)
            {
                m_Objects[i]->GetTransform().position =
                    m_Objects[i]->GetPreviousPosition();

                SDL_Log("COLLISION!");
            }
        }
    }
}

void Scene::Render(Renderer& renderer)
{
    for (const auto& object : m_Objects)
    {
        Transform& transform = object->GetTransform();
        SpriteRenderer& sprite = object->GetSpriteRenderer();

        if (sprite.GetTexture())
        {
            renderer.DrawTexture(
                sprite.GetTexture()->GetSDLTexture(),
                transform.position.x,
                transform.position.y,
                transform.scale.x,
                transform.scale.y
            );
        }
        else
        {
            Color& color = sprite.GetColor();

            renderer.DrawRectangle(
                transform.position.x,
                transform.position.y,
                transform.scale.x,
                transform.scale.y,
                color.r,
                color.g,
                color.b,
                color.a
            );
        }
    }
}

std::vector<std::unique_ptr<GameObject>>& Scene::GetObjects()
{
    return m_Objects;
}