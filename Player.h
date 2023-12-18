#pragma once
#include "SFML/Graphics.hpp"
#include "Vector2.h"
#include "Object.h"
#include "Component.h"
#include "Transform.h"
#include "Behavior.h"
#include "WindowManager.h"
#include "Renderer.h"
#include "GameObject.h"
#include "BehaviorManager.h"
#include <iostream>
#include <list>
using namespace std;

    class Player : public Behavior {
    private:
        void Init();
        void Move();

    public:
        void Awake() override;
        void Start() override;
        void Update() override;
    };
