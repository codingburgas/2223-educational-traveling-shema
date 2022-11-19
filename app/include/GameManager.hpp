#pragma once
#include <raylib.h>
#include <vector>
#include <iostream>


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
	SCENE currentScene = NO_SCENE;
	std::string getAssetPath();
	void Update();
	bool GetShouldClose();
	void LoadScene(SCENE sceneID, std::vector<std::string> textureFiles, std::vector<Vector2> positions);
	void LoadButtons(std::vector<std::string> textureFiles, std::vector<std::string> onHoverTextures, std::vector<Vector2> positions);
	void DrawTextures();
	void DrawButtons();
	void UnloadScene();
	bool IsButtonClicked(size_t buttonID);
	Vector2 GetScreenSize();
	void StartTimer(double seconds);
	bool TimerEnded();
	~GameManager();
	Font impact;

private:
	GameManager();
	static GameManager* instance;
	const int k_windowFPS = 60;
	float m_width = GetScreenWidth();
	float m_height = GetScreenHeight();
	Vector2 m_mousePos = {0, 0};
	const std::string m_assetPath = "./assets/";
	std::vector<Texture2D> m_textures;
	std::vector<Vector2> m_texturePositions;
	std::vector<Texture2D> m_buttons;
	std::vector<Texture2D> m_onHoverButtons;
	std::vector<Vector2> m_buttonPositions;
	double m_startTime = 0;
	double m_timerDuration = 0;
	
};