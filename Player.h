#pragma once

#include "Behavior.h"

#include "Component.h"
#include "GameObject.h"
#include "Transform.h"
#include "Collider.h"
#include "Renderer.h"

class Player : public Behavior {
private:
    Collider* collider;
    Renderer* renderer;

    void Init();
    void Move();

public:
    void Awake() override;
    void Start() override;
    void Update() override;
};
