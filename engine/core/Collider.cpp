#include "Collider.h"

bool Collider::CheckCollision(
    const Transform& a,
    const Transform& b
) const
{
    return
        a.position.x < b.position.x + b.scale.x &&
        a.position.x + a.scale.x > b.position.x &&
        a.position.y < b.position.y + b.scale.y &&
        a.position.y + a.scale.y > b.position.y;
}