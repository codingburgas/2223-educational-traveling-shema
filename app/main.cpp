#include <GameManager.hpp>
#include <Menu.hpp>

int main()
{
    GameManager *gameManager = GameManager::getInstance(); 
    Menu* mainMenu = new Menu();
    while (!gameManager->getShouldClose())
    {
        gameManager->Update();
    }
    return 0;
}