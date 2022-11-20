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