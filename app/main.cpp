#include <GameManager.hpp>
#include "Menu.h"

int main()
{
	Menu menu(900, 800, "Game");
    menu.toggleFullScreenWindow(menu.GetDisplayWidth(), menu.GetDisplayHeight());
    menu.SetAll({ menu.GetDisplayWidth() / 2.0f, -100, 150, 150 }, 0.0f, 1.0f, 0, 0);

    while (!menu.GameShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }
}