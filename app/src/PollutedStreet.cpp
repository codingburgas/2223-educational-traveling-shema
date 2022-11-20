#include <raylib.h>

int main()
{
    InitWindow(1920, 1080, "Polluted Street");

    Texture2D city = LoadTexture("../assets/PollutedStreet/city.png");
    
    Texture2D rubbish = LoadTexture("../assets/PollutedStreet/rubbish.png");
    Texture2D rubbish2 = LoadTexture("../assets/PollutedStreet/rubbish2.png");
    Texture2D chips = LoadTexture("../assets/PollutedStreet/chips.png");
    Texture2D bin = LoadTexture("../assets/PollutedStreet/rubbish-bin.png");
    Texture2D food = LoadTexture("../assets/PollutedStreet/food.png");
    Texture2D food2 = LoadTexture("../assets/PollutedStreet/food2.png");
    Texture2D paper = LoadTexture("../assets/PollutedStreet/paper.png");    

    int xCoordinates[16] = { GetScreenWidth() / 2 - 150, GetScreenWidth() / 2 - 325, GetScreenWidth() / 2 - rubbish.width / 2 - 420,
                            350, 1700, 1200, 1300, 240, 904, 1830, 1449, 1390, 719, 90, 100, 40 };

    int yCoordinates[16] = { GetScreenHeight() / 2 + 375, 919, 950, 924, 944, 954, 990, GetScreenHeight() - bin.height + 30,
                            789, 724, 844, 779, 719, GetScreenHeight() / 2 + 270, GetScreenHeight() - bin.height - 20,
                            GetScreenHeight() / 2 + 190 };

    Texture2D bar[12] =
    {
        LoadTexture("../assets/PollutedStreet/bar1.png"), LoadTexture("../assets/PollutedStreet/bar2.png"), LoadTexture("../assets/PollutedStreet/bar3.png"),
        LoadTexture("../assets/PollutedStreet/bar4.png"), LoadTexture("../assets/PollutedStreet/bar5.png"), LoadTexture("../assets/PollutedStreet/bar6.png"),
        LoadTexture("../assets/PollutedStreet/bar7.png"), LoadTexture("../assets/PollutedStreet/bar8.png"), LoadTexture("../assets/PollutedStreet/bar9.png"),
        LoadTexture("../assets/PollutedStreet/bar10.png"), LoadTexture("../assets/PollutedStreet/bar11.png"), LoadTexture("../assets/PollutedStreet/bar12.png")
    };

    SetTargetFPS(60);

    int x = 0, y = 0;

    short rubbishType[2][1] = { 0, 0 }; // 0 = rubbish, 1 - rubbish2, 2 - chips, 3 - manqka, 4 - food, 5 - food2, 6 - paper 

    short remainingRubbish = 16;
    int counter = 0;
    int index = 0;
    int position = 0;
    int inPosition[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    bool hideBar = 1;
    int cleaned[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    bool ePressed = 0;
    bool flag = 0;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (remainingRubbish == 0)
        {
            DrawTexture(finishScreen, 0, 0, WHITE);
            DrawText("Congratulations!", GetScreenWidth() / 2 - 240, GetScreenHeight() / 2 - 250, 50, BLACK);
            DrawText("You have collected all the", GetScreenWidth() / 2 - 300, GetScreenHeight() / 2 - 100, 40, BLACK);
            DrawText("RUBBISH", GetScreenWidth() / 2 - 300, GetScreenHeight() / 2 - 50, 120, RED);
        }
        else
        {
            DrawTexture(city, 0, 0, WHITE);
        }

        for (int i = 0; i < 16; i++)
        {
            if (inPosition[i] == 1)
            {
                hideBar = 0;
            }
        }
        if (!hideBar)
        {
            DrawTexture(bar[position], 50, 50, WHITE);
        }

        if (!cleaned[0])
        {
            DrawTexture(rubbish2, xCoordinates[0], yCoordinates[0], GRAY);
        }
        if (!cleaned[1])
        {
            DrawTexture(paper, xCoordinates[1], yCoordinates[1], GRAY);
        }
        if (!cleaned[2])
        {
            DrawTexture(rubbish, xCoordinates[2], yCoordinates[2], GRAY);
        }
        if (!cleaned[3])
        {
            DrawTexture(food, xCoordinates[3], yCoordinates[3], GRAY);
        }
        if (!cleaned[4])
        {
            DrawTexture(rubbish, xCoordinates[4], yCoordinates[4], GRAY);
        }
        if (!cleaned[5])
        {
            DrawTexture(chips, xCoordinates[5], yCoordinates[5], GRAY);
        }
        if (!cleaned[6])
        {
            DrawTexture(food2, xCoordinates[6], yCoordinates[6], GRAY);
        }
        if (!cleaned[7])
        {
            DrawTexture(food2, xCoordinates[7], yCoordinates[7], GRAY);
        }
        if (!cleaned[8])
        {
            DrawTexture(paper, xCoordinates[8], yCoordinates[8], GRAY);
        }
        if (!cleaned[9])
        {
            DrawTexture(chips, xCoordinates[9], yCoordinates[9], GRAY);
        }
        if (!cleaned[10])
        {
            DrawTexture(bin, xCoordinates[10], yCoordinates[10], GRAY);
        }
        if (!cleaned[11])
        {
            DrawTexture(food, xCoordinates[11], yCoordinates[11], GRAY);
        }
        if (!cleaned[12])
        {
            DrawTexture(rubbish, xCoordinates[12], yCoordinates[12], GRAY);
        }
        if (!cleaned[13])
        {
            DrawTexture(chips, xCoordinates[13], yCoordinates[13], GRAY);
        }
        if (!cleaned[14])
        {
            DrawTexture(bin, xCoordinates[14], yCoordinates[14], GRAY);
        }
        if (!cleaned[15])
        {
            DrawTexture(food, xCoordinates[15], yCoordinates[15], GRAY);
        }

        x = GetMouseX();
        y = GetMouseY();

        for (int i = 0; i < 16; i++)
        {
            if (i == 2 || i == 4 || i == 12)
            {
                rubbishType[0][0] = rubbish.width;
                rubbishType[1][0] = rubbish.height;
            }
            if (i == 0)
            {
                rubbishType[0][0] = rubbish2.width;
                rubbishType[1][0] = rubbish2.height;
            }
            if (i == 1 || i == 8)
            {
                rubbishType[0][0] = paper.width;
                rubbishType[1][0] = paper.height;
            }
            if (i == 3 || i == 11 || i == 15)
            {
                rubbishType[0][0] = food.width;
                rubbishType[1][0] = food.height;
            }
            if (i == 5 || i == 9 || i == 13)
            {
                rubbishType[0][0] = chips.width;
                rubbishType[1][0] = chips.height;
            }
            if (i == 6 || i == 7)
            {
                rubbishType[0][0] = food2.width;
                rubbishType[1][0] = food2.height;
            }
            if (i == 10 || i == 14)
            {
                rubbishType[0][0] = bin.width;
                rubbishType[1][0] = bin.height;
            }

            if (x >= xCoordinates[i] && x <= xCoordinates[i] + rubbishType[0][0] && y >= yCoordinates[i] - 20 && y <= yCoordinates[i] + rubbishType[1][0] && !cleaned[i])
            {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                {
                    inPosition[i] = 1;
                }
            }

            if (IsKeyPressed(KEY_E) && inPosition[i])
            {
                ePressed = 1;
                inPosition[i] = 0;
                hideBar = 1;

                if (position >= 7 && position <= 12)
                {
                    cleaned[i] = 1;
                    remainingRubbish--;
                    position = 0;
                    ePressed = 0;
                }
                else
                {
                    position = 0;
                    ePressed = 0;
                }
            }
        }

        if (counter == 0)
        {
            position = 0;
        }
        if (counter == 80)
        {
            position = 1;
        }
        if (counter == 160)
        {
            position = 2;
        }
        if (counter == 240)
        {
            position = 3;
        }
        if (counter == 320)
        {
            position = 4;
        }
        if (counter == 400)
        {
            position = 5;
        }
        if (counter == 480)
        {
            position = 6;
        }
        if (counter == 560)
        {
            position = 7;
        }
        if (counter == 640)
        {
            position = 8;
        }
        if (counter == 720)
        {
            position = 9;
        }
        if (counter == 800)
        {
            position = 10;
        }
        if (counter == 880)
        {
            position = 11;
        }
        if (counter == 960)
        {
            counter = 0;
        }
        else if (!ePressed)
        {
            counter += 20;
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}