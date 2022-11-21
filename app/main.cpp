#include <GameManager.hpp>
#include <Menu.hpp>
#include <Game.hpp>

int main()
{
    // Gets the Game manager instance
    GameManager* gameManager = GameManager::GetInstance();
	// Creates instance of the Menu class
    Menu* mainMenu = new Menu();
    return 0;
}