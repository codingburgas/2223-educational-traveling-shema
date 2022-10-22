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
};