#pragma once

#include "Transform.h"
#include "SpriteRenderer.h"
#include "Collider.h"

class GameObject
{
public:
    GameObject();

    Transform& GetTransform();
    SpriteRenderer& GetSpriteRenderer();

    void Update(float deltaTime);

    void SetPlayerControlled(bool controlled);

    Collider& GetCollider()
    {
        return m_Collider;
    }

    Vector2 GetPreviousPosition() const
    {
        return m_PreviousPosition;
    }

    Vector2& GetVelocity()
    {
        return m_Velocity;
    }
    void ApplyVelocity(float deltaTime);
    bool IsGrounded() const
    {
        return m_IsGrounded;
    }

    void SetGrounded(bool grounded)
    {
        m_IsGrounded = grounded;
    }

private:
    Transform m_Transform;
    Vector2 m_PreviousPosition;
    Vector2 m_Velocity;
    SpriteRenderer m_SpriteRenderer;
    Collider m_Collider;
    
    bool m_PlayerControlled = false;
    float m_Speed = 300.0f;
    float m_Gravity = 1400.0f;
    float m_JumpForce = 750.0f;
    bool m_IsGrounded = false;
};