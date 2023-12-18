#include "GameObject.h"


GameObject::GameObject() : transform() {
    transform.gameobject = this; // Set the gameobject pointer in Transform to this GameObject
}
