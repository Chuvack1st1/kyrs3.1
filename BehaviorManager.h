#pragma once

#include <list>
using namespace std;
#include "Behavior.h"

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

        template <typename T, typename... Args>
        T* Instantiate(Args&&... args);
    };

