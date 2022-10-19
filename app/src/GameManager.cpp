#include "GameManager.hpp"

GameManager::GameManager()
{
	InitWindow(screenWidth, screenHeight, "Game Window");
	SetTargetFPS(60);
}
GameManager::~GameManager()
{
	CloseWindow();
}
void GameManager::Update()
{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
		EndDrawing();
}

bool GameManager::getShouldClose()
{
	shouldClose = WindowShouldClose();
	return shouldClose;
}