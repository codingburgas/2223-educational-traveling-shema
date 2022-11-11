#include "Menu.hpp"
Menu::Menu()
{
    gameManager->LoadScene(gameManager->SCENE::MAIN_MENU, this->clouds, this->cloudsPositions);

    gameManager->LoadButtons(this->buttons, this->buttonsHover, this->buttonPositions);

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

        this->rect.y = EaseElasticOut((float)this->framesCounter, - 100, this->height / 2.0f + 100, 120);

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
        this->rect.width = EaseBounceOut((float)this->framesCounter, 100, this->width + 180, 120);

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
        this->rect.height = EaseCircOut((float)this->framesCounter, 10, this->width + 180, 120);

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