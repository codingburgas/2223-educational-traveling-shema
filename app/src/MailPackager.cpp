#include <raylib.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    InitWindow(1920, 1080, "Mail Packager");

    Texture2D packages[4] = { LoadTexture("../assets/mail-packager/package-front.png"), LoadTexture("../assets/mail-packager/package-front-with-stamp.png"),LoadTexture("../assets/mail-packager/package-back.png"), LoadTexture("../assets/mail-packager/package-back-with-stamp.png") };
    Texture2D letters[4] = { LoadTexture("../assets/mail-packager/letter-front.png"), LoadTexture("../assets/mail-packager/letter-front-with-stamp.png"),LoadTexture("../assets/mail-packager/letter-back.png"), LoadTexture("../assets/mail-packager/letter-back-with-stamp.png") };
    Texture2D background = LoadTexture("../assets/mail-packager/background.png");
    Texture2D finishScreen = LoadTexture("../assets/mail-packager/finish-screen.png");

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