#include "Player.h"
#include "Collider.h"
#include "Vector2.h"
#include "Renderer.h"
#include <iostream>

void Player::Init() {
    transform->SetPosition(Vector2(100.0f, 100.0f));
}

void Player::Move() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        transform->SetPosition(Vector2(0, -1) + transform->GetPosition()); 
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        transform->SetPosition(Vector2(0, 1) + transform->GetPosition());
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        transform->SetPosition(Vector2(-1, 0) + transform->GetPosition());
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        transform->SetPosition(Vector2(1, 0) + transform->GetPosition());
    }
}

void Player::Awake() {
    const std::string imagePath = "C:\\Users\\stasa\\Downloads\\pixil-frame-0 (4).png";
    renderer = AddComponent<Renderer>(imagePath);

    const sf::RectangleShape shape;
    collider = AddComponent<Collider>(shape);
}


void Player::Start() {
    Init();
}

void Player::Update() {
    
    Move();
}
