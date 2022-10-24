#pragma once
#include "raylib.h"
#include <vector>
#include <iostream>


class GameManager
{
public:
	enum SCENE
	{
		NO_SCENE,
		MAIN_MENU
	};
	
	GameManager();
	void Update();
	bool getShouldClose();
	void LoadScene(SCENE sceneID, std::vector<std::string> textureFiles, std::vector<Vector2> positions);
	void LoadButtons(std::vector<std::string> textureFiles, std::vector<std::string> onHoverTextures, std::vector<Vector2> positions);
	void DrawTextures();
	void DrawButtons();
	bool isButtonClicked(size_t buttonID);
	void UnloadScene();
	~GameManager();

private:
	const int k_windowFPS = 60;
	int m_screenWidth;
	int m_screenHeight;
	Vector2 m_mousePos = {0, 0};
	SCENE currentScene = NO_SCENE;
	std::vector<Texture2D> textures;
	std::vector<Vector2> texturePositions;
	std::vector<Texture2D> buttons;
	std::vector<Texture2D> onHoverButtons;
	std::vector<Vector2> buttonPositions;
};