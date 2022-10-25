#include <GameManager.hpp>
#include <Menu.hpp>

int main()
{
    GameManager *gameManager = GameManager::getInstance();
    while (!gameManager->getShouldClose())
    {
        gameManager->Update();
    }
    return 0;
	/*Menu menu(900, 800, "Game");
    menu.setAll();

    while (!menu.gameShouldClose())
    {
        menu.animation();

        BeginDrawing();
        ClearBackground(BLACK);

        menu.drawAnimation();
        menu.checkAnimation();

        EndDrawing();
    }

    menu.unloadTextures();
    return 0;*/
}