#pragma once
#include <raylib.h>
#include <vector>
#include <iostream>


class GameManager
{
public:
	static GameManager* getInstance();
	enum SCENE
	{
		NO_SCENE,
		MAIN_MENU,
		GAME
	};
	SCENE currentScene = NO_SCENE;
	void Update();
	bool getShouldClose();
	void LoadScene(SCENE sceneID, std::vector<std::string> textureFiles, std::vector<Vector2> positions);
	void LoadButtons(std::vector<std::string> textureFiles, std::vector<std::string> onHoverTextures, std::vector<Vector2> positions);
	void DrawTextures();
	void DrawButtons();
	bool isButtonClicked(size_t buttonID);
	void UnloadScene();
	Vector2 getScreenSize();
	~GameManager();

private:
	GameManager();
	static GameManager* instance;
	const int k_windowFPS = 60;
	float m_screenWidth;
	float m_screenHeight;
	Vector2 m_mousePos = {0, 0};
	std::vector<Texture2D> m_textures;
	std::vector<Vector2> m_texturePositions;
	std::vector<Texture2D> m_buttons;
	std::vector<Texture2D> m_onHoverButtons;
	std::vector<Vector2> m_buttonPositions;
};