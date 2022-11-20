#include <GameManager.hpp>
#include <Menu.hpp>
#include <Game.hpp>

int main()
{
    GameManager* gameManager = GameManager::GetInstance();
    Menu* mainMenu = new Menu();
    return 0;
}