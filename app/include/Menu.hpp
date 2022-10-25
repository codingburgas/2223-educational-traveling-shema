#pragma once
#include <string>
#include <raylib.h>
class Menu
{
public:
    Menu(Rectangle rect, float rot, float alp, int sta, float frmsCounter, Texture2D pl, bool anim_end,
        Texture2D opt, Texture2D rls, Texture2D exit, Texture2D nott, Texture2D topLeftCorner,
        Texture2D topRightCorner, Texture2D bottomLeftCorner, Texture2D bottomRightCorner);
    ~Menu() noexcept;

    void animation();
    void drawAnimation();
    void checkAnimation();

    void mainMenu();

    void unloadTextures();

private:
    Texture2D nameOfTheTeam;
    Texture2D play;
    Texture2D options;
    Texture2D rules;
    Texture2D quit;

    Texture2D topLCorner;
    Texture2D topRCorner;
    Texture2D bottomLCorner;
    Texture2D bottomRCorner;

    Rectangle rec;
    float rotation = 0.0f;
    float alpha = 0.0f;

    bool animationEnd = false;

    int state = 0;
    float framesCounter = 0;
};