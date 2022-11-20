#pragma once
#include <GameManager.hpp>
#include <algorithm>
#include <vector>

class CaptchaSolver
{
public:
	CaptchaSolver();
	~CaptchaSolver();
	void UpdateGame();
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
	char text[6] = { '_' };
	int letterCount = 0;
	int ascii = 0;



	short maxLetters = 5;
	short nextWord = 0;
	bool wrong = 0;
	short wait = 0;
	int score = 0;
	bool wrongCounter = 0;

	const char* money[11] = { "0$", "40$", "80$", "120$", "160$", "200$", "240$", "280$", "320$", "360$", "400$" };

};