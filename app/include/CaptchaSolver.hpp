#pragma once
#include <GameManager.hpp>

class CaptchaSolver
{
public:
	CaptchaSolver();
	~CaptchaSolver();
	void UpdateGame();
	int GetPayout();
private:
	GameManager* gameManager = GameManager::GetInstance();
	std::vector<std::string> m_Words = {
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
	Texture2D m_Background;
	Texture2D m_FinishScreen;
	
	char m_Text[6] = { '_' };
	const int c_Money[11] = { 0, 40, 80, 120, 160, 200, 240, 280, 320, 360, 400 };
	int m_LetterCount = 0;
	int m_ASCII = 0;
	int m_Score = 0;
	
	float m_Delay = 0;

	short m_MaxLetters = 5;
	short m_NextWord = 0;
	bool m_Wrong = 0;
	bool m_WrongCounter = 0;
};