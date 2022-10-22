#include <GameManager.hpp>
#include "Menu.h"

int main()
{
	Menu menu(900, 800, "Game");
    menu.toggleFullScreenWindow(menu.GetDisplayWidth(), menu.GetDisplayHeight());

    while (!menu.GameShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }
}