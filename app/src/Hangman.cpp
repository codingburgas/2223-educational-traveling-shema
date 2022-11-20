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
		BeginDrawing();
		ClearBackground(BEIGE);

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

		DrawTexture(rope, 100, 200, BEIGE);

		for (int i = 0; i < 6; i++)
		{
			if (bodyPartsPrint[i])
			{
				if (i == 0)
				{
					x = 425;
					y = 335;
				}
				if (i == 1)
				{
					x = 485;
					y = 445;
				}
				if (i == 2)
				{
					x = 412;
					y = 440;
				}
				if (i == 3)
				{
					x = 475;
					y = 432;
				}
				if (i == 4)
				{
					x = 385;
					y = 628;
				}
				if (i == 5)
				{
					x = 486;
					y = 639;
				}

				DrawTexture(bodyParts[i], x, y, WHITE);
			}
		}
		DrawText(wordConvertor.c_str(), GetScreenWidth() / 2 + 150, GetScreenHeight() / 2 - 50, 50, BLACK);
		DrawText("Guesses:", GetScreenWidth() / 2 + 30, GetScreenHeight() / 2 + 150, 40, BLACK);

		for (int i = 0; i < 26; i++)
		{
			if (alphabet[i] == 1 && letterCounter[i] == 0)
			{
				letterCounter[i] = 1;
				letter += ' ';
				letter += char(i + 97);
			}
		}

		DrawText(letter.c_str(), GetScreenWidth() / 2 + 240, GetScreenHeight() / 2 + 150, 40, BLACK);

		if (flagEnd)
		{
			DrawTexture(finishScreen, 0, 0, WHITE);
			DrawText("Congratulations!", GetScreenWidth() / 2 - 170, GetScreenHeight() / 2 - 150, 45, BLACK);
			DrawText("You've won 200 $!", GetScreenWidth() / 2 - 245, GetScreenHeight() / 2, 60, BLACK);
		}

		if (counterBodyParts == 6)
		{
			DrawTexture(finishScreen, 0, 0, WHITE);
			DrawText("Failed!", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2 - 150, 60, BLACK);
			DrawText("You've lost!", GetScreenWidth() / 2 - 205, GetScreenHeight() / 2, 70, BLACK);
		}

		EndDrawing();
	}

	CloseWindow();
	return 0;
}