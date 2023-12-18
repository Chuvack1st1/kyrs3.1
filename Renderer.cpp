// Renderer.cpp
#include "Renderer.h"
#include "WindowManager.h"
#include "Transform.h"
#include <iostream>

// Rest of your Renderer.cpp file

Renderer::Renderer(Behavior* behavior,const std::string& imagePath )
    : Component(behavior) {
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
