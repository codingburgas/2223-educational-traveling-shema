#pragma once
#include <GameManager.hpp>

class PollutedStreet
{
public:
	PollutedStreet();
	~PollutedStreet();
	void UpdateGame();
	int GetPayout();
private:
    // Creates a rubbish properties structure with the following properties
    struct RUBBISH_PROPERTIES {
        Vector2 pos;
        Texture2D type;
        bool cleaned;
        bool clicked;
    };
	// Gets the game manager instance
    GameManager* gameManager = GameManager::GetInstance();

    Vector2 m_MousePos = {0, 0};
	

    Texture2D m_Background;
    Texture2D m_FinishScreen;

    Texture2D m_Bar[12];
	
    Texture2D m_Rubbish1;
    Texture2D m_Rubbish2;
    Texture2D m_Chips;
    Texture2D m_Bin;
    Texture2D m_Food;
    Texture2D m_Food2;
    Texture2D m_Paper;
	
    int m_BarPos = 0;
    int m_Payout;
    short m_RemainingRubbish = 16;
    float m_Delay = 0;
    bool m_ePressed = 0;

	
    std::vector<RUBBISH_PROPERTIES> m_Rubbish;
};