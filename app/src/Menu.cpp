#include "raylib.h"
#include <Menu.hpp>
#include <GameManager.hpp>
#include <reasings.hpp>
Menu::Menu(Rectangle rect, float rot, float alp, int sta, float frmsCounter, Texture2D pl, bool anim_end,
    Texture2D opt, Texture2D rls, Texture2D exit, Texture2D nott, Texture2D topLeftCorner,
    Texture2D topRightCorner, Texture2D bottomLeftCorner, Texture2D bottomRightCorner)
{
    this->rec = rect;
    this->rotation = rot;
    this->alpha = alp;
    this->state = sta;
    this->framesCounter = frmsCounter;
    this->play = pl;
    this->animationEnd = anim_end;
    this->options = opt;
    this->rules = rls;
    this->quit = exit;
    this->nameOfTheTeam = nott;
    this->topLCorner = topLeftCorner;
    this->topRCorner = topRightCorner;
    this->bottomLCorner = bottomLeftCorner;
    this->bottomRCorner = bottomRightCorner;

    //TODO: Draw all the textures from the Menu::mainMenu function//
    //TODO: Delete the Menu::mainMenu function//
}

Menu::~Menu() noexcept
{
    CloseWindow();
}

void Menu::animation()
{
    //Magic numbers
    switch (this->state)
    {
    case 0:
    {
        this->framesCounter += 2.00f;

        this->rec.y = EaseElasticOut((float)this->framesCounter, -100, GetScreenHeight() / 2.0f + 100, 120);

        if (this->framesCounter >= 120)
        {
            this->framesCounter = 0;
            this->state = 1;
        }
    } break;
    case 1:
    {
        this->framesCounter += 2.00f;
        this->rec.height = EaseBounceOut((float)this->framesCounter, 100, -90, 120);
        this->rec.width = EaseBounceOut((float)this->framesCounter, 100, (float)GetScreenWidth() + 180, 120);

        if (this->framesCounter >= 120)
        {
            this->framesCounter = 0;
            state = 2;
        }
    } break;
    case 2:
    {
        this->framesCounter += 3.00f;
        this->rotation = EaseQuadOut((float)this->framesCounter, 0.0f, 270.0f, 240);

        if (this->framesCounter >= 240)
        {
            this->framesCounter = 0;
            this->state = 3;
        }
    } break;
    case 3:
    {
        this->framesCounter += 3.00f;
        this->rec.height = EaseCircOut((float)this->framesCounter, 10, (float)GetScreenWidth() + 180, 120);

        if (this->framesCounter >= 80)
            this->animationEnd = true;

        if (this->framesCounter >= 120)
        {
            this->framesCounter = 0;
            this->state = 4;
        }
    } break;
    case 4:
    {
        this->framesCounter += 2.00f;
        this->alpha = EaseSineOut((float)this->framesCounter, 1.0f, -1.0f, 160);

        if (this->framesCounter >= 160)
        {
            this->framesCounter = 0;
            this->state = 5;
        }
    } break;
    default:
        break;
    }
}

void Menu::unloadTextures()
{
    //TODO: use the GameManager::UnloadScene function//
    //TODO: delete this function
    UnloadTexture(this->nameOfTheTeam);
    UnloadTexture(this->play);
    UnloadTexture(this->options);
    UnloadTexture(this->rules);
    UnloadTexture(this->quit);
    UnloadTexture(this->topLCorner);
    UnloadTexture(this->topRCorner);
    UnloadTexture(this->bottomLCorner);
    UnloadTexture(this->bottomRCorner);
}

void Menu::drawAnimation()
{
    DrawRectanglePro(this->rec, Vector2{ float(this->rec.width / 2 + 40), float(this->rec.height / 2) }, this->rotation, Fade(BLUE, this->alpha));
}

void Menu::checkAnimation()
{
    if (this->animationEnd)
    {
        ClearBackground(BLUE);
        mainMenu();
    }
}

void Menu::mainMenu()
{
    //TODO: delete this function//
    //TODO: scroll up to the constructor//
    /*DrawTexture(topLCorner, 0, 0, RAYWHITE);
    DrawTexture(topRCorner, getDisplayWidth() - topRCorner.width, 0, RAYWHITE);
    DrawTexture(bottomLCorner, 0, getDisplayHeight() - bottomLCorner.height, RAYWHITE);
    DrawTexture(bottomRCorner, getDisplayWidth() - bottomRCorner.width / 2, getDisplayHeight() - bottomRCorner.height / 2, RAYWHITE);
    DrawTexture(nameOfTheTeam, getDisplayWidth() / 2 - nameOfTheTeam.width / 2, getDisplayHeight() / 2 - nameOfTheTeam.height / 2 - 250, RAYWHITE);
    DrawTexture(play, getDisplayWidth() / 2 - play.width / 2 - 20, getDisplayHeight() / 2 - play.height / 2 - 10, RAYWHITE);
    DrawTexture(options, getDisplayWidth() / 2 - options.width / 2 - 20, getDisplayHeight() / 2 - options.height / 2 + 85, RAYWHITE);
    DrawTexture(rules, getDisplayWidth() / 2 - rules.width / 2 - 20, getDisplayHeight() / 2 - rules.height / 2 + 180, RAYWHITE);
    DrawTexture(quit, getDisplayWidth() / 2 - quit.width / 2 - 20, getDisplayHeight() / 2 - quit.height / 2 + 275, RAYWHITE);*/
}