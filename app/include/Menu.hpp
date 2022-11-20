#pragma once
#include <GameManager.hpp>
#include <reasings.hpp>
#include <Game.hpp>

class Menu
{
public:
    Menu();
    ~Menu();
    void animation();

private:
    GameManager *gameManager = GameManager::GetInstance();
    void drawMenu();
	const int buttonWidth = 280;
	const int buttonHeight = 67;
    float rotation = 0.0f;
    float alpha = 1.0f;
    float framesCounter = 0;
    bool animationEnd = false;
    int state = 0;
    Rectangle rect = {GetScreenWidth()/2.0f, -100, 150, 150};
    Vector2 mousePos = GetMousePosition();
    std::vector<std::string> buttons = { "Play.png", "Options.png", "Rules.png", "Exit.png" };
    std::vector<Vector2> buttonPositions = { {gameManager->GetScreenSize().x / 2 - this->buttonWidth / 2, gameManager->GetScreenSize().y / 2 - this->buttonHeight / 2 - 10}, {gameManager->GetScreenSize().x / 2 - this->buttonWidth / 2, gameManager->GetScreenSize().y / 2 - this->buttonHeight / 2 + 85}, {gameManager->GetScreenSize().x / 2 - this->buttonWidth / 2, gameManager->GetScreenSize().y / 2 - this->buttonHeight / 2 + 180}, {gameManager->GetScreenSize().x / 2 - this->buttonWidth / 2, gameManager->GetScreenSize().y / 2 - this->buttonHeight / 2 + 275} };
	std::vector<std::string> buttonsHover = { "PlayHover.png", "OptionsHover.png", "RulesHover.png", "ExitHover.png" };
    std::vector<std::string> images = { "MenuBackground.png" };
    std::vector<Vector2> imagePositions = { {0, 0} };
};