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

    // m_Velocity.x = 0.0f;

    // if (Input::IsKeyDown(Key::W))
    // {
    //     m_Velocity.y = -m_Speed;
    // }

    // if (Input::IsKeyDown(Key::S))
    // {
    //     m_Velocity.y = m_Speed;
    // }

    if (Input::IsKeyDown(Key::A))
    {
        m_Velocity.x -= m_Acceleration * deltaTime;
    }

    if (Input::IsKeyDown(Key::D))
    {
        m_Velocity.x += m_Acceleration * deltaTime;
    }
    
    if (!Input::IsKeyDown(Key::A) && !Input::IsKeyDown(Key::D))
    {
        if (m_Velocity.x > 0.0f)
        {
            m_Velocity.x -= m_Friction * deltaTime;

            if (m_Velocity.x < 0.0f)
                m_Velocity.x = 0.0f;
        }
        else if (m_Velocity.x < 0.0f)
        {
            m_Velocity.x += m_Friction * deltaTime;

            if (m_Velocity.x > 0.0f)
                m_Velocity.x = 0.0f;
        }
    }

    if (Input::IsKeyDown(Key::SPACE) && m_IsGrounded)
    {
        m_Velocity.y = -m_JumpForce;
        m_IsGrounded = false;
    }

    if (!Input::IsKeyDown(Key::SPACE) && m_Velocity.y < 0.0f)
    {
        m_Velocity.y *= 0.5f;
    }


//     if (m_Transform.position.x < 0.0f)
//         m_Transform.position.x = 0.0f;

//     if (m_Transform.position.y < 0.0f)
//         m_Transform.position.y = 0.0f;

//     if (m_Transform.position.x > 1280.0f - m_Transform.scale.x)
//         m_Transform.position.x = 1280.0f - m_Transform.scale.x;

//     if (m_Transform.position.y > 720.0f - m_Transform.scale.y)
//         m_Transform.position.y = 720.0f - m_Transform.scale.y;
}

void GameObject::ApplyVelocity(float deltaTime)
{
    m_IsGrounded = false;

    m_Velocity.y += m_Gravity * deltaTime;

    m_Transform.position.x += m_Velocity.x * deltaTime;
    m_Transform.position.y += m_Velocity.y * deltaTime;

    if (m_Transform.position.x < 0.0f)
        m_Transform.position.x = 0.0f;

    if (m_Transform.position.y < 0.0f)
        m_Transform.position.y = 0.0f;

    if (m_Transform.position.x > 1280.0f - m_Transform.scale.x)
        m_Transform.position.x = 1280.0f - m_Transform.scale.x;

    if (m_Transform.position.y > 720.0f - m_Transform.scale.y)
    {
        m_Transform.position.y =
            720.0f - m_Transform.scale.y;

        m_Velocity.y = 0.0f;
        m_IsGrounded = true;
    }
}