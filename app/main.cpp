#include "raylib.h"

class Game {
public:
	Game() {
		InitWindow(800, 600, "raylib [core] example - basic window");
		SetTargetFPS(60);
	}
	~Game() {
		CloseWindow();
	}
	void run() {
		while (!WindowShouldClose()) {
			BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawText("Window", 400 - MeasureText("Window", 20) / 2, 300 - 10, 20, LIGHTGRAY);
			EndDrawing();
		}
	}
};

int main(void)
{
	Game* game = new Game();
	game->run();
}