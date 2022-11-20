#include <GameManager.hpp>
#include <Menu.hpp>
#include <Game.hpp>

int main()
{
    // Creates instance of the Game manager class
    GameManager* gameManager = GameManager::GetInstance();
	// Creates instance of the Menu class
    Menu* mainMenu = new Menu();
    return 0;
}