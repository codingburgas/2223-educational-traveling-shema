#pragma once
#include <GameManager.hpp>

class MailPackager
{
public:
	MailPackager();
	~MailPackager();
	void UpdateGame();
	int GetPayout();
private:
	// Gets the game manager instance
	GameManager *gameManager = GameManager::GetInstance();
	
	Texture2D m_Packages[4];
	Texture2D m_Letters[4];
	Texture2D m_Background;
	Texture2D m_FinishScreen;
	
	Vector2 m_MousePos;
	Vector2 m_LetterPos;

	bool m_MailType = 0; // 1 - packages; 0 - letters
	bool m_NextMail = 1;
	bool m_Side = 1;
	int m_Money[11] = { 0, 40, 80, 120, 160, 200, 240, 280, 320, 360, 400 };
	int m_MailsLeft = 11;
	int m_Back = 0;
	int m_Front = 0;
	int m_Payout;
	
	bool m_Idle = 1;
	unsigned short m_Score = 0;
};