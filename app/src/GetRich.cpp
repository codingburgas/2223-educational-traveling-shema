#include <GetRich.hpp>

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
int questionCounter = 0, answerCounter = 0;
Color color1 = BLACK, color2 = BLACK, color3 = BLACK, color4 = BLACK;

=======
>>>>>>> 87eb3c1 (feat(backend): add questions and answers)
=======
int questionCounter = 0, answerCounter = 0;
Color color1 = BLACK, color2 = BLACK, color3 = BLACK, color4 = BLACK;

>>>>>>> aa6ab0f (feat(backend): implement question printing)
const char questions[15][100] =
=======
GetRich::GetRich()
>>>>>>> bc0e718 (refactor(backend): optimize get rich minigame codebase)
=======
GetRich::GetRich()
>>>>>>> bc0e7180a15fed193dc7ae969649f7307c69785a
{
    this->Background = LoadTexture((gameManager->getAssetPath() + "background.png").c_str());
    this->FinishScreen = LoadTexture((gameManager->getAssetPath() + "finish-screen.png").c_str());

    for (int i = 0; i < 4; i++)
    {
        this->ButtonHover[i] = LoadTexture((gameManager->getAssetPath() + "background-" + std::to_string(i + 1) + ".png").c_str());
        this->CorrectAnswer[i] = LoadTexture((gameManager->getAssetPath() + "correct-answer-" + std::to_string(i + 1) + ".png").c_str());
        this->WrongAnswer[i] = LoadTexture((gameManager->getAssetPath() + "wrong-answer-" + std::to_string(i + 1) + ".png").c_str());

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> aa6ab0f (feat(backend): implement question printing)
const char reward[16][11] ={ "    0$    ", "   100$   ", "   200$   ", "   300$   ", "   500$   ", "  1,000$  ", "  2,000$  ", "  4,000$  ", "  8,000$  ", " 16,000$  ", " 32,000$ ", " 64,000$ ", " 125,000$ ", " 250,000$ ", " 500,000$ ", "1,000,000$" };
short correctAnswers[15] = { 0, 1, 2, 1, 3, 2, 0, 2, 0, 0, 1, 1, 1, 3, 3};

void displayQuestion()
{
    DrawText(questions[questionCounter], 190, 535, 35, RAYWHITE);
    DrawText("BANK:", 315, 120, 30, ORANGE);
    DrawText(reward[questionCounter], 270, 170, 40, RAYWHITE);
    DrawText(answers[answerCounter], 190, 770, 30, color1);
    DrawText(answers[answerCounter+1], 936, 770, 30, color2);
    DrawText(answers[answerCounter+2], 190, 957, 30, color3);
    DrawText(answers[answerCounter+3], 936, 957, 30, color4);
}

<<<<<<< HEAD
int main()
=======
    }
}

GetRich::~GetRich()
>>>>>>> bc0e718 (refactor(backend): optimize get rich minigame codebase)
{
    UnloadTexture(this->Background);
    UnloadTexture(this->FinishScreen);
    for (int i = 0; i < 4; i++)
    {
        UnloadTexture(this->ButtonHover[i]);
        UnloadTexture(this->CorrectAnswer[i]);
        UnloadTexture(this->WrongAnswer[i]);
    }
}

const char reward[16][11] = { "    0$    ", "   100$   ", "   200$   ", "   300$   ", "   500$   ", "  1,000$  ", "  2,000$  ", "  4,000$  ", "  8,000$  ", " 16,000$  ", " 32,000$ ", " 64,000$ ", " 125,000$ ", " 250,000$ ", " 500,000$ ", "1,000,000$" };

void GetRich::displayQuestion()
{
    DrawText((questions[this->QuestionCounter].question).c_str(), 190, 535, 35, RAYWHITE);
    DrawText("BANK:", 315, 120, 30, ORANGE);
    DrawText(reward[this->QuestionCounter], 270, 170, 40, RAYWHITE);
    DrawText(questions[this->QuestionCounter].answer[0].c_str(), 190, 770, 30, this->colors[0]);
    DrawText(questions[this->QuestionCounter].answer[1].c_str(), 936, 770, 30, this->colors[1]);
    DrawText(questions[this->QuestionCounter].answer[2].c_str(), 190, 957, 30, this->colors[2]);
    DrawText(questions[this->QuestionCounter].answer[3].c_str(), 936, 957, 30, this->colors[3]);
}

void GetRich::UpdateGame()
{
    while (!this->Finish)
    {
        BeginDrawing();
        ClearBackground(BLACK);
        this->MousePos = GetMousePosition();
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        if (!(this->SelectedQuestion == questions[this->QuestionCounter].correctIndex) && this->SelectedQuestion != 4)
        {
            DrawTexture(WrongAnswer[this->SelectedQuestion], 0, 0, WHITE);
            if (this->Delay >= 2)
            {
                this->Delay = 0;
                this->Finish = 1;
            }
            this->Delay += GetFrameTime();

        }
        else if (this->SelectedQuestion == questions[this->QuestionCounter].correctIndex && this->SelectedQuestion != 4)
        {
            DrawTexture(CorrectAnswer[this->SelectedQuestion], 0, 0, WHITE);

            if (this->Delay >= 2)
            {
                this->SelectedQuestion = 4;
                this->Delay = 0;
                this->QuestionCounter++;
                AnswerCounter += 4;
            }
            this->Delay += GetFrameTime();

        }
        else if (MousePos.x >= 157 && MousePos.x <= 757 && MousePos.y >= 695 && MousePos.y <= 835)
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            DrawTexture(ButtonHover[0], 0, 0, WHITE);
            this->colors[0] = WHITE;
            this->colors[1] = BLACK;
            this->colors[2] = BLACK;
            this->colors[3] = BLACK;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                this->SelectedQuestion = 0;
            }
        }
        else if (MousePos.x >= 903 && MousePos.x <= 1503 && MousePos.y >= 695 && MousePos.y <= 835)
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            DrawTexture(ButtonHover[1], 0, 0, WHITE);
            this->colors[0] = BLACK;
            this->colors[1] = WHITE;
            this->colors[2] = BLACK;
            this->colors[3] = BLACK;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                this->SelectedQuestion = 1;
            }
        }
        else if (MousePos.x >= 157 && MousePos.x <= 757 && MousePos.y >= 885 && MousePos.y <= 1020)
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            DrawTexture(ButtonHover[2], 0, 0, WHITE);
            this->colors[0] = BLACK;
            this->colors[1] = BLACK;
            this->colors[2] = WHITE;
            this->colors[3] = BLACK;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                this->SelectedQuestion = 2;
            }
        }
        else if (MousePos.x >= 903 && MousePos.x <= 1503 && MousePos.y >= 885 && MousePos.y <= 1020)
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            DrawTexture(ButtonHover[3], 0, 0, WHITE);
            this->colors[0] = BLACK;
            this->colors[1] = BLACK;
            this->colors[2] = BLACK;
            this->colors[3] = WHITE;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                this->SelectedQuestion = 3;
            }
        }
        else
        {
            DrawTexture(Background, 0, 0, WHITE);
            this->colors[0] = BLACK;
            this->colors[1] = BLACK;
            this->colors[2] = BLACK;
            this->colors[3] = BLACK;
        }
        if (this->QuestionCounter == 15)
        {
            this->Finish = 1;
        }
        displayQuestion();
        EndDrawing();
    }

    gameManager->StartTimer(3);

<<<<<<< HEAD
    CloseWindow();
    return 0;
=======
=======
>>>>>>> 87eb3c1 (feat(backend): add questions and answers)
=======
>>>>>>> aa6ab0f (feat(backend): implement question printing)
int main()
=======
    }
}

GetRich::~GetRich()
>>>>>>> bc0e7180a15fed193dc7ae969649f7307c69785a
{
    UnloadTexture(this->Background);
    UnloadTexture(this->FinishScreen);
    for (int i = 0; i < 4; i++)
    {
        UnloadTexture(this->ButtonHover[i]);
        UnloadTexture(this->CorrectAnswer[i]);
        UnloadTexture(this->WrongAnswer[i]);
    }
}

const char reward[16][11] = { "    0$    ", "   100$   ", "   200$   ", "   300$   ", "   500$   ", "  1,000$  ", "  2,000$  ", "  4,000$  ", "  8,000$  ", " 16,000$  ", " 32,000$ ", " 64,000$ ", " 125,000$ ", " 250,000$ ", " 500,000$ ", "1,000,000$" };

void GetRich::displayQuestion()
{
    DrawText((questions[this->QuestionCounter].question).c_str(), 190, 535, 35, RAYWHITE);
    DrawText("BANK:", 315, 120, 30, ORANGE);
    DrawText(reward[this->QuestionCounter], 270, 170, 40, RAYWHITE);
    DrawText(questions[this->QuestionCounter].answer[0].c_str(), 190, 770, 30, this->colors[0]);
    DrawText(questions[this->QuestionCounter].answer[1].c_str(), 936, 770, 30, this->colors[1]);
    DrawText(questions[this->QuestionCounter].answer[2].c_str(), 190, 957, 30, this->colors[2]);
    DrawText(questions[this->QuestionCounter].answer[3].c_str(), 936, 957, 30, this->colors[3]);
}

<<<<<<< HEAD
    SetTargetFPS(60);

<<<<<<< HEAD
>>>>>>> 967dc07 (feat(backend): add neccessary libraries)
=======
    while (!WindowShouldClose())
=======
void GetRich::UpdateGame()
{
    while (!this->Finish)
>>>>>>> bc0e7180a15fed193dc7ae969649f7307c69785a
    {
        BeginDrawing();
        ClearBackground(BLACK);
        this->MousePos = GetMousePosition();
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        if (!(this->SelectedQuestion == questions[this->QuestionCounter].correctIndex) && this->SelectedQuestion != 4)
        {
            DrawTexture(WrongAnswer[this->SelectedQuestion], 0, 0, WHITE);
            if (this->Delay >= 2)
            {
                this->Delay = 0;
                this->Finish = 1;
            }
            this->Delay += GetFrameTime();

        }
        else if (this->SelectedQuestion == questions[this->QuestionCounter].correctIndex && this->SelectedQuestion != 4)
        {
            DrawTexture(CorrectAnswer[this->SelectedQuestion], 0, 0, WHITE);

            if (this->Delay >= 2)
            {
                this->SelectedQuestion = 4;
                this->Delay = 0;
                this->QuestionCounter++;
                AnswerCounter += 4;
            }
            this->Delay += GetFrameTime();

        }
        else if (MousePos.x >= 157 && MousePos.x <= 757 && MousePos.y >= 695 && MousePos.y <= 835)
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            DrawTexture(ButtonHover[0], 0, 0, WHITE);
            this->colors[0] = WHITE;
            this->colors[1] = BLACK;
            this->colors[2] = BLACK;
            this->colors[3] = BLACK;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                this->SelectedQuestion = 0;
            }
        }
        else if (MousePos.x >= 903 && MousePos.x <= 1503 && MousePos.y >= 695 && MousePos.y <= 835)
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            DrawTexture(ButtonHover[1], 0, 0, WHITE);
            this->colors[0] = BLACK;
            this->colors[1] = WHITE;
            this->colors[2] = BLACK;
            this->colors[3] = BLACK;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                this->SelectedQuestion = 1;
            }
        }
        else if (MousePos.x >= 157 && MousePos.x <= 757 && MousePos.y >= 885 && MousePos.y <= 1020)
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            DrawTexture(ButtonHover[2], 0, 0, WHITE);
            this->colors[0] = BLACK;
            this->colors[1] = BLACK;
            this->colors[2] = WHITE;
            this->colors[3] = BLACK;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                this->SelectedQuestion = 2;
            }
        }
        else if (MousePos.x >= 903 && MousePos.x <= 1503 && MousePos.y >= 885 && MousePos.y <= 1020)
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            DrawTexture(ButtonHover[3], 0, 0, WHITE);
            this->colors[0] = BLACK;
            this->colors[1] = BLACK;
            this->colors[2] = BLACK;
            this->colors[3] = WHITE;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                this->SelectedQuestion = 3;
            }
        }
        else
        {
            DrawTexture(Background, 0, 0, WHITE);
            this->colors[0] = BLACK;
            this->colors[1] = BLACK;
            this->colors[2] = BLACK;
            this->colors[3] = BLACK;
        }
        if (this->QuestionCounter == 15)
        {
            this->Finish = 1;
        }
        displayQuestion();
        EndDrawing();
    }

    gameManager->StartTimer(3);

<<<<<<< HEAD
    CloseWindow();
    return 0;
>>>>>>> 87eb3c1 (feat(backend): add questions and answers)
}
=======
=======
>>>>>>> bc0e7180a15fed193dc7ae969649f7307c69785a
    while (!gameManager->TimerEnded())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(FinishScreen, 0, 0, WHITE);
        DrawText("Congratulations!", 50, 250, 100, RAYWHITE);
        DrawText("You have won ", 55, 420, 80, RAYWHITE);
        DrawText(reward[this->QuestionCounter], 55, 570, 250, ORANGE);
        EndDrawing();
    }
}
<<<<<<< HEAD
>>>>>>> bc0e718 (refactor(backend): optimize get rich minigame codebase)
=======
>>>>>>> bc0e7180a15fed193dc7ae969649f7307c69785a
