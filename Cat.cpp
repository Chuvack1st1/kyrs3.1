#include "Cat.h"
#include "Player.h"
#include "Collider.h"
#include "Vector2.h"
#include "Renderer.h"
#include <iostream>

void Cat::Init() {
    transform->SetPosition(Vector2(500.0f, 500.0f));
}

double FindDistance(Vector2 vector) {
   return sqrt(pow(vector.x, 2) + pow(vector.y, 2));
}
Vector2 GenerateRandomPoint() {
    // Генерація випадкової точки в межах екрану (замініть це відповідно до вашого контексту)
    return Vector2(rand() % 1600, rand() % 800);
}
void Cat::Move() {
    Vector2 directionFromPlayerToCat;

    directionFromPlayerToCat.x = transform->GetPosition().x - _player->transform->GetPosition().x;
    directionFromPlayerToCat.y = transform->GetPosition().y - _player->transform->GetPosition().y;

    double distance = FindDistance(directionFromPlayerToCat);

    if (distance < 300) {
        //run
        float timeScale = 500;
        Vector2 lefttry( Vector2(directionFromPlayerToCat.y * runSpeed / timeScale, -directionFromPlayerToCat.x * runSpeed / timeScale));
        Vector2 righttry( Vector2(-directionFromPlayerToCat.y * runSpeed / timeScale, directionFromPlayerToCat.x * runSpeed / timeScale));
        if (FindDistance(lefttry) < FindDistance(righttry)) {
            transform->SetPosition(transform->GetPosition() + righttry + _player->transform->GetPosition() / 100);
        }
        else {
            transform->SetPosition(transform->GetPosition() + lefttry + _player->transform->GetPosition() / 100);
        }

    }
    else {
        //rendom move
        Vector2 currentPosition = transform->GetPosition();
        auto currentTime = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::duration<double>>(currentTime - lastChangeTime).count();

        // Check if 2 seconds have passed since the last change
        if (elapsedTime >= 2.0) {
            // Generate a new random point for direction change
            Vector2 randomPoint = GenerateRandomPoint();

            // Calculate new direction towards the random point
            direction = (randomPoint - currentPosition).Normalize();

            // Update the time of the last change
            lastChangeTime = currentTime;
        }

        // Move in the current direction
        float moveSpeed = 0.5f;  // Speed of movement
        Vector2 newPosition = currentPosition + direction * moveSpeed;
        transform->SetPosition(newPosition);


    }

}

Cat::Cat(Player* player)
{
    _player = player;
}

void Cat::Awake() {
    const std::string imagePath = "C:\\Users\\stasa\\Downloads\\pixil-frame-0 (3).png";
    renderer = AddComponent<Renderer>(imagePath);
    const sf::RectangleShape shape;
    collider = AddComponent<Collider>(shape);
}


void Cat::Start() {
    Init();
}

void Cat::Update() {

    Move();
}
