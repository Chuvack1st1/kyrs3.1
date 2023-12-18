// Component.h
#pragma once

#include "Object.h"
#include "Behavior.h"

class Component : public Object {
private:
    Behavior* behavior;
public:
    // Constructor that takes a Behavior pointer as a parameter
    Component(Behavior* initialBehavior);

    Component()
    {

    }
    // Getter for the Behavior member
    Behavior* GetBehavior() const;

    // Virtual method to update position
    virtual void UpdatePosition();  // Make sure it's marked as virtual

    // Setter for the Behavior member
    void SetBehavior(Behavior* newBehavior);
};

