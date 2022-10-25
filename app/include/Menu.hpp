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
    Rectangle rect = {GetScreenWidth()/2.0f, -100, 150, 150};
    float rotation = 0.0f;
    float alpha = 1.0f;
    bool animationEnd = false;
    int state = 0;
    float framesCounter = 0;
    float width = GetScreenWidth();
    float height = GetScreenHeight();
};