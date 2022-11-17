<<<<<<< HEAD
#include <GameManager.hpp>
#include <Menu.hpp>
#include <Game.hpp>

int main()
{
    GameManager *gameManager = GameManager::GetInstance(); 
    Menu* mainMenu = new Menu();
    //while (!gameManager->getShouldClose())
    //{
    //    gameManager->Update();
    //}
    return 0;
=======
#include <raylib.h>
#include <time.h>
#include <stdlib.h>

int main()
{
<<<<<<< HEAD

>>>>>>> 3b6da91 (feat(backend): add necessary libraries for the sea game)
=======
	InitWindow(1920, 1080, "Mini Game Waves");
	
	while (!WindowShouldClose())
    	{
        		BeginDrawing();
        		HideCursor();
        		ClearBackground(RAYWHITE);
        	
	}
>>>>>>> be9e7d5 (feat(backend): create game window)
}