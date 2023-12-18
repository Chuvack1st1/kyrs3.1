// Renderer.h
#pragma once
#include "SFML/Graphics.hpp"
#include "Vector2.h"
#include "Object.h"
#include "Component.h"
#include "Transform.h"
#include "Behavior.h"
#include "WindowManager.h"
#include "GameObject.h"
#include "BehaviorManager.h"
#include "Player.h"
#include <iostream>
#include <list>
using namespace std;

    class Renderer : public Component {
    private:
        bool isVisible = true;
        sf::Sprite sprite;
        sf::Texture texture;
        Behavior* behavior;  // Add a member variable to store the associated Behavior

    public:
        // Constructor taking a Behavior pointer
        Renderer(Renderer* renderer, Behavior* behavior);

        // Copy constructor taking a Behavior pointer
        Renderer(Renderer& renderer, Behavior* behavior);

        // Constructor taking an image path and a Behavior pointer
        Renderer(const std::string& imagePath, Behavior* behavior);

        void SetSpritePosition(Vector2 position);
        bool GetIsVisible() const;
        sf::Sprite GetSprite() const;
        sf::Texture GetTexture() const;
        void Render() const;  // Pass the window as a parameter

        // Method to get the associated Behavior
        Behavior* GetBehavior() const {
            return behavior;
        }

        virtual void UpdatePosition() override;
    };

