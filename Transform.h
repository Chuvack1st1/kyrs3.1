#pragma once

#include "Component.h"
#include "GameObject.h"
#include "Vector2.h"
class GameObject;

class Transform : public Component {
public:
    GameObject* gameobject; // Pointer to GameObject
    Vector2 position;

    Transform();
    Transform(Behavior* behavior);
};

