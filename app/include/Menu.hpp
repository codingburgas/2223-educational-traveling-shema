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
    GameManager *gameManager = GameManager::getInstance();
    void drawMenu();
	const int buttonWidth = 250;
	const int buttonHeight = 75;
    float rotation = 0.0f;
    float alpha = 1.0f;
    float framesCounter = 0;
    bool animationEnd = false;
    int state = 0;
    Rectangle rect = {GetScreenWidth()/2.0f, -100, 150, 150};
    Vector2 mousePos = GetMousePosition();
    std::vector<Vector2> buttonPositions = { {gameManager->getScreenSize().x / 2 - this->buttonWidth / 2 - 20, gameManager->getScreenSize().y / 2 - this->buttonHeight / 2 - 10}, {gameManager->getScreenSize().x / 2 - this->buttonWidth / 2 - 20, gameManager->getScreenSize().y / 2 - this->buttonHeight / 2 + 85}, {gameManager->getScreenSize().x / 2 - this->buttonWidth / 2 - 20, gameManager->getScreenSize().y / 2 - this->buttonHeight / 2 + 180}, {gameManager->getScreenSize().x / 2 - this->buttonWidth / 2 - 20, gameManager->getScreenSize().y / 2 - this->buttonHeight / 2 + 275} };
    std::vector<Vector2> cloudsPositions = { {0, 0}, {gameManager->getScreenSize().x - 600, 0}, {0, gameManager->getScreenSize().y - 500}, {gameManager->getScreenSize().x - 600, gameManager->getScreenSize().y - 500}, {gameManager->getScreenSize().x / 2 - 750 / 2, gameManager->getScreenSize().y / 2 - 200 / 2 - this->buttonWidth} };
    std::vector<std::string> buttons = { "Play.png", "Options.png", "Rules.png", "Exit.png" };
	std::vector<std::string> buttonsHover = { "PlayHover.png", "OptionsHover.png", "RulesHover.png", "ExitHover.png " };
    std::vector<std::string> clouds = { "TopLeftCorner.png", "TopRightCorner.png", "BottomLeftCorner.png", "BottomRightCorner.png", "Logo.png" };
};