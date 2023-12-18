#pragma once
#include "SFML/Graphics.hpp"
#include "Vector2.h"
#include "Object.h"
#include "Component.h"
#include "Transform.h"
#include "Behavior.h"
#include "WindowManager.h"
#include "Renderer.h"
#include "GameObject.h"
#include "Player.h"
#include <iostream>
#include <list>
using namespace std;
    class BehaviorManager {
    private:
        list<Behavior*> behaviors;

        template <typename T>
        T* AddObject(T* behavior);

        void CheckColliderEntering();
        void UpdateAllBehavior();
        void UpdateAllBehaviorComponents();

    public:
        void GlobalAwake();
        void GlobalStart();
        void GlobalUpdate();
        void RemoveAll();
        void Render();

        template <typename T>
        T* Instantiate();
    };

