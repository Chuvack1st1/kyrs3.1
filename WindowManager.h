#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class WindowManager {
private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text firstframeText;
    sf::Clock clock;
    sf::Clock startupTimer;  // Added timer for startup animation

    sf::Texture backGroundTexture;
    sf::Sprite backGroundSprite;
    sf::RectangleShape background;
    // Add a sound buffer and sound object
    sf::SoundBuffer soundBuffer;
    sf::Music sound;
    // Private constructor to prevent instantiation
    WindowManager() : window(sf::VideoMode(1600, 800), "kursova Prokopchuck"), startupTimer() {
        if (!backGroundTexture.loadFromFile("C:\\Users\\stasa\\Downloads\\6857cc431acab3e.jpg"))
            std::cout << " ! ERROR::GAME::INITTEXTURES::Could not load 'Без названия (1).jpg' ! " << std::endl;

        //start playing sound

        background.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
        background.setTexture(&backGroundTexture);
        
        // Load sound buffer from file
        if (!sound.openFromFile("C:\\Users\\stasa\\Downloads\\sound.mp3")) {
            std::cout << " ! ERROR::GAME::INITSOUND::Could not load sound file! " << std::endl;
        }
        sound.setLoop(true);
        sound.setVolume(15);
        sound.play();
    }

public:
    bool showInstructions = true;
    sf::RenderWindow& GetWindow() {
        return window;
    }
    void DrawBackGround() {
        window.draw(background);
    }
    // Function to get the instance of the WindowManager
    static WindowManager& Instance() {
        static WindowManager instance;
        return instance;
    }

    // Function to update the animation
    void PlayStartAnimation() {
        if (!this->font.loadFromFile("C:\\Users\\stasa\\source\\repos\\kyrs3.1\\kyrs3.1\\Teko-Light.ttf"))
            std::cout << " ! ERROR::GAME::INITFONTS::Failed to load 'Teko-Light.ttf' ! " << std::endl;

        this->firstframeText.setFont(font);
        this->firstframeText.setString("Kursova robota \nVikonav Prokopchuck Stanislav \n");
        this->firstframeText.setFont(this->font);
        this->firstframeText.setCharacterSize(32);
        this->firstframeText.setFillColor(sf::Color(255, 255, 255, 0));
        this->firstframeText.setStyle(sf::Text::Bold);
        this->firstframeText.setPosition(300.f, 200.f);

        float fadeInDuration = 2.0f;
        float Felapsed = clock.getElapsedTime().asSeconds();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || Felapsed > fadeInDuration)
        {
            showInstructions = false;
        }

        if (showInstructions && Felapsed < fadeInDuration)
        {
            int alpha = static_cast<int>(255 * (Felapsed / fadeInDuration));
            this->firstframeText.setFillColor(sf::Color(255, 255, 255, alpha));
        }
        window.draw(firstframeText);
    }

    // Delete copy and move constructors and assignment operators
    WindowManager(const WindowManager&) = delete;
    WindowManager& operator=(const WindowManager&) = delete;
    WindowManager(WindowManager&&) = delete;
    WindowManager& operator=(WindowManager&&) = delete;
    ~WindowManager() {
        // Stop the sound and release resources
        sound.stop();
    }
};
