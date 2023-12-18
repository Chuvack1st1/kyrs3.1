#include "Transform.h"


Transform::Transform() : gameobject(nullptr), position() {}

Transform::Transform(Behavior* behavior) : Component(behavior) {
    // Initialize the Transform object
}

