#pragma once

#include "Transform.h"
#include "SpriteRenderer.h"

class GameObject
{
public:
    GameObject();

    Transform& GetTransform();
    SpriteRenderer& GetSpriteRenderer();

    void Update(float deltaTime);

    void SetPlayerControlled(bool controlled);

private:
    Transform m_Transform;
    SpriteRenderer m_SpriteRenderer;

    bool m_PlayerControlled = false;
    float m_Speed = 300.0f;
};