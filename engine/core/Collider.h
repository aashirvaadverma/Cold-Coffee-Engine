#pragma once

#include "Transform.h"

class Collider
{
public:
    Collider() = default;

    bool CheckCollision(
        const Transform& a,
        const Transform& b
    ) const;
};