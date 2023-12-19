#include "BehaviorManager.h"
#include "Player.h"
#include "Component.h"
#include "Cat.h"

template Player* BehaviorManager::Instantiate<Player>();
template Cat* BehaviorManager::Instantiate<Cat>(Player*&);

template <typename T>
T* BehaviorManager::AddObject(T* behavior) {
    behaviors.push_front(behavior);
    return behavior;
}

void BehaviorManager::CheckColliderEntering() {
    // ... (uncommented-out collision detection code)
}

void BehaviorManager::UpdateAllBehavior() {
    for (auto& behavior : behaviors) {
        if (behavior) {
            behavior->Update();
        }
    }
}

void BehaviorManager::UpdateAllBehaviorComponents()
{
    for (auto& behavior : behaviors) {
        if (behavior) {
            for (auto& component : behavior->Components) {
                component->UpdatePosition();
            }
        }
    }
}

void BehaviorManager::GlobalAwake() {
    for (auto& behavior : behaviors) {
        if (behavior) {
            behavior->Awake();
        }
    }
}

void BehaviorManager::GlobalStart() {
    for (auto& behavior : behaviors) {
        if (behavior) {
            behavior->Start();
        }
    }
}

void BehaviorManager::GlobalUpdate() {
    CheckColliderEntering();
    UpdateAllBehaviorComponents();
    UpdateAllBehavior();
}

void BehaviorManager::RemoveAll() {
    for (auto& object : behaviors) {
        delete object;
    }
    behaviors.clear();
}

void BehaviorManager::Render() {
    for (auto& behavior : behaviors) {
        if (behavior) {
            behavior->TryRender();
        }
    }
}

template <typename T, typename... Args>
T* BehaviorManager::Instantiate(Args&&... args) {
    T* object = new T(std::forward<Args>(args)...);
    object->transform = new Transform();
    return AddObject(object);
}
