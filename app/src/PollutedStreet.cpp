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

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}