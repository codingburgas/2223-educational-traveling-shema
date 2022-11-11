#pragma once
#include <GameManager.hpp>
#include <reasings.hpp>

class Menu
{
public:
    Menu();
    ~Menu();
    void animation();

private:
    GameManager *gameManager = GameManager::getInstance();
    const float width = GetScreenWidth();
    const float height = GetScreenHeight();
	const int buttonWidth = 250;
	const int buttonHeight = 75;
    float rotation = 0.0f;
    float alpha = 1.0f;
    float framesCounter = 0;
    bool animationEnd = false;
    int state = 0;
    Rectangle rect = {GetScreenWidth()/2.0f, -100, 150, 150};
    Vector2 mousePos = GetMousePosition();
    std::vector<Vector2> buttonPositions = { {this->width / 2 - this->buttonWidth / 2 - 20, this->height / 2 - this->buttonHeight / 2 - 10}, {this->width / 2 - this->buttonWidth / 2 - 20, this->height / 2 - this->buttonHeight / 2 + 85}, {this->width / 2 - this->buttonWidth / 2 - 20, this->height / 2 - this->buttonHeight / 2 + 180}, {this->width / 2 - this->buttonWidth / 2 - 20, this->height / 2 - this->buttonHeight / 2 + 275} };
    std::vector<Vector2> cloudsPositions = { {0, 0}, {this->width - 600, 0}, {0, this->height - 500}, {this->width - 600, this->height - 500}, {this->width / 2 - 750 / 2, this->height / 2 - 200 / 2 - this->buttonWidth} };
    std::vector<std::string> buttons = { "Play.png", "Options.png", "Rules.png", "Exit.png" };
	std::vector<std::string> buttonsHover = { "PlayHover.png", "OptionsHover.png", "RulesHover.png", "ExitHover.png " };
    std::vector<std::string> clouds = { "TopLeftCorner.png", "TopRightCorner.png", "BottomLeftCorner.png", "BottomRightCorner.png", "Logo.png" };
};