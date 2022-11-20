#pragma once
#include <GameManager.hpp>

class MailPackager
{
public:
	MailPackager();
	~MailPackager();
	void UpdateGame();
	int getPayout();
private:
	GameManager *gameManager = GameManager::GetInstance();
	
	Texture2D Packages[4];
	Texture2D Letters[4];
	Texture2D Background;
	Texture2D FinishScreen;
	
	Vector2 MousePos;
	Vector2 LetterPos;

	bool MailType = 0; // 1 - packages; 0 - letters
	bool NextMail = 1;
	bool Side = 1;
	int money[11] = { 0, 40, 80, 120, 160, 200, 240, 280, 320, 360, 400 };
	int MailsLeft = 11;
	int Back = 0;
	int Front = 0;
	int Payout;
	
	bool Idle = 1;
	unsigned short Score = 0;
};