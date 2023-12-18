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
#include "Player.h"
#include <iostream>
#include <list>
using namespace std;
    class Collider : public Component {
    private:
        bool isTrigger;
        sf::RectangleShape* shape;
    public:
        Collider(const sf::RectangleShape& shapeToSet);

        Collider();


        void SetShape(sf::RectangleShape* newShape);
        void OnColliderEnter(Collider other);
    };

