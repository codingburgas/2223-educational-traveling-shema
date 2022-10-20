#pragma once
#include "raylib.h"
#include <vector>
#include <iostream>
#include <fstream>
class GameManager
{
public:
	GameManager();
	~GameManager();
	void Update();
	bool getShouldClose();
	void LoadScene(std::string sceneName, std::vector<std::string> textureFiles, std::vector<Vector2> positions);
	void SceneError();
	void UnloadScene();
	void Draw();

private:
	int screenWidth = 800;
	int screenHeight = 450;
	std::string currentScene = "mainMenu";
	std::vector<Texture2D> textures;
	std::vector<Vector2> texturePositions;
};