#include <GameManager.hpp>
#include "Menu.h"

int main()
{
	Menu menu(900, 800, "Game");
    menu.toggleFullScreenWindow(menu.GetDisplayWidth(), menu.GetDisplayHeight());
    menu.SetAll({ menu.GetDisplayWidth() / 2.0f, -100, 150, 150 }, 0.0f, 1.0f, 0, 0, LoadTexture("resources/Play.png"), false,
        LoadTexture("resources/Options.png"), LoadTexture("resources/Rules.png"), LoadTexture("resources/Exit.png"),
        LoadTexture("resources/nott.png"), LoadTexture("resources/topLeftCorner.png"), LoadTexture("resources/topRightCorner.png"),
        LoadTexture("resources/bottomLeftCorner.png"), LoadTexture("resources/bottomRightCorner.png"));

    while (!menu.GameShouldClose())
    {
        menu.Animation();

        BeginDrawing();
        ClearBackground(BLACK);

        menu.drawAnimation();
        menu.checkAnimation();

        EndDrawing();
    }

    menu.UnloadTextures();
    return 0;
}