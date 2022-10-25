#include <GameManager.hpp>
#include <Menu.hpp>

int main()
{
    GameManager* gameManager = new GameManager();
    while (!gameManager->getShouldClose())
    {
        gameManager->Update();
    }
    return 0;
	/*Menu menu(900, 800, "Game");
    menu.setAll({ menu.getDisplayWidth() / 2.0f, -100, 150, 150 }, 0.0f, 1.0f, 0, 0, LoadTexture("resources/Play.png"), false,
        LoadTexture("resources/Options.png"), LoadTexture("resources/Rules.png"), LoadTexture("resources/Exit.png"),
        LoadTexture("resources/nott.png"), LoadTexture("resources/topLeftCorner.png"), LoadTexture("resources/topRightCorner.png"),
        LoadTexture("resources/bottomLeftCorner.png"), LoadTexture("resources/bottomRightCorner.png"));

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