#pragma once
#include "SFML/Graphics.hpp"
#include "Component.h"
#include "Vector2.h"

class Behavior;
class Renderer : public Component {
private:
    bool isVisible = true;
    sf::Sprite sprite;
    sf::Texture texture;

public:
    // Constructor taking an image path and a Behavior pointer
    Renderer(Behavior* behavior, const std::string& imagePath);
    void SetSpritePosition(Vector2 position);
    bool GetIsVisible() const;
    sf::Sprite GetSprite() const;
    sf::Texture GetTexture() const;
    void Render() const;  // Pass the window as a parameter

    void UpdatePosition() override;
};
