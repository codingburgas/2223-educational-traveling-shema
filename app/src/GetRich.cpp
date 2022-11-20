#include <GetRich.hpp>

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
{
    InitWindow(1920, 1080, "Get Rich");

    Texture2D background = LoadTexture("../assets/background.png");
    Texture2D buttonHover[4] = { LoadTexture("../assets/background-1.png"), LoadTexture("../assets/background-2.png"), LoadTexture("../assets/background-3.png"), LoadTexture("../assets/background-4.png") };
    
    Texture2D correctAnswer[4] = { LoadTexture("../assets/correct-answer-1.png"), LoadTexture("../assets/correct-answer-2.png"), LoadTexture("../assets/correct-answer-3.png"), LoadTexture("../assets/correct-answer-4.png") };
    Texture2D wrongAnswer[4] = { LoadTexture("../assets/wrong-answer-1.png"), LoadTexture("../assets/wrong-answer-2.png"), LoadTexture("../assets/wrong-answer-3.png"), LoadTexture("../assets/wrong-answer-4.png") };
    Texture2D finishScreen = LoadTexture("../assets/finish-screen.png");    

    short x = 0, y = 0;
    short choice = 4;
    int wait = 0;
    bool correct = 0;
    bool finish = 0;

    SetTargetFPS(60);

<<<<<<< HEAD
>>>>>>> 967dc07 (feat(backend): add neccessary libraries)
=======
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        x = GetMouseX();
        y = GetMouseY();

        if (finish)
        {
            DrawTexture(finishScreen, 0, 0, WHITE);
            DrawText("Congratulations!", 50, 250, 100, RAYWHITE);
            DrawText("You have won ", 55, 420, 80, RAYWHITE);
            DrawText(reward[questionCounter], 55, 570, 250, ORANGE);
        }
        else if (!(choice == correctAnswers[questionCounter]) && choice != 4)
        {
            DrawTexture(wrongAnswer[choice], 0, 0, WHITE);
            if (wait == 80)
            {
                wait = 0;
                finish = 1;
            }
            wait++;

        }
        else if (choice == correctAnswers[questionCounter])
        {
            DrawTexture(correctAnswer[choice], 0, 0, WHITE);

            if (wait == 80)
            {
                choice = 4;
                wait = 0;
                questionCounter++;
                answerCounter += 4;
            }
            wait++;

        }
        else if (x >= 157 && x <= 757 && y >= 695 && y <= 835)
        {
            DrawTexture(buttonHover[0], 0, 0, WHITE);
            color1 = WHITE;
            color2 = BLACK;
            color3 = BLACK;
            color4 = BLACK;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                choice = 0;
            }
        }
        else if (x >= 903 && x <= 1503 && y >= 695 && y <= 835)
        {
            DrawTexture(buttonHover[1], 0, 0, WHITE);
            color1 = BLACK;
            color2 = WHITE;
            color3 = BLACK;
            color4 = BLACK;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                choice = 1;
            }
        }
        else if (x >= 157 && x <= 757 && y >= 885 && y <= 1020)
        {
            DrawTexture(buttonHover[2], 0, 0, WHITE);
            color1 = BLACK;
            color2 = BLACK;
            color3 = WHITE;
            color4 = BLACK;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                choice = 2;
            }
        }
        else if (x >= 903 && x <= 1503 && y >= 885 && y <= 1020)
        {
            DrawTexture(buttonHover[3], 0, 0, WHITE);
            color1 = BLACK;
            color2 = BLACK;
            color3 = BLACK;
            color4 = WHITE;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                choice = 3;
            }
        }
        else
        {
            DrawTexture(background, 0, 0, WHITE);
            color1 = BLACK;
            color2 = BLACK;
            color3 = BLACK;
            color4 = BLACK;
        }

        if (!finish)
        {
            displayQuestion();
        }
        if (questionCounter == 15)
        {
            finish = 1;
        }

        EndDrawing();
    }


    CloseWindow();
    return 0;
>>>>>>> 87eb3c1 (feat(backend): add questions and answers)
}
=======
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
>>>>>>> bc0e718 (refactor(backend): optimize get rich minigame codebase)
