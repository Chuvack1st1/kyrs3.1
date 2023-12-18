#include "Player.h"
#include "Collider.h"
#include "Vector2.h"
#include "Renderer.h"
#include <iostream>

void Player::Init() {
    transform->position.x = 0.1f;
    transform->position.y = 0.1f;
}

void Player::Move() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        transform->position = transform->position + Vector2(0, 1);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        transform->position = transform->position + Vector2(0, -1);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        transform->position = transform->position + Vector2(-1, 0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        transform->position = transform->position + Vector2(1, 0);
    }
    std::cout << transform->position.x << " " << transform->position.y << " \n";
}

void Player::Awake() {
    const std::string imagePath = "C:\\Users\\stasa\\Downloads\\images.jpg";
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
