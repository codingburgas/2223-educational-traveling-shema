#include "GameManager.hpp"

GameManager::GameManager()
{
	this->m_screenHeight = GetScreenHeight();
	this->m_screenWidth = GetScreenWidth();
	InitWindow(this->m_screenWidth, this->m_screenHeight, "Game Window");
	ToggleFullscreen();
	SetTargetFPS(this->k_windowFPS);
}
GameManager::~GameManager()
{
	CloseWindow();
}
void GameManager::Update()
{
	BeginDrawing();
	ClearBackground(BLACK);
	m_mousePos = GetMousePosition();
	DrawText(TextFormat("Mouse Position: %f, %f", this->m_mousePos.x, this->m_mousePos.y), 10, 10, 20, LIGHTGRAY);
	DrawTextures();
	DrawButtons();
	EndDrawing();
}
void GameManager::DrawTextures()
{
	for (size_t i = 0; i < this->textures.size(); i++)
	{
		DrawTexture(this->textures[i], this->texturePositions[i].x, this->texturePositions[i].y, WHITE);
	}
}

bool GameManager::getShouldClose()
{
	return WindowShouldClose();
}
void GameManager::UnloadScene()
{
	for (size_t i = 0; i < this->textures.size(); i++)
	{
		UnloadTexture(this->textures[i]);
	}
	this->textures.clear();
	this->texturePositions.clear();
	for (size_t i = 0; i < this->buttons.size(); i++)
	{
		UnloadTexture(this->buttons[i]);
		UnloadTexture(this->onHoverButtons[i]);
	}
	this->buttons.clear();
	this->onHoverButtons.clear();
	this->buttonPositions.clear();
}
void GameManager::LoadScene(SCENE sceneID, std::vector<std::string> textureFiles, std::vector<Vector2> positions)
{
	if (this->currentScene != sceneID)
	{
		UnloadScene();
		this->currentScene = sceneID;
		for (int i = 0; i < textureFiles.size(); i++)
		{
			this->textures.push_back(LoadTexture(textureFiles[i].c_str()));
			this->texturePositions.push_back(positions[i]);
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
		this->buttons.push_back(LoadTexture(textureFiles[i].c_str()));
		this->onHoverButtons.push_back(LoadTexture(onHoverTextures[i].c_str()));
		this->buttonPositions.push_back(positions[i]);
	}
}

void GameManager::DrawButtons()
{
	for (size_t i = 0; i < this->buttons.size(); i++)
	{
		SetMouseCursor(MOUSE_CURSOR_DEFAULT);
		DrawTexture(this->buttons[i], this->buttonPositions[i].x, this->buttonPositions[i].y, WHITE);
		Rectangle buttonRect = { this->buttonPositions[i].x, this->buttonPositions[i].y, this->buttons[i].width, this->buttons[i].height };
		if (CheckCollisionPointRec(this->m_mousePos, buttonRect))
		{
			SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
			DrawTexture(this->onHoverButtons[i], this->buttonPositions[i].x, this->buttonPositions[i].y, WHITE);
		}
	}
}

bool GameManager::isButtonClicked(size_t buttonID)
{
	if (buttonID >= this->buttons.size())
	{
		std::cout << "Button ID out of range\n";
		return false;
	}
	Rectangle buttonRect = { this->buttonPositions[buttonID].x, this->buttonPositions[buttonID].y, this->buttons[buttonID].width, this->buttons[buttonID].height };
	if (CheckCollisionPointRec(this->m_mousePos, buttonRect))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			return true;
		}
	}
	return false;
}
