#pragma once
#include "Behavior.h"
#include "Collider.h"
#include "Renderer.h"
#include "Player.h"
#include <chrono>


class Cat : public Behavior {
private:
    Vector2 currentPosition;
    Vector2 direction;  // Added direction variable

    std::chrono::steady_clock::time_point lastChangeTime;
    const float runSpeed = 10;

    Collider* collider;
    Renderer* renderer;
    Player* _player;

    void Init();
    void Move();

public:
    Cat(Player* player);
    

    void Awake() override;
    void Start() override;
    void Update() override;
};

