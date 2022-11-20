#pragma once
#include <GameManager.hpp>

class Hangman
{
public:
	Hangman();
	~Hangman();
	void UpdateGame();
	int getPayout();
private:
	GameManager* gameManager = GameManager::GetInstance();
	Texture2D Rope;
	Texture2D FinishScreen;
	Texture2D BodyParts[6];

	std::string Words[20] = {
	"dance," "dilligent", "fall", "steel", "beggar", "cleave", "page", "lush", "unruly", "trolley",
	"ball", "achieve", "detect", "wander", "behave", "ingest", "cart", "yield", "fast", "garden" 
	};

	bool Alphabet[26] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	bool BodyPartsPrint[6] = { 0, 0, 0, 0, 0, 0 };

	int RandomWord = rand() % 20;

	int x = 0, y = 0;

	int Counter = 0;
	int CounterBodyParts = 0;
	int CorrectLetters = 0;
	int Index = 0;
	int Key = 0;
	int Length = Words[RandomWord].length();
	bool LetterCounter[26] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	bool FlagEnd = false;

	std::string WordConvertor = "";
	std::string Letter = "";
	std::string CopyWord = Words[RandomWord];

	int Payout = 0;
};