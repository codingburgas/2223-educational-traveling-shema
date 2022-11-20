#pragma once
#include <GameManager.hpp>

class SeaMinigame
{
public:
	SeaMinigame();
	~SeaMinigame();;
	void UpdateGame();
	int getPayout();
private:
	struct rubbish {
		int x = 0;
		int y = 0;
		short type = 0;
		bool isClicked = 0;
		bool isCleaned = 0;
	};
	GameManager* gameManager = GameManager::GetInstance();

	Texture2D waves = LoadTexture((gameManager->getAssetPath() + "waves.png").c_str());
	Texture2D bag = LoadTexture((gameManager->getAssetPath() + "bag.png").c_str());
	Texture2D can = LoadTexture((gameManager->getAssetPath() + "can.png").c_str());
	Texture2D bottle = LoadTexture((gameManager->getAssetPath() + "bottle.png").c_str());
	Texture2D hook = LoadTexture((gameManager->getAssetPath() + "hook.png").c_str());
	Texture2D rope = LoadTexture((gameManager->getAssetPath() + "rope.png").c_str());

	Vector2 MousePos;

	rubbish rubbishArray[20];
	bool carrying = 0;
	short RemainingRubbish = 20;
	int Payout = 0;


	void RandomizeRubbish();
};