#pragma once
#include "SFML/Graphics.hpp"
#include "Vector2.h"
#include "Object.h"
#include "Component.h"
#include "Behavior.h"
#include "WindowManager.h"
#include "Renderer.h"
#include "GameObject.h"
#include "BehaviorManager.h"
#include "Player.h"
#include <iostream>
#include <list>
using namespace std;
    class Transform : public Object {
    public:
        GameObject* gameobject; // Pointer to GameObject
        Vector2 position;

        Transform();
        Transform(const Transform& transform);
    };

