#pragma once
#include <raylib.h>
#include <vector>
#include <iostream>
#include <time.h>
#include <string>
#include <stdlib.h>
#include <algorithm>


class GameManager
{
public:
	static GameManager* GetInstance();
	
	enum SCENE
	{
		NO_SCENE,
		MAIN_MENU,
		GAME
	};
	
	Font impact;
	SCENE currentScene = NO_SCENE;
	Vector2 GetScreenSize();
	std::string getAssetPath();
	void Update();
	void LoadScene(SCENE sceneID, std::vector<std::string> textureFiles, std::vector<Vector2> positions);
	void LoadButtons(std::vector<std::string> textureFiles, std::vector<std::string> onHoverTextures, std::vector<Vector2> positions);
	void DrawTextures();
	void DrawButtons();
	void UnloadScene();
	void StartTimer(double seconds);
	bool IsButtonClicked(size_t buttonID);
	bool GetShouldClose();
	bool TimerEnded();
	~GameManager();

private:
	GameManager();
	static GameManager* instance;
	Vector2 m_mousePos = {0, 0};
	std::vector<Texture2D> m_textures;
	std::vector<Vector2> m_texturePositions;
	std::vector<Texture2D> m_buttons;
	std::vector<Texture2D> m_onHoverButtons;
	std::vector<Vector2> m_buttonPositions;
	const std::string m_assetPath = "./assets/";
	const int k_windowFPS = 60;
	float m_width = GetScreenWidth();
	float m_height = GetScreenHeight();
	double m_startTime = 0;
	double m_timerDuration = 0;
	
};