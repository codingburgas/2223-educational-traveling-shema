#pragma once
#include <GameManager.hpp>
#include <reasings.hpp>
#include <Game.hpp>

class Menu
{
public:
    Menu();
    ~Menu();
    void Animation();

private:
    // Gets the Game manager instance
    GameManager *gameManager = GameManager::GetInstance();
    Rectangle m_Rect = {GetScreenWidth()/2.0f, -100, 150, 150};

    Vector2 m_MousePos = GetMousePosition();
	
	const int c_ButtonWidth = 280;
	const int c_ButtonHeight = 67;
	
    int m_State = 0;
	
    float m_Rotation = 0.0f;
    float m_Alpha = 1.0f;
	
    float m_FramesCounter = 0;
    bool m_AnimationEnd = false;
	
    void DrawMenu();
	
    std::vector<std::string> m_Buttons = { "Menu/Play.png", "Menu/Options.png", "Menu/Rules.png", "Menu/Exit.png" };
    std::vector<Vector2> m_ButtonPositions = { {gameManager->GetScreenSize().x / 2 - this->c_ButtonWidth / 2, gameManager->GetScreenSize().y / 2 - this->c_ButtonHeight / 2 - 10}, {gameManager->GetScreenSize().x / 2 - this->c_ButtonWidth / 2, gameManager->GetScreenSize().y / 2 - this->c_ButtonHeight / 2 + 85}, {gameManager->GetScreenSize().x / 2 - this->c_ButtonWidth / 2, gameManager->GetScreenSize().y / 2 - this->c_ButtonHeight / 2 + 180}, {gameManager->GetScreenSize().x / 2 - this->c_ButtonWidth / 2, gameManager->GetScreenSize().y / 2 - this->c_ButtonHeight / 2 + 275} };
	std::vector<std::string> m_ButtonsHover = { "Menu/PlayHover.png", "Menu/OptionsHover.png", "Menu/RulesHover.png", "Menu/ExitHover.png" };
    std::vector<std::string> m_Images = { "Menu/MenuBackground.png" };
    std::vector<Vector2> m_ImagePositions = { {0, 0} };
};