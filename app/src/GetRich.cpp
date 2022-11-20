#include <GetRich.hpp>

GetRich::GetRich()
{
	// Loads all the textures
    this->m_Background = LoadTexture((gameManager->GetAssetPath() + "GetRich/background.png").c_str());
    this->m_FinishScreen = LoadTexture((gameManager->GetAssetPath() + "GetRich/finish-screen.png").c_str());

    for (int i = 0; i < 4; i++)
    {
        this->m_ButtonHover[i] = LoadTexture((gameManager->GetAssetPath() + "GetRich/background-" + std::to_string(i + 1) + ".png").c_str());
        this->m_CorrectAnswer[i] = LoadTexture((gameManager->GetAssetPath() + "GetRich/correct-answer-" + std::to_string(i + 1) + ".png").c_str());
        this->m_WrongAnswer[i] = LoadTexture((gameManager->GetAssetPath() + "GetRich/wrong-answer-" + std::to_string(i + 1) + ".png").c_str());
    }
}

GetRich::~GetRich()
{
	// Unloads all the textures
    UnloadTexture(this->m_Background);
    UnloadTexture(this->m_FinishScreen);
    for (int i = 0; i < 4; i++)
    {
        UnloadTexture(this->m_ButtonHover[i]);
        UnloadTexture(this->m_CorrectAnswer[i]);
        UnloadTexture(this->m_WrongAnswer[i]);
    }
}

void GetRich::DisplayQuestion()
{
	// Displays the questions
    DrawText((Questions[this->m_QuestionCounter].question).c_str(), 190, 535, 35, RAYWHITE);
    DrawText("BANK:", 315, 120, 30, ORANGE);
    DrawText((std::to_string(this->m_Reward[this->m_QuestionCounter]) + "$").c_str(), 270, 170, 40, RAYWHITE);
    DrawText(Questions[this->m_QuestionCounter].answer[0].c_str(), 190, 770, 30, this->Colors[0]);
    DrawText(Questions[this->m_QuestionCounter].answer[1].c_str(), 936, 770, 30, this->Colors[1]);
    DrawText(Questions[this->m_QuestionCounter].answer[2].c_str(), 190, 957, 30, this->Colors[2]);
    DrawText(Questions[this->m_QuestionCounter].answer[3].c_str(), 936, 957, 30, this->Colors[3]);
}

void GetRich::UpdateGame()
{
	// Displays the background
    while (!this->m_Finish)
    {
        BeginDrawing();
        ClearBackground(BLACK);
        this->m_MousePos = GetMousePosition();
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        if (!(this->m_SelectedQuestion == Questions[this->m_QuestionCounter].correctIndex) && this->m_SelectedQuestion != 4)
        {
            DrawTexture(this->m_WrongAnswer[this->m_SelectedQuestion], 0, 0, WHITE);
            if (this->m_Delay >= 2)
            {
                this->m_Delay = 0;
                this->m_Finish = 1;
            }
            this->m_Delay += GetFrameTime();

        }
        else if (this->m_SelectedQuestion == this->Questions[this->m_QuestionCounter].correctIndex && this->m_SelectedQuestion != 4)
        {
            DrawTexture(this->m_CorrectAnswer[this->m_SelectedQuestion], 0, 0, WHITE);

            if (this->m_Delay >= 2)
            {
                this->m_SelectedQuestion = 4;
                this->m_Delay = 0;
                this->m_QuestionCounter++;
                m_AnswerCounter += 4;
            }
            this->m_Delay += GetFrameTime();

        }
        else if (this->m_MousePos.x >= 157 && this->m_MousePos.x <= 757 && this->m_MousePos.y >= 695 && this->m_MousePos.y <= 835)
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            DrawTexture(this->m_ButtonHover[0], 0, 0, WHITE);
            this->Colors[0] = WHITE;
            this->Colors[1] = BLACK;
            this->Colors[2] = BLACK;
            this->Colors[3] = BLACK;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                this->m_SelectedQuestion = 0;
            }
        }
        else if (this->m_MousePos.x >= 903 && this->m_MousePos.x <= 1503 && this->m_MousePos.y >= 695 && this->m_MousePos.y <= 835)
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            DrawTexture(this->m_ButtonHover[1], 0, 0, WHITE);
            this->Colors[0] = BLACK;
            this->Colors[1] = WHITE;
            this->Colors[2] = BLACK;
            this->Colors[3] = BLACK;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                this->m_SelectedQuestion = 1;
            }
        }
        else if (this->m_MousePos.x >= 157 && this->m_MousePos.x <= 757 && this->m_MousePos.y >= 885 && this->m_MousePos.y <= 1020)
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            DrawTexture(this->m_ButtonHover[2], 0, 0, WHITE);
            this->Colors[0] = BLACK;
            this->Colors[1] = BLACK;
            this->Colors[2] = WHITE;
            this->Colors[3] = BLACK;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                this->m_SelectedQuestion = 2;
            }
        }
        else if (this->m_MousePos.x >= 903 && this->m_MousePos.x <= 1503 && this->m_MousePos.y >= 885 && this->m_MousePos.y <= 1020)
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            DrawTexture(this->m_ButtonHover[3], 0, 0, WHITE);
            this->Colors[0] = BLACK;
            this->Colors[1] = BLACK;
            this->Colors[2] = BLACK;
            this->Colors[3] = WHITE;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                this->m_SelectedQuestion = 3;
            }
        }
        else
        {
            DrawTexture(this->m_Background, 0, 0, WHITE);
            this->Colors[0] = BLACK;
            this->Colors[1] = BLACK;
            this->Colors[2] = BLACK;
            this->Colors[3] = BLACK;
        }
        if (this->m_QuestionCounter == 15)
        {
            this->m_Finish = 1;
        }
        DisplayQuestion();
        EndDrawing();
    }

    gameManager->StartTimer(3);

    while (!gameManager->TimerEnded())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(this->m_FinishScreen, 0, 0, WHITE);
        DrawText("Congratulations!", 50, 250, 100, RAYWHITE);
        DrawText("You have won ", 55, 420, 80, RAYWHITE);
        DrawText((std::to_string(this->m_Reward[this->m_QuestionCounter]) + "$").c_str(), 55, 570, 250, ORANGE);
        EndDrawing();
    }
}

int GetRich::GetPayout()
{
	return this->m_Reward[this->m_QuestionCounter];
}