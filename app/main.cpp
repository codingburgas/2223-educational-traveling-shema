#include <raylib.h>
#include "Menu.h"

int main(void)
{
	const int screenWidth = 900;
	const int screenHeight = 800;

	Menu menu(screenWidth, screenHeight, "Game");

	while (!menu.GameShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		EndDrawing();
	}

	return 0;
}