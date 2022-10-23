#pragma once
#include "raylib.h"
#include <vector>
#include <iostream>
#include <fstream>

enum SCENE
{
	NO_SCENE,
	MAIN_MENU
};

class GameManager
{
public:
	GameManager();
	~GameManager();
	void Update();
	bool getShouldClose();
	void LoadScene(SCENE sceneID, std::vector<std::string> textureFiles, std::vector<Vector2> positions);
	void SceneError();
	void UnloadScene();
	void Draw();

private:
	int screenWidth = 800;
	int screenHeight = 450;
	std::vector<Texture2D> textures;
	std::vector<Vector2> texturePositions;
	SCENE currentScene = NO_SCENE;
};