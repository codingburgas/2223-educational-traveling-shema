#include <raylib.h>
#include <time.h>
#include <stdlib.h>
#include <string>

int main()
{
	InitWindow(1920, 1080, "Hang");
	FLAG_FULLSCREEN_MODE;

	while (!WindowShouldClose())
	{


		BeginDrawing();
		ClearBackground(BEIGE);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}