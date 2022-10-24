#pragma once
#include "raylib.h"
#include <vector>
#include <iostream>

enum SCENE
{
	NO_SCENE,
	MAIN_MENU
};

class GameManager
{
public:
	GameManager();
	void Update();
	bool getShouldClose();
	void LoadScene(SCENE sceneID, std::vector<std::string> textureFiles, std::vector<Vector2> positions);
	void LoadButtons(std::vector<std::string> textureFiles, std::vector<std::string> onHoverTextures, std::vector<Vector2> positions);
	void Draw();
	void DrawButtons();
	bool isButtonClicked(size_t buttonID);
	void UnloadScene();
	~GameManager();

private:
	int screenWidth = GetScreenWidth();
	int screenHeight = GetScreenHeight();
	Vector2 mousePos;
	SCENE currentScene = NO_SCENE;
	std::vector<Texture2D> textures;
	std::vector<Vector2> texturePositions;
	std::vector<Texture2D> buttons;
	std::vector<Texture2D> onHoverButtons;
	std::vector<Vector2> buttonPositions;
};