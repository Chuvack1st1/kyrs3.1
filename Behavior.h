#pragma once
#include "SFML/Graphics.hpp"
#include "Vector2.h"
#include "Object.h"
#include "Component.h"
#include "Transform.h"
#include "WindowManager.h"
#include "Renderer.h"
#include "GameObject.h"
#include "BehaviorManager.h"
#include "Player.h"
#include <iostream>
#include <list>
using namespace std;

    class Behavior : public Object {
    public:
        list<Component*> Components;
        GameObject* _gameObject; // Pointer to GameObject
        Transform* transform;    // Pointer to Transform
        Behavior();
        Behavior(GameObject& gameObject);
        Behavior(GameObject& gameObject, Transform& transform);
        virtual ~Behavior() = default;

        template <typename T>
        T* GetComponent() const;

        template <typename T, typename... Args>
        T* AddComponent(Args&&... args);

        virtual void Awake();
        virtual void Start();
        virtual void Update();

        virtual void TryRender();
    };

