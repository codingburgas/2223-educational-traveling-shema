#include <raylib.h>
#include <time.h>
#include <stdlib.h>
#include <string>

int main()
{
	InitWindow(1920, 1080, "Hang");
	FLAG_FULLSCREEN_MODE;

	Texture2D rope = LoadTexture("rope.png");
	Texture2D finishScreen = LoadTexture("finishScreen.png");
	Texture2D bodyParts[6] = { (LoadTexture("head.png")), (LoadTexture("body.png")), (LoadTexture("lHand.png")), (LoadTexture("rHand.png")), (LoadTexture("rHand.png")), (LoadTexture("lHand.png")) };

	std::string words[20] = { "dance," "dilligent", "fall", "steel", "beggar", "cleave", "page", "lush", "unruly", "trolley",
							 "ball", "achieve", "detect", "wander", "behave", "ingest", "cart", "yield", "fast", "garden" };

	bool alphabet[26] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	bool bodyPartsPrint[6] = { 0, 0, 0, 0, 0, 0 };

	srand(time(NULL()));
	int num = rand() % 20;

	int x = 0, y = 0;

	int counter = 0;
	int counterBodyParts = 0;
	int correctLetters = 0;
	int index = 0;
	int key = 0;
	int length = words[num].size();
	bool letterCounter[26] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	bool flagEnd = false;

	std::string wordConvertor = "";
	std::string letter = "";
	std::string copyWord = words[num]

	while (!WindowShouldClose())
	{


		BeginDrawing();
		ClearBackground(BEIGE);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}