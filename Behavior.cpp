#include "Behavior.h"


Behavior::Behavior() : _gameObject(nullptr), transform(nullptr) {}

Behavior::Behavior(GameObject& gameObject) : _gameObject(&gameObject), transform(&gameObject.transform) {}

Behavior::Behavior(GameObject& gameObject, Transform& transform) : _gameObject(&gameObject), transform(&transform) {}

template Renderer* Behavior::AddComponent(Renderer*&);

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
    T* newComponent = new T(std::forward<Args>(args)..., this);

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

