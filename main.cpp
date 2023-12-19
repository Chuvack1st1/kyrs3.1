//main.cpp
#include "BehaviorManager.h"
#include "WindowManager.h"
#include "Player.h"
#include "Cat.h"

void LiveCircle(BehaviorManager& behaviorManager) {
    
    behaviorManager.GlobalStart();

    while (WindowManager::Instance().GetWindow().isOpen()) {

        sf::Event event;
        while (WindowManager::Instance().GetWindow().pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                WindowManager::Instance().GetWindow().close();
        }
        WindowManager::Instance().GetWindow().clear();

        
        if (WindowManager::Instance().showInstructions) {
            WindowManager::Instance().PlayStartAnimation();
        }
        else {
            WindowManager::Instance().DrawBackGround();

            behaviorManager.GlobalUpdate(); // Call behavior updates

            behaviorManager.Render();
        }
            
        WindowManager::Instance().GetWindow().display();
    }
}

int main() {
    
    BehaviorManager behaviorManager;
    Player* player = behaviorManager.Instantiate<Player>();
    Cat* player2 = behaviorManager.Instantiate<Cat>(player);

    behaviorManager.GlobalAwake();
    LiveCircle(behaviorManager);
    behaviorManager.RemoveAll();

    return 0;
}
