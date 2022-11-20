#include <raylib.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    InitWindow(1920, 1080, "Mail Packager");

    Texture2D packages[4] = { LoadTexture("package-front.png"), LoadTexture("package-front-with-stamp.png"),LoadTexture("package-back.png"), LoadTexture("package-back-with-stamp.png") };
    Texture2D letters[4] = { LoadTexture("letter-front.png"), LoadTexture("letter-front-with-stamp.png"),LoadTexture("letter-back.png"), LoadTexture("letter-back-with-stamp.png") };
    Texture2D background = LoadTexture("background.png");


    SetTargetFPS(60);

    int x = 0, y = 0;

    bool mailType = 0; // 1 - packages; 0 - letters
    bool nextMail = 1;
    bool side = 1;
    int back = 0;
    int front = 0;
    bool idle = 1;
    int letterX = 0, letterY = 0;
    short score = 0;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BROWN);

        DrawTexture(background, 0, 0, WHITE);
        DrawText(money[score], GetScreenWidth() / 2 - 50, 50, 50, GREEN);

        x = GetMouseX();
        y = GetMouseY();

        if (nextMail)
        {
            srand(time(NULL));
            mailType = rand() % 2; // random number from 0 to 1
            front = rand() % 2;
            back = rand() % 2 + 2; // random number from 2 to 3
            nextMail = 0;
            mailsLeft--;
        }

        if (idle)
        {
            letterX = GetScreenWidth() / 2 - 80;
            letterY = 300;
        }
        else
        {
            letterX = x - 65;
            letterY = y - 30;
        }

        if (mailType && mailsLeft != 0)
        {
            if (side)
            {
                DrawTexture(packages[front], letterX, letterY, WHITE);
            }
            else
            {
                DrawTexture(packages[back], letterX, letterY, WHITE);
            }
        }
        else if (mailsLeft != 0)
        {
            if (side)
            {
                DrawTexture(letters[front], letterX, letterY, WHITE);
            }
            else
            {
                DrawTexture(letters[back], letterX, letterY, WHITE);
            }
        }

        if (IsKeyPressed(KEY_F))
        {
            side = !side;
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && x >= GetScreenWidth() / 2 - 80 && x <= GetScreenWidth() / 2 + 50 && y >= 300 && y <= 400)
        {
            idle = 0;
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !idle && x >= GetScreenWidth() / 2 - 550 && x <= GetScreenWidth() / 2 - 400 && y >= 150 && y <= 300 && mailsLeft != 0)
        {
            if (mailType == 0)
            {
                score++;
            }
            else
            {
                if (score != 0)
                {
                    score--;
                }
            }
            nextMail = 1;
            idle = 1;
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !idle && x >= GetScreenWidth() / 2 + 340 && x <= GetScreenWidth() / 2 + 500 && y >= 150 && y <= 300 && mailsLeft != 0)
        {
            if (mailType == 1)
            {
                score++;
            }
            else
            {
                if (score != 0)
                {
                    score--;
                }
            }
            nextMail = 1;
            idle = 1;
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !idle && x >= GetScreenWidth() / 2 - 50 && x <= GetScreenWidth() / 2 + 150 && y >= 670 && y <= 850 && mailsLeft != 0)
        {
            if (front == 0 && back == 2)
            {
                score++;
            }
            else
            {
                if (score != 0)
                {
                    score--;
                }
            }
            nextMail = 1;
            idle = 1;
        }

        EndDrawing();
    }


    CloseWindow();
    return 0;
}