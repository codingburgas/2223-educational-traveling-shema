#pragma once
#include <string>

class Menu
{
public:
    Menu(int width, int height, std::string title);
    ~Menu() noexcept;

    bool GameShouldClose() const;

    void toggleFullScreenWindow(int windowWidth, int windowHeight);

    int GetDisplayWidth() const;
    int GetDisplayHeight() const;

    void Animation();
    void drawAnimation();

    void SetAll(Rectangle rect, float rot, float alp, int sta, float frmsCounter);

private:
    Rectangle rec;
    float rotation = 0.0f;
    float alpha = 0.0f;

    bool animationEnd = false;

    int state = 0;
    float framesCounter = 0;
};