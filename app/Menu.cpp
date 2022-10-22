#include <raylib.h> 
#include "Menu.h"

Menu::Menu(int width, int height, std::string title)
{
    InitWindow(width, height, title.c_str());
    SetWindowPosition(0, 0);
    SetTargetFPS(60);
}

Menu::~Menu() noexcept
{
    CloseWindow();
}

bool Menu::GameShouldClose() const
{
    return WindowShouldClose();
}

void Menu::toggleFullScreenWindow(int windowWidth, int windowHeight)
{
    if (!IsWindowFullscreen())
    {
        int monitor = GetCurrentMonitor();
        SetWindowSize(GetMonitorWidth(monitor), GetMonitorHeight(monitor));
    }
    else
    {
        ToggleFullscreen();
        SetWindowSize(windowWidth, windowHeight);
    }
}

int Menu::GetDisplayWidth() const
{
    if (IsWindowFullscreen())
    {
        int monitor = GetCurrentMonitor();
        return GetMonitorWidth(monitor);
    }
    else
    {
        return GetScreenWidth();
    }
}

int Menu::GetDisplayHeight() const
{
    if (IsWindowFullscreen())
    {
        int monitor = GetCurrentMonitor();
        return GetMonitorHeight(monitor);
    }
    else
    {
        return GetScreenHeight();
    }
}