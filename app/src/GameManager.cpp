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
	mousePos = GetMousePosition();
	DrawText(TextFormat("Mouse Position: %f, %f", mousePos.x, mousePos.y), 10, 10, 20, LIGHTGRAY);
	Draw();
	DrawButtons();
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
	textures.clear();
	texturePositions.clear();
	for (size_t i = 0; i < buttons.size(); i++)
	{
		UnloadTexture(buttons[i]);
		UnloadTexture(onHoverButtons[i]);
	}
	buttons.clear();
	onHoverButtons.clear();
	buttonPositions.clear();
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

void GameManager::LoadButtons(std::vector<std::string> textureFiles, std::vector<std::string> onHoverTextures, std::vector<Vector2> positions)
{
	for (size_t i = 0; i < textureFiles.size(); i++)
	{
		buttons.push_back(LoadTexture(textureFiles[i].c_str()));
		onHoverButtons.push_back(LoadTexture(onHoverTextures[i].c_str()));
		buttonPositions.push_back(positions[i]);
	}
}

void GameManager::DrawButtons()
{
	for (size_t i = 0; i < buttons.size(); i++)
	{
		SetMouseCursor(MOUSE_CURSOR_DEFAULT);
		DrawTexture(buttons[i], buttonPositions[i].x, buttonPositions[i].y, WHITE);
		if (CheckCollisionPointRec(mousePos, {buttonPositions[i].x, buttonPositions[i].y, float(buttons[i].width), float(buttons[i].height)}))
		{
			SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
			DrawTexture(onHoverButtons[i], buttonPositions[i].x, buttonPositions[i].y, WHITE);
		}
	}
}

bool GameManager::isButtonClicked(size_t buttonID)
{
	if (CheckCollisionPointRec(mousePos, {buttonPositions[buttonID].x, buttonPositions[buttonID].y, float(buttons[buttonID].width), float(buttons[buttonID].height)}))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			return true;
		}
	}
	return false;
}