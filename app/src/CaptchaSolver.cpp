#include <raylib.h>
#include <algorithm>
#include <vector>

int main()
{
    InitWindow(1920, 1080, "Captcha Solver");

    SetTargetFPS(60);

    Texture2D finishScreen = LoadTexture("../assets/finish-screen.png");

    char text[6] = { '_' };
    int letterCount = 0;
    int ascii = 0;

    std::vector<char*> givenWords;

    givenWords.push_back("HELLo");
    givenWords.push_back("wORLD");
    givenWords.push_back("VSCPI");
    givenWords.push_back("BINGO");
    givenWords.push_back("words");
    givenWords.push_back("mails");
    givenWords.push_back("SharP");
    givenWords.push_back("seize");
    givenWords.push_back("LOREM");
    givenWords.push_back("IPSUM");

    std::random_shuffle(givenWords.begin(), givenWords.end());

    short maxLetters = 5;
    short nextWord = 0;
    bool wrong = 0;
    short wait = 0;
    int score = 0;
    bool wrongCounter = 0;
    
    const char* money[11] = { "0$", "40$", "80$", "120$", "160$", "200$", "240$", "280$", "320$", "360$", "400$" };

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (nextWord == 10)
        {
            DrawTexture(finishScreen, 0, 0, WHITE);
            DrawText("Congratulations!", GetScreenWidth() / 2 - 320, GetScreenHeight() / 2 - 300, 80, BLACK);
            DrawText("You have filled successfuly all the", GetScreenWidth() / 2 - 350, GetScreenHeight() / 2 - 125, 40, BLACK);
            DrawText("CAPTCHAS", GetScreenWidth() / 2 - 415, GetScreenHeight() / 2 - 50, 150, GRAY);
            DrawText("CAPTCHAS", GetScreenWidth() / 2 - 420, GetScreenHeight() / 2 - 50, 150, YELLOW);
        }
        else
        {
            DrawRectangle(GetScreenWidth() / 2 - 195, GetScreenHeight() / 2 - 10, 340, 100, LIGHTGRAY);
            DrawText(givenWords[nextWord], GetScreenWidth() / 2 - 100, GetScreenHeight() / 2 - 300, 50, BLACK);

            ascii = GetCharPressed();

            while (ascii > 0)
            {
                // Only allow keys in range [32..125]
                if ((ascii >= 32) && (ascii <= 125) && (letterCount < maxLetters))
                {
                    text[letterCount] = (char)ascii;
                    if (letterCount != maxLetters - 1)
                    {
                        text[letterCount + 1] = '_'; // Add _ to the next index of the array.
                    }
                    letterCount++;
                }

                ascii = GetCharPressed();  // Get ascii number of the next character
            }

            if (IsKeyPressed(KEY_BACKSPACE))
            {
                wrongCounter = 0;
                letterCount--;
                if (letterCount < 0)
                {
                    letterCount = 0;
                }
                text[letterCount] = '_';
                text[letterCount + 1] = NULL;
            }

            for (int i = 0; i < letterCount; i++)
            {
                if (text[i] != givenWords[nextWord][i] && text[i] != '_')
                {
                    wrong = 1;
                }
            }

            if (wrong)
            {
                if (score != 0 && wrongCounter == 0)
                {
                    wrongCounter = 1;
                    score--;
                }
                DrawText(text, GetScreenWidth() / 2 - 150, GetScreenHeight() / 2, 80, RED);
            }
            else if (!wrong && letterCount == 5)
            {
                DrawText(text, GetScreenWidth() / 2 - 150, GetScreenHeight() / 2, 80, GREEN);
                if (wait == 40)
                {
                    wait = -1;
                    nextWord++;
                    text[0] = '_';
                    for (int i = 1; i < 5; i++)
                    {
                        text[i] = NULL;
                    }
                    letterCount = 0;
                    score++;
                }
                wait++;



            }
            else
            {
                DrawText(text, GetScreenWidth() / 2 - 150, GetScreenHeight() / 2, 80, BLACK);
            }
            wrong = 0;
        }

        DrawText("Income:", 20, 20, 40, BLACK);
        DrawText(money[score], 180, 22, 40, GREEN);

        EndDrawing();
    }


    CloseWindow();
    return 0;
}