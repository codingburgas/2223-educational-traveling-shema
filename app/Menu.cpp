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

void Menu::SetAll(Rectangle rect, float rot, float alp, int sta, float frmsCounter)
{
    rec = rect;
    rotation = rot;
    alpha = alp;
    state = sta;
    framesCounter = frmsCounter;
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

void Menu::Animation()
{
    switch (state)
    {
    case 0:
    {
        framesCounter += 2.00f;

        rec.y = EaseElasticOut((float)framesCounter, -100, GetDisplayHeight() / 2.0f + 100, 120);

        if (framesCounter >= 120)
        {
            framesCounter = 0;
            state = 1;
        }
    } break;
    case 1:
    {
        
    } break;
    case 2:
    {
        
    } break;
    case 3:
    {
        
    } break;
    case 4:
    {
        
    } break;
    default:
        break;
    }
}