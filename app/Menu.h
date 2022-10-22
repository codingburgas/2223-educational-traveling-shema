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
    void checkAnimation();

    void MainMenu();

    void SetAll(Rectangle rect, float rot, float alp, int sta, float frmsCounter, Texture2D pl, bool anim_end,
        Texture2D opt, Texture2D rls, Texture2D exit, Texture2D nott, Texture2D topLeftCorner, Texture2D topRightCorner,
        Texture2D bottomLeftCorner, Texture2D bottomRightCorner);

    void UnloadTextures();

private:
    Texture2D name_of_the_team;
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