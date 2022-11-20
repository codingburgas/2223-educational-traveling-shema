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
	std::string copyWord = words[num];

	for (int i = 0; i < length; i++)
	{
		wordConvertor += '_';
	}

	while (!WindowShouldClose())
	{
		key = GetCharPressed();

		while (key >= 97 && key <= 122 && alphabet[key - 97] == 0)
		{
			for (int i = 0; i < length; i++)
			{
				alphabet[key - 97] = 1;

				if (key == copyWord[i])
				{
					wordConvertor[i] = copyWord[i];
					counter++;
					correctLetters++;
				}
			}

			if (correctLetters == 0)
			{
				bodyPartsPrint[counterBodyParts] = 1;
				counterBodyParts++;
			}

			key = GetCharPressed();
			correctLetters = 0;
		}

		if (counter == length)
		{
			flagEnd = true;
		}

		BeginDrawing();
		ClearBackground(BEIGE);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}