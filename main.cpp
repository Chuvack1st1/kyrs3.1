#include "BehaviorManager.h"
#include "WindowManager.h"
#include "Player.h"

void LiveCircle(BehaviorManager& behaviorManager, sf::RenderWindow& window) {
    behaviorManager.GlobalStart();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        behaviorManager.GlobalUpdate(); // Call behavior updates

        window.clear();
        behaviorManager.Render();
        window.display();
    }
}

int main() {
    BehaviorManager behaviorManager;
    Player* player = behaviorManager.Instantiate<Player>();
    Player* player2 = behaviorManager.Instantiate<Player>();

    sf::RenderWindow& window = WindowManager::Instance().GetWindow();

    behaviorManager.GlobalAwake();
    LiveCircle(behaviorManager, window);
    behaviorManager.RemoveAll();

    return 0;
}
