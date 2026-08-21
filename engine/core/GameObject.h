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

private:
    Transform m_Transform;
    Vector2 m_PreviousPosition;
    SpriteRenderer m_SpriteRenderer;
    Collider m_Collider;

    bool m_PlayerControlled = false;
    float m_Speed = 300.0f;
};