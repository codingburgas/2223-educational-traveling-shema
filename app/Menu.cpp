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

void Menu::SetAll(Rectangle rect, float rot, float alp, int sta, float frmsCounter, Texture2D pl, bool anim_end,
    Texture2D opt, Texture2D rls, Texture2D exit, Texture2D nott, Texture2D topLeftCorner,
    Texture2D topRightCorner, Texture2D bottomLeftCorner, Texture2D bottomRightCorner)
{
    rec = rect;
    rotation = rot;
    alpha = alp;
    state = sta;
    framesCounter = frmsCounter;
    play = pl;
    animationEnd = anim_end;
    options = opt;
    rules = rls;
    quit = exit;
    name_of_the_team = nott;
    topLCorner = topLeftCorner;
    topRCorner = topRightCorner;
    bottomLCorner = bottomLeftCorner;
    bottomRCorner = bottomRightCorner;
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
        framesCounter += 2.00f;
        rec.height = EaseBounceOut((float)framesCounter, 100, -90, 120);
        rec.width = EaseBounceOut((float)framesCounter, 100, (float)GetDisplayWidth() + 180, 120);

        if (framesCounter >= 120)
        {
            framesCounter = 0;
            state = 2;
        }
    } break;
    case 2:
    {
        framesCounter += 3.00f;
        rotation = EaseQuadOut((float)framesCounter, 0.0f, 270.0f, 240);

        if (framesCounter >= 240)
        {
            framesCounter = 0;
            state = 3;
        }
    } break;
    case 3:
    {
        framesCounter += 3.00f;
        rec.height = EaseCircOut((float)framesCounter, 10, (float)GetDisplayWidth() + 180, 120);

        if (framesCounter >= 80)
            animationEnd = true;

        if (framesCounter >= 120)
        {
            framesCounter = 0;
            state = 4;
        }
    } break;
    case 4:
    {
        framesCounter += 2.00f;
        alpha = EaseSineOut((float)framesCounter, 1.0f, -1.0f, 160);

        if (framesCounter >= 160)
        {
            framesCounter = 0;
            state = 5;
        }
    } break;
    default:
        break;
    }
}

void Menu::UnloadTextures()
{
    UnloadTexture(name_of_the_team);
    UnloadTexture(play);
    UnloadTexture(options);
    UnloadTexture(rules);
    UnloadTexture(quit);
    UnloadTexture(topLCorner);
    UnloadTexture(topRCorner);
    UnloadTexture(bottomLCorner);
    UnloadTexture(bottomRCorner);
}

void Menu::drawAnimation()
{
    DrawRectanglePro(rec, Vector2{ float(rec.width / 2 + 40), float(rec.height / 2) }, rotation, Fade(BLUE, alpha));
}

void Menu::checkAnimation()
{
    if (animationEnd)
    {
        ClearBackground(BLUE);
        MainMenu();
    }
}

void Menu::MainMenu()
{
    DrawTexture(topLCorner, 0, 0, RAYWHITE);
    DrawTexture(topRCorner, GetDisplayWidth() - topRCorner.width, 0, RAYWHITE);
    DrawTexture(bottomLCorner, 0, GetDisplayHeight() - bottomLCorner.height, RAYWHITE);
    DrawTexture(bottomRCorner, GetDisplayWidth() - bottomRCorner.width / 2, GetDisplayHeight() - bottomRCorner.height / 2, RAYWHITE);
    DrawTexture(name_of_the_team, GetDisplayWidth() / 2 - name_of_the_team.width / 2, GetDisplayHeight() / 2 - name_of_the_team.height / 2 - 250, RAYWHITE);
    DrawTexture(play, GetDisplayWidth() / 2 - play.width / 2 - 20, GetDisplayHeight() / 2 - play.height / 2 - 10, RAYWHITE);
    DrawTexture(options, GetDisplayWidth() / 2 - options.width / 2 - 20, GetDisplayHeight() / 2 - options.height / 2 + 85, RAYWHITE);
    DrawTexture(rules, GetDisplayWidth() / 2 - rules.width / 2 - 20, GetDisplayHeight() / 2 - rules.height / 2 + 180, RAYWHITE);
    DrawTexture(quit, GetDisplayWidth() / 2 - quit.width / 2 - 20, GetDisplayHeight() / 2 - quit.height / 2 + 275, RAYWHITE);
}