#include "Menu.hpp"
Menu::Menu()
{
    gameManager->LoadScene(gameManager->SCENE::MAIN_MENU,
                           {"TopLeftCorner.png", "TopRightCorner.png", "BottomLeftCorner.png", "BottomRightCorner.png", "Logo.png"},
                           {{0, 0}, {this->width - 600, 0}, {0, this->height - 500}, {this->width - 600, this->height - 500}, {this->width / 2 - 750 / 2, this->height / 2 - 200 / 2 - 250}});

    gameManager->LoadButtons({"Play.png", "Options.png", "Rules.png", "Exit.png"},
                             {"PlayHover.png", "OptionsHover.png", "RulesHover.png", "ExitHover.png"},
                             {{this->width / 2 - 250 / 2 - 20, this->height / 2 - 75 / 2 - 10}, {this->width / 2 - 250 / 2 - 20, this->height / 2 - 75 / 2 + 85}, {this->width / 2 - 250 / 2 - 20, this->height / 2 - 75 / 2 + 180}, {this->width / 2 - 250 / 2 - 20, this->height / 2 - 75 / 2 + 275}});

    while (gameManager->MAIN_MENU && !gameManager->getShouldClose())
    {
        if (!this->animationEnd)
        {
            BeginDrawing();
            ClearBackground(BLACK);
            this->animation();
            EndDrawing();
        }
        else
        {
            ClearBackground(BLUE);
            gameManager->Update();
            if (gameManager->isButtonClicked(3))
            {
                delete gameManager;
            }
        }
    }
}

Menu::~Menu()
{
    gameManager->UnloadScene();
}

void Menu::animation()
{
    if(!this->animationEnd)
    
    switch (this->state)
    {
    case 0:
    {
        this->framesCounter += 2.00f;

        this->rect.y = EaseElasticOut((float)this->framesCounter, -100, height / 2.0f + 100, 120);

        if (this->framesCounter >= 120)
        {
            this->framesCounter = 0;
            this->state = 1;
        }
    } break;
    case 1:
    {
        this->framesCounter += 2.00f;
        this->rect.height = EaseBounceOut((float)this->framesCounter, 100, -90, 120);
        this->rect.width = EaseBounceOut((float)this->framesCounter, 100, width + 180, 120);

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
        this->rect.height = EaseCircOut((float)this->framesCounter, 10, width + 180, 120);

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

    DrawRectanglePro(this->rect, Vector2{ float(this->rect.width / 2 + 40), float(this->rect.height / 2) }, this->rotation, Fade(BLUE, this->alpha));
}