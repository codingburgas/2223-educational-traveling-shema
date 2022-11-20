#include "Menu.hpp"

Menu::Menu()
{
	// Loads all the textures
    gameManager->LoadScene(gameManager->SCENE::MAIN_MENU, this->m_Images, this->m_ImagePositions);

    gameManager->LoadButtons(this->m_Buttons, this->m_ButtonsHover, this->m_ButtonPositions);

    this->DrawMenu();
}

Menu::~Menu()
{
    
}

void Menu::DrawMenu()
{
	// Displays the background
    while (gameManager->CurrentScene == gameManager->SCENE::MAIN_MENU && !gameManager->GetShouldClose())
    {
        if (!this->m_AnimationEnd)
        {
            BeginDrawing();
            ClearBackground(BLACK);
            this->Animation();
            EndDrawing();
        }
        else
        {
            BeginDrawing();
            ClearBackground(BLUE);
            gameManager->Update();
            if (gameManager->IsButtonClicked(0))
            {
                Game* game = new Game();
                delete this;
                break;
            }
            if (gameManager->IsButtonClicked(1)) OpenURL("https://github.com/codingburgas/2223-educational-traveling-shema/");
            if (gameManager->IsButtonClicked(2)) OpenURL("https://github.com/codingburgas/2223-educational-traveling-shema/blob/code-refactoring/app/assets/Rules.txt");
            if (gameManager->IsButtonClicked(3))
            {
                delete gameManager;
                break;
            }
            EndDrawing();
        }
    }
}

void Menu::Animation()
{
    // Starts the animation
    if(!this->m_AnimationEnd)
    
    switch (this->m_State)
    {
    case 0:
    {
        this->m_FramesCounter += 2.00f;

        this->m_Rect.y = EaseElasticOut((float)this->m_FramesCounter, - 100, gameManager->GetScreenSize().y / 2.0f + 100, 120);

        if (this->m_FramesCounter >= 120)
        {
            this->m_FramesCounter = 0;
            this->m_State = 1;
        }
    } break;
    case 1:
    {
        this->m_FramesCounter += 2.00f;
        this->m_Rect.height = EaseBounceOut((float)this->m_FramesCounter, 100, -90, 120);
        this->m_Rect.width = EaseBounceOut((float)this->m_FramesCounter, 100, gameManager->GetScreenSize().x + 180, 120);

        if (this->m_FramesCounter >= 120)
        {
            this->m_FramesCounter = 0;
            m_State = 2;
        }
    } break;
    case 2:
    {
        this->m_FramesCounter += 3.00f;
        this->m_Rotation = EaseQuadOut((float)this->m_FramesCounter, 0.0f, 270.0f, 240);

        if (this->m_FramesCounter >= 240)
        {
            this->m_FramesCounter = 0;
            this->m_State = 3;
        }
    } break;
    case 3:
    {
        this->m_FramesCounter += 3.00f;
        this->m_Rect.height = EaseCircOut((float)this->m_FramesCounter, 10, gameManager->GetScreenSize().x + 180, 120);

        if (this->m_FramesCounter >= 80)
            this->m_AnimationEnd = true;

        if (this->m_FramesCounter >= 120)
        {
            this->m_FramesCounter = 0;
            this->m_State = 4;
        }
    } break;
    case 4:
    {
        this->m_FramesCounter += 2.00f;
        this->m_Alpha = EaseSineOut((float)this->m_FramesCounter, 1.0f, -1.0f, 160);

        if (this->m_FramesCounter >= 160)
        {
            this->m_FramesCounter = 0;
            this->m_State = 5;
        }
    } break;
    default:
        break;
    }

    DrawRectanglePro(this->m_Rect, Vector2{ float(this->m_Rect.width / 2 + 40), float(this->m_Rect.height / 2) }, this->m_Rotation, Fade(BROWN, this->m_Alpha));
}