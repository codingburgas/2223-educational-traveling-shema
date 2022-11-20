#pragma once
#include <time.h>
#include <GameManager.hpp>

class MailPackager
{
public:
	MailPackager();
	~MailPackager();
	void UpdateGame();
private:
	GameManager *gameManager = GameManager::GetInstance();
	
	Texture2D Packages[4];
	Texture2D Letters[4];
	Texture2D Background;
	Texture2D FinishScreen;
	
	Vector2 MousePos;

	int MailsLeft = 11;
	bool MailType = 0; // 1 - packages; 0 - letters
	bool NextMail = 1;
	bool Side = 1;
	int Back = 0;
	int Front = 0;
	bool Idle = 1;
	Vector2 LetterPos;
	unsigned short Score = 0;
};