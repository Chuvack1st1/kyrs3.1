// Renderer.cpp
#include "Renderer.h"

// Rest of your Renderer.cpp file



// Constructor taking a Behavior pointer
Renderer::Renderer(Renderer* renderer, Behavior* behavior)
    : Component(behavior), isVisible(renderer->GetIsVisible()), sprite(renderer->GetSprite()), texture(renderer->GetTexture()), behavior(behavior) {}

// Copy constructor taking a Behavior pointer
Renderer::Renderer(Renderer& renderer, Behavior* behavior)
    : Component(behavior), isVisible(renderer.GetIsVisible()), sprite(renderer.GetSprite()), texture(renderer.GetTexture()), behavior(behavior) {}

Renderer::Renderer(const std::string& imagePath, Behavior* behavior)
    : Component(behavior), behavior(behavior) {
    if (!texture.loadFromFile(imagePath)) {
        std::cerr << "Failed to load image: " << imagePath << std::endl;
    }
    sprite.setTexture(texture);
}

bool Renderer::GetIsVisible() const {
    return isVisible;
}

sf::Sprite Renderer::GetSprite() const {
    return sprite;
}
sf::Texture Renderer::GetTexture() const {
    return texture;
}
void Renderer::SetSpritePosition(Vector2 position) {
    sprite.setPosition(position.x, position.y);
}

void Renderer::Render() const{
    
    WindowManager::Instance().GetWindow().draw(sprite);  // Assuming `window` is defined and accessible
}

void Renderer::UpdatePosition()
{
    SetSpritePosition(GetBehavior()->transform->position);
}
