#pragma once

#include "Component.h"

class Transform;
    class GameObject : public Component {
    public:
        Transform* transform;

        GameObject();
        GameObject(Behavior* behavior);
    };

