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
	for (size_t i = 0; i < this->m_textures.size(); i++)
	{
		DrawTexture(this->m_textures[i], this->m_texturePositions[i].x, this->m_texturePositions[i].y, WHITE);
	}
}

bool GameManager::getShouldClose()
{
	return WindowShouldClose();
}
void GameManager::UnloadScene()
{
	for (size_t i = 0; i < this->m_textures.size(); i++)
	{
		UnloadTexture(this->m_textures[i]);
	}
	this->m_textures.clear();
	this->m_texturePositions.clear();
	for (size_t i = 0; i < this->m_buttons.size(); i++)
	{
		UnloadTexture(this->m_buttons[i]);
		UnloadTexture(this->m_onHoverButtons[i]);
	}
	this->m_buttons.clear();
	this->m_onHoverButtons.clear();
	this->m_buttonPositions.clear();
}
void GameManager::LoadScene(SCENE sceneID, std::vector<std::string> textureFiles, std::vector<Vector2> positions)
{
	if (this->currentScene != sceneID)
	{
		UnloadScene();
		this->currentScene = sceneID;
		for (int i = 0; i < textureFiles.size(); i++)
		{
			this->m_textures.push_back(LoadTexture(textureFiles[i].c_str()));
			this->m_texturePositions.push_back(positions[i]);
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
		this->m_buttons.push_back(LoadTexture(textureFiles[i].c_str()));
		this->m_onHoverButtons.push_back(LoadTexture(onHoverTextures[i].c_str()));
		this->m_buttonPositions.push_back(positions[i]);
	}
}

void GameManager::DrawButtons()
{
	for (size_t i = 0; i < this->m_buttons.size(); i++)
	{
		SetMouseCursor(MOUSE_CURSOR_DEFAULT);
		DrawTexture(this->m_buttons[i], this->m_buttonPositions[i].x, this->m_buttonPositions[i].y, WHITE);
		Rectangle buttonRect = { this->m_buttonPositions[i].x, this->m_buttonPositions[i].y, this->m_buttons[i].width, this->m_buttons[i].height };
		if (CheckCollisionPointRec(this->m_mousePos, buttonRect))
		{
			SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
			DrawTexture(this->m_onHoverButtons[i], this->m_buttonPositions[i].x, this->m_buttonPositions[i].y, WHITE);
		}
	}
}

bool GameManager::isButtonClicked(size_t buttonID)
{
	if (buttonID >= this->m_buttons.size())
	{
		std::cout << "Button ID out of range\n";
		return false;
	}
	Rectangle buttonRect = { this->m_buttonPositions[buttonID].x, this->m_buttonPositions[buttonID].y, this->m_buttons[buttonID].width, this->m_buttons[buttonID].height };
	if (CheckCollisionPointRec(this->m_mousePos, buttonRect))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			return true;
		}
	}
	return false;
}
