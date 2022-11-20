#pragma once
#include <GameManager.hpp>
#include <string>

class GetRich
{
public:
	GetRich();
	~GetRich();
	void UpdateGame();
	
private:
	GameManager* gameManager = GameManager::GetInstance();
	Vector2 MousePos;
	Texture2D Background;
	Texture2D ButtonHover[4];
	Texture2D CorrectAnswer[4];
	Texture2D WrongAnswer[4];
	Texture2D FinishScreen;
	Color colors[4] = { BLACK, BLACK, BLACK, BLACK };
	unsigned SelectedQuestion = 4;
	float Delay = 0;
	int QuestionCounter = 0;
	int	AnswerCounter = 0;
	/*bool Correct = 0;*/
	bool Finish = 0;
	struct questionPool
	{
		std::string question;
		std::string answer[4];
		size_t correctIndex;
	};
    questionPool questions[15] = {
		{"In Marco Polo's day, Cathay was the name for China, and Cidngo was for:", {"Japan", "Bulgaria", "Iran", "Mongolia"}, 0},
		{"Thailand was once called:", {"Sesam", "Siam", "Susam", "Sumatra",}, 1},
		{"What is Big Ben?", {"Clock", "Tower", "Bell", "House"}, 2},
		{"When was the first watch invented?", {"1700", "1500", "1400", "1893"}, 1},
		{"Who was the first man to walk on the moon?", {"Alexander Baev", "Yuri Gagarin", "Cristiano Ronaldo", "Neil Armstrong"}, 3},
		{"The country with the most square shape?", {"Canada", "Russia", "Egypt", "Bulgaria"}, 2},
		{"Which island group is only 50 miles south-east of the coast of Florida?", {"Bahamas", "Turks and Caicos Islands", "US Virgin Islands", "Bermuda"}, 0},
		{"Construction of which of these famous landmarks was completed first?", {"Empire State Building", "Eiffel Tower", "Big Ben Clock Tower", "Royal Albert Hall"}, 2},
		{"Mesopotamia lies between these two rivers?", {"Tigris and Euphrates", "Nile and Indus", "Nile and Tigris", "Indus and Nile"}, 0},
		{"Queen Anne was the daughter of which English Monarch?", {"James II", "Henry VIII", "Victoria", "William I"}, 0},
		{"What is the Celsius equivalent of 77 degrees Fahrenheit?", {"30", "25", "20", "15"}, 1},
		{"Which ancient civilization formed along the Nile River?", {"Mesopotamia", "Egypt", "Greece", "Rome"}, 1},
		{"In what year was the first iPhone released?", {"2000", "2007", "1998", "2009"}, 1},
		{"What colour were the Pyramids of Giza originally?", {"Orange", "Yellow", "Brown", "White"}, 3},
		{"Which city will host the 2028 Olympic Games?", {"Los Angeles", "Sofia", "Beijing", "Tokyo"}, 3}
    };
	void displayQuestion();

};
