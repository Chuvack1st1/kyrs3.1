#include "Transform.h"
#include <algorithm>

const float& clamp(const float& value, const float& low, const float& high) {
    return std::min(std::max(value, low), high);
}

void Transform::SetPosition(Vector2 newPosition)
{
    // Assuming position is a Vector2
    position.x = clamp(newPosition.x, 0, 1500);
    position.y = clamp(newPosition.y, 0, 700);
}

Vector2 Transform::GetPosition()
{
    return position;
}

Transform::Transform() : gameobject(nullptr), position() {}

Transform::Transform(Behavior* behavior) : Component(behavior) {
    // Initialize the Transform object
}

