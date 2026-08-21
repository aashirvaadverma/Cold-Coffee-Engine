#include "Scene.h"
#include "Renderer.h"

GameObject& Scene::CreateObject()
{
    m_Objects.push_back(std::make_unique<GameObject>());

    return *m_Objects.back();
}

void Scene::Update(float deltaTime)
{
    for (const auto& object : m_Objects)
    {
        object->Update(deltaTime);
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