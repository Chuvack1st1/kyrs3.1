#include "Component.h"

// Constructor that takes a Behavior pointer as a parameter
Component::Component(Behavior* initialBehavior) : behavior(initialBehavior){
    
}
// Getter for the Behavior member
Behavior* Component::GetBehavior() const {
    return behavior;
}

void Component::UpdatePosition()
{
    
}

// Setter for the Behavior member
void Component::SetBehavior(Behavior* newBehavior) {
    behavior = newBehavior;
}
