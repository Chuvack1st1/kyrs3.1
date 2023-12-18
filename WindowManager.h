#pragma once
#include <SFML/Graphics.hpp>
class WindowManager {
private:
    sf::RenderWindow window;

    // Private constructor to prevent instantiation
    WindowManager() : window(sf::VideoMode(800, 600), "SFML Window") {}

public:
    // Function to get the instance of the WindowManager
    static WindowManager& Instance() {
        static WindowManager instance;
        return instance;
    }

    // Function to get a reference to the sf::RenderWindow
    sf::RenderWindow& GetWindow() {
        return window;
    }

    // Add any other functionality you need

    // Delete copy and move constructors and assignment operators
    WindowManager(const WindowManager&) = delete;
    WindowManager& operator=(const WindowManager&) = delete;
    WindowManager(WindowManager&&) = delete;
    WindowManager& operator=(WindowManager&&) = delete;
};