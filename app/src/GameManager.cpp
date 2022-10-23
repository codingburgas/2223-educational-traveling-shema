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
	ClearBackground(BLACK);
	Vector2 mousePos = GetMousePosition();
	DrawText(TextFormat("Mouse Position: %f, %f", mousePos.x, mousePos.y), 10, 10, 20, LIGHTGRAY);
	Draw();
	EndDrawing();
}
void GameManager::Draw()
{
	for (size_t i = 0; i < textures.size(); i++)
	{
		DrawTexture(textures[i], texturePositions[i].x, texturePositions[i].y, WHITE);
	}
}

bool GameManager::getShouldClose()
{
	return WindowShouldClose();
}
void GameManager::UnloadScene()
{
	for (size_t i = 0; i < textures.size(); i++)
	{
		UnloadTexture(textures[i]);
	}
}
void GameManager::LoadScene(SCENE sceneID, std::vector<std::string> textureFiles, std::vector<Vector2> positions)
{
	if (currentScene != sceneID)
	{
		UnloadScene();
		currentScene = sceneID;
		for (int i = 0; i < textureFiles.size(); i++)
		{
			textures.push_back(LoadTexture(textureFiles[i].c_str()));
			texturePositions.push_back(positions[i]);
			std::cout << "Loaded Texture: " << textureFiles[i] << std::endl;
		}
	}
	else
	{
		std::cout << "Scene already loaded\n";
	}
}