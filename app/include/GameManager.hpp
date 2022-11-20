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
	// Creates a getter for the instance
	static GameManager* GetInstance();
	
	enum SCENE
	{
		NO_SCENE,
		MAIN_MENU,
		GAME
	};
	
	// Font intialization
	Font m_Impact;
	SCENE CurrentScene = NO_SCENE;
	Vector2 GetScreenSize();
	std::string GetAssetPath();
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
	Vector2 m_MousePos = {0, 0};
	std::vector<Texture2D> m_Textures;
	std::vector<Vector2> m_TexturePositions;
	std::vector<Texture2D> m_Buttons;
	std::vector<Texture2D> m_OnHoverButtons;
	std::vector<Vector2> m_ButtonPositions;
	const std::string m_AssetPath = "./assets/";
	const int c_WindowFPS = 60;
	float m_Width = GetScreenWidth();
	float m_Height = GetScreenHeight();
	double m_StartTime = 0;
	double m_TimerDuration = 0;
	
};