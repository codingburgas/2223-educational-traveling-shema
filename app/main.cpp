<<<<<<< HEAD
#include <GameManager.hpp>
#include <Menu.hpp>
#include <Game.hpp>

int main()
{
    GameManager *gameManager = GameManager::GetInstance(); 
    Menu* mainMenu = new Menu();
    //while (!gameManager->getShouldClose())
    //{
    //    gameManager->Update();
    //}
    return 0;
=======
#include <raylib.h>
#include <time.h>
#include <stdlib.h>

int main()
{
<<<<<<< HEAD

>>>>>>> 3b6da91 (feat(backend): add necessary libraries for the sea game)
=======
	InitWindow(1920, 1080, "Mini Game Waves");

    Texture2D waves = LoadTexture("assets/waves.png");

    Image bagImage = LoadImage("assets/bag.png");
    Image* bagImagePtr = &bagImage;
    ImageResize(bagImagePtr, 80, 80);
    Texture2D bag = LoadTextureFromImage(*bagImagePtr);

    Image canImage = LoadImage("assets/can.png");
    Image* canImagePtr = &canImage;
    ImageResize(canImagePtr, 80, 50);
    Texture2D can = LoadTextureFromImage(*canImagePtr);

    Image bottleImage = LoadImage("assets/bottle.png");
    Image* bottleImagePtr = &bottleImage;
    ImageResize(bottleImagePtr, 70, 80);
    Texture2D bottle = LoadTextureFromImage(*bottleImagePtr);


    Image ropeImage = LoadImage("assets/rope.png");
    Image* ropeImagePtr = &ropeImage;
    ImageResize(ropeImagePtr, 100, 1000);
    Texture2D rope = LoadTextureFromImage(*ropeImagePtr);

    Image hookImage = LoadImage("assets/hook.png");
    Image* hookImagePtr = &hookImage;
    ImageResize(hookImagePtr, 70, 70);
    Texture2D hook = LoadTextureFromImage(*hookImagePtr);
	
    int mouseX, mouseY;

    bool checkIfObjectIsClicked[20] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    bool cleaned[20] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    bool carrying = 0;

    int rubbishX[20] = { 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    int rubbishY[20] = { 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

    short rubbishType[20] = { 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, remainingRubbish = 20;

    srand(time(NULL));

    for (int i = 0; i < 20; i++)
    {
        rubbishType[i] = rand() % 3 + 1;
    }

    for (int i = 0; i < 20; i++)
    {
        rubbishX[i] = rand() % 1820 + 1;
        rubbishY[i] = rand() % 450 + 450;
        for (int j = 0; j < i; j++)
        {
            while (abs(rubbishX[i] - rubbishX[j]) < 100)
            {
                rubbishX[i] = rand() % 1820 + 1;
            }
            while (abs(rubbishY[i] - rubbishY[j]) < 100)
            {
                rubbishY[i] = rand() % 450 + 450;
            }
        }
    }

	while (!WindowShouldClose())
<<<<<<< HEAD
    	{
        		BeginDrawing();
        		HideCursor();
        		ClearBackground(RAYWHITE);
        	
	}
>>>>>>> be9e7d5 (feat(backend): create game window)
=======
    {
        BeginDrawing();
        HideCursor();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }


    CloseWindow();
    return 0;
>>>>>>> 6f0b1eb (feat(backend): add sea game assets)
}