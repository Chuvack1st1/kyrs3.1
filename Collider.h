#pragma once
#include "SFML/Graphics.hpp"
#include "Component.h"
    class Collider : public Component {
    private:
        bool isTrigger;
        sf::RectangleShape* shape;
    public:
        Collider(Behavior* behavior, const sf::RectangleShape& shapeToSet);

        Collider();


        void SetShape(sf::RectangleShape* newShape);
        void OnColliderEnter(Collider other);
    };

