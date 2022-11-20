#pragma once
#include <GameManager.hpp>

class CaptchaSolver
{
public:
	CaptchaSolver();
	~CaptchaSolver();
	void UpdateGame();
	int getPayout();
private:
	GameManager* gameManager = GameManager::GetInstance();
	std::vector<std::string> Words = {
		"HELLo",
		"wORLD",
		"VSCPI",
		"BINGO",
		"words",
		"mails",
		"SharP",
		"seize",
		"LOREM",
		"IPSUM"
	};
	Texture2D FinishScreen;
	
	char Text[6] = { '_' };
	const int Money[11] = { 0, 40, 80, 120, 160, 200, 240, 280, 320, 360, 400 };
	int LetterCount = 0;
	int ASCII = 0;
	int Score = 0;
	
	float Delay = 0;

	short MaxLetters = 5;
	short NextWord = 0;
	bool Wrong = 0;
	bool WrongCounter = 0;


};