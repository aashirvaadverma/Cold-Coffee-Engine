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
        object->ApplyVelocity(deltaTime);
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

            auto currentPair =
                std::make_pair(m_Objects[i].get(), m_Objects[j].get());

            bool wasColliding = false;

            for (const auto& pair : m_CollidingPairs)
            {
                if (pair.first == currentPair.first &&
                    pair.second == currentPair.second)
                {
                    wasColliding = true;
                    break;
                }
            }

            if (isColliding)
            {
                if (m_Objects[i]->IsPlayerControlled())
                {
                    Transform& playerTransform =
                        m_Objects[i]->GetTransform();

                    Transform& otherTransform =
                        m_Objects[j]->GetTransform();

                    Vector2 previousPosition =
                        m_Objects[i]->GetPreviousPosition();

                    // Player landed on top.
                    if (previousPosition.y + playerTransform.scale.y <=
                        otherTransform.position.y)
                    {
                        playerTransform.position.y =
                            otherTransform.position.y - playerTransform.scale.y;

                        m_Objects[i]->GetVelocity().y = 0.0f;
                        m_Objects[i]->SetGrounded(true);
                    }
                    // Player hit the side.
                    else
                    {
                        playerTransform.position.x =
                            previousPosition.x;
                    }
                }

                if (!wasColliding)
                {
                    SDL_Log("COLLISION ENTER");
                    m_CollidingPairs.push_back(currentPair);
                }
            }

        }
    }
    for (auto it = m_CollidingPairs.begin();
    it != m_CollidingPairs.end();)
    {
        GameObject* first = it->first;
        GameObject* second = it->second;

        bool stillColliding =
            first->GetCollider().CheckCollision(
                first->GetTransform(),
                second->GetTransform()
            );

            if (!stillColliding)
                {
                    SDL_Log("COLLISION EXIT");
                    it = m_CollidingPairs.erase(it);
                }
            else
                {
                    ++it;
                }
    }
}

void Scene::Render(Renderer& renderer)
{
    // Draw everything except the player first.
    for (const auto& object : m_Objects)
    {
        if (object->IsPlayerControlled())
            continue;

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

    // Draw player last so it appears in front.
    for (const auto& object : m_Objects)
    {
        if (!object->IsPlayerControlled())
            continue;

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