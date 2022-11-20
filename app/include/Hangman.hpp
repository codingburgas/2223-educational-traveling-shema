#pragma once
#include <GameManager.hpp>

class Hangman
{
public:
	Hangman();
	~Hangman();
	void UpdateGame();
	int GetPayout();
private:
	// Gets the game manager instance
	GameManager* gameManager = GameManager::GetInstance();
	Texture2D m_Rope;
	Texture2D m_FinishScreen;
	Texture2D m_Background;
	Texture2D m_BodyParts[6];

	std::string m_Words[20] =
	{
		"dance," "dilligent", "fall", "steel", "beggar", "cleave", "page", "lush", "unruly", "trolley",
		"ball", "achieve", "detect", "wander", "behave", "ingest", "cart", "yield", "fast", "garden" 
	};

	bool m_Alphabet[26] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	bool m_BodyPartsPrint[6] = { 0, 0, 0, 0, 0, 0 };

	int m_RandomWord = rand() % 20;

	int x = 0, y = 0;

	int m_Counter = 0;
	int m_CounterBodyParts = 0;
	int m_CorrectLetters = 0;
	int m_Index = 0;
	int m_Key = 0;
	int m_Length = this->m_Words[this->m_RandomWord].length();
	bool m_LetterCounter[26] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	bool m_FlagEnd = false;

	std::string m_WordConvertor = "";
	std::string m_Letter = "";
	std::string m_CopyWord = m_Words[m_RandomWord];

	int m_Payout = 0;
};