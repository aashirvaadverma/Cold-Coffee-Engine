#include "GameObject.h"
#include "Input.h"

GameObject::GameObject()
{
}

Transform& GameObject::GetTransform()
{
    return m_Transform;
}

SpriteRenderer& GameObject::GetSpriteRenderer()
{
    return m_SpriteRenderer;
}

void GameObject::SetPlayerControlled(bool controlled)
{
    m_PlayerControlled = controlled;
}

void GameObject::Update(float deltaTime)
{
    m_PreviousPosition = m_Transform.position;
    
    if (!m_PlayerControlled)
        return;

    if (Input::IsKeyDown(Key::W))
    {
        m_Transform.position.y -= m_Speed * deltaTime;
    }

    if (Input::IsKeyDown(Key::S))
    {
        m_Transform.position.y += m_Speed * deltaTime;
    }

    if (Input::IsKeyDown(Key::A))
    {
        m_Transform.position.x -= m_Speed * deltaTime;
    }

    if (Input::IsKeyDown(Key::D))
    {
        m_Transform.position.x += m_Speed * deltaTime;
    }

    // Keep the player inside the window.
    if (m_Transform.position.x < 0.0f)
        m_Transform.position.x = 0.0f;

    if (m_Transform.position.y < 0.0f)
        m_Transform.position.y = 0.0f;

    if (m_Transform.position.x > 1280.0f - m_Transform.scale.x)
        m_Transform.position.x = 1280.0f - m_Transform.scale.x;

    if (m_Transform.position.y > 720.0f - m_Transform.scale.y)
        m_Transform.position.y = 720.0f - m_Transform.scale.y;
}