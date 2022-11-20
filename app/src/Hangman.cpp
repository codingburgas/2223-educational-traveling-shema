#include <Hangman.hpp>

Hangman::Hangman()
{
	Rope = LoadTexture((gameManager->getAssetPath() + "Hangman/rope.png").c_str());
	FinishScreen = LoadTexture((gameManager->getAssetPath() + "Hangman/finishScreen.png").c_str());
	BodyParts[0] = LoadTexture((gameManager->getAssetPath() + "Hangman/head.png").c_str());
	BodyParts[1] = LoadTexture((gameManager->getAssetPath() + "Hangman/body.png").c_str());
	BodyParts[2] = LoadTexture((gameManager->getAssetPath() + "Hangman/lHand.png").c_str());
	BodyParts[3] = LoadTexture((gameManager->getAssetPath() + "Hangman/rHand.png").c_str());
	BodyParts[4] = LoadTexture((gameManager->getAssetPath() + "Hangman/rHand.png").c_str());
	BodyParts[5] = LoadTexture((gameManager->getAssetPath() + "Hangman/lHand.png").c_str());
	
	for (int i = 0; i < Length; i++)
	{
		WordConvertor += '_';
	}
}

Hangman::~Hangman()
{
	UnloadTexture(Rope);
	UnloadTexture(FinishScreen);
	for (int i = 0; i < 6; i++)
	{
		UnloadTexture(BodyParts[i]);
	}
}

void Hangman::UpdateGame()
{
	while (!FlagEnd && CounterBodyParts < 6)
	{
		BeginDrawing();
		ClearBackground(BEIGE);

		Key = GetCharPressed();

		while (Key >= 97 && Key <= 122 && Alphabet[Key - 97] == 0)
		{
			for (int i = 0; i < Length; i++)
			{
				Alphabet[Key - 97] = 1;

				if (Key == CopyWord[i])
				{
					WordConvertor[i] = CopyWord[i];
					Counter++;
					CorrectLetters++;
				}
			}

			if (CorrectLetters == 0)
			{
				BodyPartsPrint[CounterBodyParts] = 1;
				CounterBodyParts++;
			}

			Key = GetCharPressed();
			CorrectLetters = 0;
		}

		if (Counter == Length)
		{
			FlagEnd = true;
		}

		DrawTexture(Rope, 100, 200, BEIGE);

		for (int i = 0; i < 6; i++)
		{
			if (BodyPartsPrint[i])
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

				DrawTexture(BodyParts[i], x, y, WHITE);
			}
		}
		DrawText(WordConvertor.c_str(), GetScreenWidth() / 2 + 150, GetScreenHeight() / 2 - 50, 50, BLACK);
		DrawText("Guesses:", GetScreenWidth() / 2 + 30, GetScreenHeight() / 2 + 150, 40, BLACK);

		for (int i = 0; i < 26; i++)
		{
			if (Alphabet[i] == 1 && LetterCounter[i] == 0)
			{
				LetterCounter[i] = 1;
				Letter += ' ';
				Letter += char(i + 97);
			}
		}

		DrawText(Letter.c_str(), GetScreenWidth() / 2 + 240, GetScreenHeight() / 2 + 150, 40, BLACK);

		EndDrawing();
	}

	gameManager->StartTimer(3);
	while (!gameManager->TimerEnded())
	{
		if (FlagEnd)
		{
			BeginDrawing();
			ClearBackground(BEIGE);
			DrawTexture(FinishScreen, 0, 0, WHITE);
			DrawText("Congratulations!", GetScreenWidth() / 2 - 170, GetScreenHeight() / 2 - 150, 45, BLACK);
			DrawText("You've won 200 $!", GetScreenWidth() / 2 - 245, GetScreenHeight() / 2, 60, BLACK);
			EndDrawing();
		}

		if (CounterBodyParts == 6)
		{
			BeginDrawing();
			ClearBackground(BEIGE);
			DrawTexture(FinishScreen, 0, 0, WHITE);
			DrawText("Failed!", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2 - 150, 60, BLACK);
			DrawText("You've lost!", GetScreenWidth() / 2 - 205, GetScreenHeight() / 2, 70, BLACK);
			EndDrawing();
		}
	}
}