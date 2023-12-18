#include "Behavior.h"
#include "GameObject.h"
#include "Renderer.h"
#include "Transform.h"
#include "Collider.h"
#include "SFML/Graphics.hpp"

Behavior::Behavior() 
{
    _gameObject = AddComponent<GameObject>();
    transform = AddComponent<Transform>();
}

template Renderer* Behavior::AddComponent<Renderer>(const std::string&);
template Collider* Behavior::AddComponent<Collider>(const sf::RectangleShape&);

template <typename T>
T* Behavior::GetComponent() const {
    for (const auto& component : this->Components) {  // <-- Add 'this->'
        auto t = dynamic_cast<T*>(component);
        if (t) {
            return t;
        }
    }
    return nullptr; // Return nullptr if component not found
}

template <typename T, typename... Args>
T* Behavior::AddComponent(Args&&... args) {
    // Create a new instance of T using the provided arguments and the Behavior pointer
    T* newComponent = new T(this, std::forward<Args>(args)...);

    // Add the new component to the Components list
    this->Components.push_back(newComponent);

    // Check if the component is successfully added
    T* addedComponent = GetComponent<T>();
    if (!addedComponent) {
        // Cleanup on failure
        delete newComponent;
        throw std::runtime_error("Failed to add component");
    }

    return addedComponent;
}



void Behavior::Awake() {}

void Behavior::Start() {}

void Behavior::Update() {}

void Behavior::TryRender() {
    for (auto& component : this->Components) {  // <-- Add 'this->'
        auto renderer = dynamic_cast<Renderer*>(component);
        if (renderer) {
            renderer->Render();
        }
    }
}

