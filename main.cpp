#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <memory>

sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");

class GameObject; // Forward declaration

class Object {
public:
    virtual ~Object() = default;  // Add a virtual destructor
};

struct Vector2 {
    double x, y;
    Vector2() : x(0), y(0) {}
    Vector2(double SetX, double SetY) : x(SetX), y(SetY) {}
    Vector2(const Vector2& otherVector) : x(otherVector.x), y(otherVector.y) {}
};

class Transform : public Object {
public:
    GameObject* gameobject; // Pointer to GameObject

    Vector2 position;

    Transform() : gameobject(nullptr), position() {}
    Transform(const Transform& transform) : gameobject(transform.gameobject), position(transform.position) {}
};

class GameObject : public Object {
public:
    Transform transform;

    GameObject() : transform() {
        transform.gameobject = this; // Set the gameobject pointer in Transform to this GameObject
    }
};

class Renderer : public Object {
private:
    bool isVisible = true;
    sf::Sprite sprite;
    sf::Texture texture;  

public:
    Renderer(const std::string& imagePath) {
        if (!texture.loadFromFile(imagePath)) {
            std::cerr << "Failed to load image: " << imagePath << std::endl;
        }
        sprite.setTexture(texture);
    }

    void Render() {
        window.draw(sprite);
    }
};


class Behavior : public Object {
private:
    std::list<std::unique_ptr<Object>> Components;

public:
    using BehaviorType = Behavior;
    GameObject* _gameObject; // Pointer to GameObject
    Transform* transform; // Pointer to Transform

    Behavior(GameObject& gameObject) : _gameObject(&gameObject), transform(&gameObject.transform) {}
    Behavior(GameObject& gameObject, Transform& transform) : _gameObject(&gameObject), transform(&transform) {}

    template <typename T>
    void AddComponent(std::unique_ptr<T> obj) {
        std::cout << "added " << typeid(T).name() << std::endl;

        Components.push_front(std::move(obj));
    }

    virtual void Awake() {}
    virtual void Start() {}
    virtual void Update() {}

    virtual void TryRender()
    {
        for (auto& renderer : Components) {
            auto behavior = dynamic_cast<Renderer*>(renderer.get());
            if (behavior) {
                behavior->Render();
            }
        }
    }
};

class BehaviorManager {
private:
    std::list<std::unique_ptr<Object>> objects;

    void AddObject(std::unique_ptr<Object> object) {
        objects.push_front(std::move(object));
    }

public:
    void GlobalAwake() {
        for (auto& object : objects) {
            auto behavior = dynamic_cast<Behavior*>(object.get());
            if (behavior) {
                behavior->Awake();
            }
        }
    }

    void GlobalStart() {
        for (auto& object : objects) {
            auto behavior = dynamic_cast<Behavior*>(object.get());
            if (behavior) {
                behavior->Start();
            }
        }
    }

    void GlobalUpdate() {
        for (auto& object : objects) {
            auto behavior = dynamic_cast<Behavior*>(object.get());
            if (behavior) {
                behavior->Update();
            }
        }
    }

    void RemoveAll() {
        objects.clear();
    }

    void Render() {
        for (auto& object : objects) {
            auto behavior = dynamic_cast<Behavior*>(object.get());
            if (behavior) {
                behavior->TryRender();
            }
        }
    }

    template <typename T, typename... Args>
    T Instantiate(GameObject& gameObject, Args&&... args) {
        T object{ gameObject, std::forward<Args>(args)... }; // Use the parameterized constructor of T (BehaviorType)
        AddObject(std::make_unique<T>(gameObject, std::forward<Args>(args)...));
        return object;
    }

};

void LiveCircle(sf::RenderWindow& window, BehaviorManager& behaviorManager) {

    behaviorManager.GlobalStart();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        behaviorManager.GlobalUpdate();  // Call behavior updates

        window.clear();
        behaviorManager.Render();
        window.display();
    }
}

class Player : public Behavior {
public:
    void Awake() override {

        std::unique_ptr<Renderer> playergraphics = std::make_unique<Renderer>("C:\\Users\\stasa\\Downloads\\images.jpg");
        AddComponent(std::move(playergraphics));
    }
};



int main() {

    BehaviorManager behaviorManager;
    
    GameObject gameobject;

    // Example: Instantiate a Behavior associated with the GameObject
    Player player = behaviorManager.Instantiate<Player>(gameobject);
   

    behaviorManager.GlobalAwake();

    LiveCircle(window, behaviorManager);

    behaviorManager.RemoveAll();

    return 0;
}
