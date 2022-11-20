#include <GameManager.hpp>
#include <Menu.hpp>
GameManager *GameManager::instance;
GameManager::GameManager()
{
	srand(time(NULL));
	SetWindowIcon(LoadImage((this->GetAssetPath() + "Logo.png").c_str()));
	SetConfigFlags(FLAG_VSYNC_HINT);
	InitWindow(1920, 1080, "Game Window");
	SetExitKey(KEY_NULL);
	this->m_Impact = LoadFontEx((this->GetAssetPath() + "impact.ttf").c_str(), 1000, 0, 0);
	ToggleFullscreen();
}
GameManager::~GameManager()
{
	CloseWindow();
}
GameManager *GameManager::GetInstance()
{
	// Singleton
	// If the instance is null, create a new instance
	if(!instance)
	{
		instance = new GameManager();
	}
	return instance;
}
std::string GameManager::GetAssetPath()
{
	return this->m_AssetPath;
}
void GameManager::Update()
{
	this->m_MousePos = GetMousePosition();
	DrawTextures();
	DrawButtons();
}
void GameManager::DrawTextures()
{
	// Draws the textures
	for (size_t i = 0; i < this->m_Textures.size(); i++)
	{
		DrawTextureEx(this->m_Textures[i], this->m_TexturePositions[i], 0, GetScreenSize().x / 1920, WHITE);
	}
}

bool GameManager::GetShouldClose()
{
	return WindowShouldClose();
}
void GameManager::UnloadScene()
{
	// Unloads the scene
	for (size_t i = 0; i < this->m_Textures.size(); i++)
	{
		UnloadTexture(this->m_Textures[i]);
	}
	this->m_Textures.clear();
	this->m_TexturePositions.clear();
	for (size_t i = 0; i < this->m_Buttons.size(); i++)
	{
		UnloadTexture(this->m_Buttons[i]);
		UnloadTexture(this->m_OnHoverButtons[i]);
	}
	this->m_Buttons.clear();
	this->m_OnHoverButtons.clear();
	this->m_ButtonPositions.clear();
}
void GameManager::LoadScene(SCENE sceneID, std::vector<std::string> textureFiles, std::vector<Vector2> positions)
{
	// Loads the scene
	if (this->CurrentScene != sceneID)
	{
		UnloadScene();
		this->CurrentScene = sceneID;
		for (int i = 0; i < textureFiles.size(); i++)
		{
			textureFiles[i] = this->GetAssetPath() + textureFiles[i];
			this->m_Textures.push_back(LoadTexture(textureFiles[i].c_str()));
			this->m_TexturePositions.push_back(positions[i]);
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
	// Loads the buttons
	for (size_t i = 0; i < textureFiles.size(); i++)
	{
		textureFiles[i] = "./assets/" + textureFiles[i];
		onHoverTextures[i] = "./assets/" + onHoverTextures[i];
		this->m_Buttons.push_back(LoadTexture(textureFiles[i].c_str()));
		this->m_OnHoverButtons.push_back(LoadTexture(onHoverTextures[i].c_str()));
		this->m_ButtonPositions.push_back(positions[i]);
	}
}

void GameManager::DrawButtons()
{
	// Draws the buttons
	SetMouseCursor(MOUSE_CURSOR_DEFAULT);
	for (size_t i = 0; i < this->m_Buttons.size(); i++)
	{
		DrawTexture(this->m_Buttons[i], this->m_ButtonPositions[i].x, this->m_ButtonPositions[i].y, WHITE);
		Rectangle buttonRect = { this->m_ButtonPositions[i].x, this->m_ButtonPositions[i].y, this->m_Buttons[i].width, this->m_Buttons[i].height };
		if (CheckCollisionPointRec(this->m_MousePos, buttonRect))
		{
			SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
			DrawTexture(this->m_OnHoverButtons[i], this->m_ButtonPositions[i].x, this->m_ButtonPositions[i].y, WHITE);
		}
	}
}

bool GameManager::IsButtonClicked(size_t buttonID)
{
	// Checks if a button is clicked
	if (buttonID >= this->m_Buttons.size())
	{
		std::cout << "Button ID out of range\n";
		return false;
	}
	Rectangle buttonRect = { this->m_ButtonPositions[buttonID].x, this->m_ButtonPositions[buttonID].y, this->m_Buttons[buttonID].width, this->m_Buttons[buttonID].height };
	if (CheckCollisionPointRec(this->m_MousePos, buttonRect))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			return true;
		}
	}
	return false;
}
Vector2 GameManager::GetScreenSize()
{
	return Vector2{ float(GetScreenWidth()), float(GetScreenHeight())};
}
void GameManager::StartTimer(double seconds)
{
	this->m_StartTime = GetTime();
	this->m_TimerDuration = seconds;
}
bool GameManager::TimerEnded()
{
	return (GetTime() - this->m_StartTime) >= this->m_TimerDuration;
}