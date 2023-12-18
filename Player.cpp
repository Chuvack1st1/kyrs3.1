#include "Player.h"


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
    // Assuming you have a Behavior pointer for the Player
    Behavior* playerBehavior = this;  // Use 'this' as the Behavior pointer for the Player

    // Create a new Renderer with the image path and the Behavior pointer
    auto playergraphics = new Renderer("C:\\Users\\stasa\\Downloads\\images.jpg", playerBehavior);

    // Add the Renderer as a component to the Player
    AddComponent<Renderer>(playergraphics);
    sf::RectangleShape shape;
    
    AddComponent<Collider>();
}


void Player::Start() {
    Init();
}

void Player::Update() {
    
    Move();
}
