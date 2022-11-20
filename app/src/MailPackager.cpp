#include <raylib.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    InitWindow(1920, 1080, "Mail Packager");

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BROWN);
        EndDrawing();
     }

    CloseWindow();
    return 0;
}