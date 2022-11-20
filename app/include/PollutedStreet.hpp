#pragma once
#include <GameManager.hpp>

class PollutedStreet
{
public:
	PollutedStreet();
	~PollutedStreet();
	void UpdateGame();
	int getPayout();
private:
    struct RubbishProperties {
        Vector2 pos;
        Texture2D type;
        bool cleaned;
        bool clicked;
    };
    GameManager* gameManager = GameManager::GetInstance();

    Vector2 MousePos = {0, 0};
	

    Texture2D Background;
    Texture2D FinishScreen;

    Texture2D Bar[12];
	
    Texture2D Rubbish1;
    Texture2D Rubbish2;
    Texture2D Chips;
    Texture2D Bin;
    Texture2D Food;
    Texture2D Food2;
    Texture2D Paper;
	
    int BarPos = 0;
    int Payout;
    short RemainingRubbish = 16;
    float Delay = 0;
    bool ePressed = 0;

	
    std::vector<RubbishProperties> Rubbish;
};