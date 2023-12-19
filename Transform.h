#pragma once

#include "Component.h"
#include "GameObject.h"
#include "Vector2.h"
class GameObject;

class Transform : public Component {
private:
    Vector2 position;

public:
    GameObject* gameobject; // Pointer to GameObject
    void SetPosition(Vector2 newPosition);
    Vector2 GetPosition();
    Transform();
    Transform(Behavior* behavior);
};

