#include <raylib.h>
#include <algorithm>
#include <vector>

int main()
{
    InitWindow(1920, 1080, "Captcha Solver");

    SetTargetFPS(60);

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
    bool wrong = 0;
    short wait = 0;
    bool wrongCounter = 0;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawRectangle(GetScreenWidth() / 2 - 195, GetScreenHeight() / 2 - 10, 340, 100, LIGHTGRAY);
        DrawText(givenWords[0], GetScreenWidth() / 2 - 100, GetScreenHeight() / 2 - 300, 50, BLACK);

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
            DrawText(text, GetScreenWidth() / 2 - 150, GetScreenHeight() / 2, 80, RED);
        }
        else if (!wrong && letterCount == 5)
        {
            DrawText(text, GetScreenWidth() / 2 - 150, GetScreenHeight() / 2, 80, GREEN);
            if (wait == 40)
            {
                wait = -1;
                text[0] = '_';
                for (int i = 1; i < 5; i++)
                {
                    text[i] = NULL;
                }
                letterCount = 0;
            }
            wait++;



        }
        else
        {
            DrawText(text, GetScreenWidth() / 2 - 150, GetScreenHeight() / 2, 80, BLACK);
        }
        wrong = 0;

        EndDrawing();
    }


    CloseWindow();
    return 0;
}