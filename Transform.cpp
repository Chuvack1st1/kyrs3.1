#include "Transform.h"


Transform::Transform() : gameobject(nullptr), position() {}

Transform::Transform(const Transform& transform) : gameobject(transform.gameobject), position(transform.position) {}
