#pragma once
#include "Object.h"
#include <list>
class Component;
class GameObject;
class Transform;
    class Behavior : public Object {
    public:
        std::list<Component*> Components;
        GameObject* _gameObject; // Pointer to GameObject
        Transform* transform;    // Pointer to Transform
        Behavior();
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

