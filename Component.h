// Component.h
#pragma once
#include "SFML/Graphics.hpp"
#include "Vector2.h"
#include "Object.h"
#include "Transform.h"
#include "Behavior.h"
#include "WindowManager.h"
#include "Renderer.h"
#include "GameObject.h"
#include "BehaviorManager.h"
#include "Player.h"
#include <iostream>
#include <list>
using namespace std;

class Transform;
class Behavior;

    class Component : public Object {
    private:
        Transform* position;
        Behavior* behavior;

    public:
        // Constructor that takes a Behavior pointer as a parameter
        Component(Behavior* initialBehavior);

        // Default constructor
        Component();

        // Getter for the Behavior member
        Behavior* GetBehavior() const;

        // Virtual method to update position
        virtual void UpdatePosition();  // Make sure it's marked as virtual

        // Setter for the Behavior member
        void SetBehavior(Behavior* newBehavior);
    };

