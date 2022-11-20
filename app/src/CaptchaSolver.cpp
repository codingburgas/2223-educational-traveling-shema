#include <CaptchaSolver.hpp>

CaptchaSolver::CaptchaSolver()
{
	this->FinishScreen = LoadTexture((gameManager->getAssetPath() + "captcha-solver/finish-screen.png").c_str());
	std::random_shuffle(Words.begin(), Words.end());
}

CaptchaSolver::~CaptchaSolver()
{
	UnloadTexture(this->FinishScreen);
}

void CaptchaSolver::UpdateGame()
{
	while (nextWord < 10)
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawRectangle(GetScreenWidth() / 2 - 195, GetScreenHeight() / 2 - 10, 340, 100, LIGHTGRAY);
		DrawText(Words[nextWord].c_str(), GetScreenWidth() / 2 - 100, GetScreenHeight() / 2 - 300, 50, BLACK);

		ascii = GetCharPressed();

		while (ascii > 0)
		{
			// Only allow keys in range [32..125]
			if ((ascii >= 32) && (ascii <= 125) && (letterCount < maxLetters))
			{
				text[letterCount] = (char)ascii;
				if (letterCount != maxLetters - 1)
				{
					text[letterCount + 1] = '_'; // Add _ to the next index of the array.
				}
				letterCount++;
			}

			ascii = GetCharPressed();  // Get ascii number of the next character
		}

		if (IsKeyPressed(KEY_BACKSPACE))
		{
			wrongCounter = 0;
			letterCount--;
			if (letterCount < 0)
			{
				letterCount = 0;
			}
			text[letterCount] = '_';
			text[letterCount + 1] = NULL;
		}

		for (int i = 0; i < letterCount; i++)
		{
			if (text[i] != Words[nextWord][i] && text[i] != '_')
			{
				wrong = 1;
			}
		}

		if (wrong)
		{
			if (score != 0 && wrongCounter == 0)
			{
				wrongCounter = 1;
				score--;
			}
			DrawText(text, GetScreenWidth() / 2 - 150, GetScreenHeight() / 2, 80, RED);
		}
		else if (!wrong && letterCount == 5)
		{
			DrawText(text, GetScreenWidth() / 2 - 150, GetScreenHeight() / 2, 80, GREEN);
			if (wait == 40)
			{
				wait = -1;
				nextWord++;
				text[0] = '_';
				for (int i = 1; i < 5; i++)
				{
					text[i] = NULL;
				}
				letterCount = 0;
				score++;
			}
			wait++;
		}
		else
		{
			DrawText(text, GetScreenWidth() / 2 - 150, GetScreenHeight() / 2, 80, BLACK);
		}

		wrong = 0;

		DrawText("Income:", 20, 20, 40, BLACK);
		DrawText(money[score], 180, 22, 40, GREEN);

		EndDrawing();
	}

	gameManager->StartTimer(3);
	while(!gameManager->TimerEnded())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawTexture(this->FinishScreen, 0, 0, WHITE);
		DrawText("Congratulations!", GetScreenWidth() / 2 - 320, GetScreenHeight() / 2 - 300, 80, BLACK);
		DrawText("You have filled successfuly all the", GetScreenWidth() / 2 - 350, GetScreenHeight() / 2 - 125, 40, BLACK);
		DrawText("CAPTCHAS", GetScreenWidth() / 2 - 415, GetScreenHeight() / 2 - 50, 150, GRAY);
		DrawText("CAPTCHAS", GetScreenWidth() / 2 - 420, GetScreenHeight() / 2 - 50, 150, YELLOW);
		EndDrawing();
	}
}

