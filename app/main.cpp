#include <GameManager.hpp>
#include <Menu.hpp>

int main()
{
    GameManager *gameManager = GameManager::getInstance(); 
    Menu* mainMenu = new Menu();
    while (gameManager->NO_SCENE && !gameManager->getShouldClose())
    {
        gameManager->Update();
    }
    return 0;
}