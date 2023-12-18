#include "Collider.h"


Collider::Collider(const sf::RectangleShape& shapeToSet)
{
    isTrigger = false;
    // Create a new sf::RectangleShape and copy properties from shapeToSet
    shape = new sf::RectangleShape(shapeToSet.getSize());
    shape->setPosition(shapeToSet.getPosition());
    shape->setRotation(shapeToSet.getRotation());
    shape->setFillColor(shapeToSet.getFillColor());
    shape->setOutlineColor(shapeToSet.getOutlineColor());
    shape->setOutlineThickness(shapeToSet.getOutlineThickness());
}


Collider::Collider()
{
    isTrigger = false;
    shape = nullptr;
}

void Collider::SetShape(sf::RectangleShape* newShape)
{
    shape = newShape;
}

void Collider::OnColliderEnter(Collider other) {
    // Implementation of OnColliderEnter
    // You may want to handle the collision event here
}
