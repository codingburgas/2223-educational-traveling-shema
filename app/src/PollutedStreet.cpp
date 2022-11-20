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

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
		
		DrawTexture(bar[position], 50, 50, WHITE);
		
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