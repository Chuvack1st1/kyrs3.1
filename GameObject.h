#pragma once
#include "SFML/Graphics.hpp"
#include "Vector2.h"
#include "Object.h"
#include "Component.h"
#include "Transform.h"
#include "Behavior.h"
#include "WindowManager.h"
#include "Renderer.h"
#include "BehaviorManager.h"
#include "Player.h"
#include <iostream>
#include <list>
using namespace std;


    class GameObject : public Component {
    public:
        Transform transform;

        GameObject();
    };

