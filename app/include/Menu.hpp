#pragma once
#include <GameManager.hpp>
#include <reasings.hpp>
class Menu
{
public:
    Menu();
    ~Menu();
    void animation();
    void hoverEffects();

private:
    GameManager *gameManager = GameManager::getInstance();
    Rectangle rect = {GetScreenWidth()/2.0f, -100, 150, 150};
    Vector2 mousePos = GetMousePosition();
    float width = GetScreenWidth();
    float height = GetScreenHeight();
    float rotation = 0.0f;
    float alpha = 1.0f;
    float framesCounter = 0;
    bool animationEnd = false;
    int state = 0;
};