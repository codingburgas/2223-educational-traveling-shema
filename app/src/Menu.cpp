#include "Menu.hpp"
Menu::Menu()
{
    gameManager->LoadScene(gameManager->SCENE::MAIN_MENU, 
		{ "TopLeftCorner.png", "TopRightCorner.png", "BottomLeftCorner.png", "BottomRightCorner.png", "Logo.png", "Play.png", "Options.png", "Rules.png", "Exit.png" },
        { { 0,0 } , { this->width - 600, 0 } , { 0, this->height - 500 } , { this->width - 600, this->height - 500} , { this->width / 2 - 750 / 2, this->height / 2 - 200 / 2 - 250 } , { this->width / 2 - 250 / 2 - 20, this->height / 2 - 75 / 2 - 10 } , { this->width / 2 - 250 / 2 - 20, this->height / 2 - 75 / 2 + 85 } , { this->width / 2 - 250 / 2 - 20, this->height / 2 - 75 / 2 + 180 }, { this->width / 2 - 250 / 2 - 20, this->height / 2 - 75 / 2 + 275 } });

    while (gameManager->MAIN_MENU && !gameManager->getShouldClose())
    {
        if (!this->animationEnd)
        {
            BeginDrawing();
            ClearBackground(BLACK);
            this->animation();
            this->hoverEffects();
            EndDrawing();
        }
        else
        {
            ClearBackground(BLUE);
            gameManager->Update();
        }
    }
}

Menu::~Menu()
{
    gameManager->UnloadScene();
}

void Menu::animation()
{
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

void Menu::hoverEffects()
{
	Rectangle playBounds = { this->width / 2 - 250 / 2 - 20, this->height / 2 - 75 / 2 - 10, 250, 75 };
	Rectangle optionsBounds = { this->width / 2 - 250 / 2 - 20, this->height / 2 - 75 / 2 + 85, 250, 75 };
	Rectangle rulesBounds = { this->width / 2 - 250 / 2 - 20, this->height / 2 - 75 / 2 + 180, 250, 75 };
	Rectangle exitBounds = { this->width / 2 - 250 / 2 - 20, this->height / 2 - 75 / 2 + 275, 250, 75 };
    if (CheckCollisionPointRec(this->mousePos, playBounds) && this->animationEnd)
    {
        gameManager->LoadScene(gameManager->SCENE::MAIN_MENU,
            { "TopLeftCorner.png", "TopRightCorner.png", "BottomLeftCorner.png", "BottomRightCorner.png", "Logo.png", "PlayHover.png", "Options.png", "Rules.png", "Exit.png" },
            { { 0,0 } , { this->width - 600, 0 } , { 0, this->height - 500 } , { this->width - 600, this->height - 500} , { this->width / 2 - 750 / 2, this->height / 2 - 200 / 2 - 250 } , { this->width / 2 - 250 / 2 - 20, this->height / 2 - 75 / 2 - 10 } , { this->width / 2 - 250 / 2 - 20, this->height / 2 - 75 / 2 + 85 } , { this->width / 2 - 250 / 2 - 20, this->height / 2 - 75 / 2 + 180 }, { this->width / 2 - 250 / 2 - 20, this->height / 2 - 75 / 2 + 275 } });

        //DrawTexture(playHover, this->width / 2 - playHover.width / 2 - 20, this->height / 2 - playHover.height / 2 - 10, RAYWHITE);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            DrawText("Play button is working!", 200, this->height / 2, 24, RAYWHITE);
            ClearBackground(BLUE);
        }
    }

    if (CheckCollisionPointRec(this->mousePos, optionsBounds) && animationEnd)
    {
        gameManager->LoadScene(gameManager->SCENE::MAIN_MENU,
            { "TopLeftCorner.png", "TopRightCorner.png", "BottomLeftCorner.png", "BottomRightCorner.png", "Logo.png", "Play.png", "OptionsHover.png", "Rules.png", "Exit.png" },
            { { 0,0 } , { this->width - 600, 0 } , { 0, this->height - 500 } , { this->width - 600, this->height - 500} , { this->width / 2 - 750 / 2, this->height / 2 - 200 / 2 - 250 } , { this->width / 2 - 250 / 2 - 20, this->height / 2 - 75 / 2 - 10 } , { this->width / 2 - 250 / 2 - 20, this->height / 2 - 75 / 2 + 85 } , { this->width / 2 - 250 / 2 - 20, this->height / 2 - 75 / 2 + 180 }, { this->width / 2 - 250 / 2 - 20, this->height / 2 - 75 / 2 + 275 } });

        //DrawTexture(optionsHover, this->width / 2 - optionsHover.width / 2 - 20, this->height / 2 - optionsHover.height / 2 + 85, RAYWHITE);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            DrawText("Settings button is working!", 200, this->height / 2, 24, RAYWHITE);
            ClearBackground(BLUE);
        }
    }

    if (CheckCollisionPointRec(this->mousePos, rulesBounds) && animationEnd)
    {
        gameManager->LoadScene(gameManager->SCENE::MAIN_MENU,
            { "TopLeftCorner.png", "TopRightCorner.png", "BottomLeftCorner.png", "BottomRightCorner.png", "Logo.png", "Play.png", "Options.png", "RulesOptions.png", "Exit.png" },
            { { 0,0 } , { this->width - 600, 0 } , { 0, this->height - 500 } , { this->width - 600, this->height - 500} , { this->width / 2 - 750 / 2, this->height / 2 - 200 / 2 - 250 } , { this->width / 2 - 250 / 2 - 20, this->height / 2 - 75 / 2 - 10 } , { this->width / 2 - 250 / 2 - 20, this->height / 2 - 75 / 2 + 85 } , { this->width / 2 - 250 / 2 - 20, this->height / 2 - 75 / 2 + 180 }, { this->width / 2 - 250 / 2 - 20, this->height / 2 - 75 / 2 + 275 } });

        //DrawTexture(rulesHover, this->width / 2 - rulesHover.width / 2 - 20, this->height / 2 - rulesHover.height / 2 + 180, RAYWHITE);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            DrawText("Rules button is working!", 200, this->height / 2, 24, RAYWHITE);
            ClearBackground(BLUE);
        }
    }

    if (CheckCollisionPointRec(this->mousePos, exitBounds) && animationEnd)
    {
        gameManager->LoadScene(gameManager->SCENE::MAIN_MENU,
            { "TopLeftCorner.png", "TopRightCorner.png", "BottomLeftCorner.png", "BottomRightCorner.png", "Logo.png", "Play.png", "Options.png", "Rules.png", "ExitHover.png" },
            { { 0,0 } , { this->width - 600, 0 } , { 0, this->height - 500 } , { this->width - 600, this->height - 500} , { this->width / 2 - 750 / 2, this->height / 2 - 200 / 2 - 250 } , { this->width / 2 - 250 / 2 - 20, this->height / 2 - 75 / 2 - 10 } , { this->width / 2 - 250 / 2 - 20, this->height / 2 - 75 / 2 + 85 } , { this->width / 2 - 250 / 2 - 20, this->height / 2 - 75 / 2 + 180 }, { this->width / 2 - 250 / 2 - 20, this->height / 2 - 75 / 2 + 275 } });

        //DrawTexture(quitHover, this->width / 2 - quitHover.width / 2 - 20, this->height / 2 - quitHover.height / 2 + 275, RAYWHITE);

        /*if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            isRunning = false;
        }*/
    }
}