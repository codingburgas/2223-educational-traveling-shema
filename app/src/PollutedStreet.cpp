#include <raylib.h>

int main()
{
    InitWindow(1920, 1080, "Polluted Street");
    
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