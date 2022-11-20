#pragma once
#include <GameManager.hpp>

class SeaMinigame
{
public:
	SeaMinigame();
	~SeaMinigame();;
	void UpdateGame();
	int GetPayout();
private:
	// Creates a rubbish structure with the following properties
	struct RUBBISH {
		int x = 0;
		int y = 0;
		short type = 0;
		bool isClicked = 0;
		bool isCleaned = 0;
	};
	// Gets the game manager instance
	GameManager* gameManager = GameManager::GetInstance();

	Texture2D m_Waves = LoadTexture((gameManager->GetAssetPath() + "SeaMinigame/waves.png").c_str());
	Texture2D m_Bag = LoadTexture((gameManager->GetAssetPath() + "SeaMinigame/bag.png").c_str());
	Texture2D m_Can = LoadTexture((gameManager->GetAssetPath() + "SeaMinigame/can.png").c_str());
	Texture2D m_Bottle = LoadTexture((gameManager->GetAssetPath() + "SeaMinigame/bottle.png").c_str());
	Texture2D m_Hook = LoadTexture((gameManager->GetAssetPath() + "SeaMinigame/hook.png").c_str());
	Texture2D m_Rope = LoadTexture((gameManager->GetAssetPath() + "SeaMinigame/rope.png").c_str());

	Vector2 m_MousePos;

	RUBBISH m_RubbishArray[20];
	bool m_Carrying = 0;
	short m_RemainingRubbish = 20;
	int m_Payout = 0;


	void RandomizeRubbish();
};