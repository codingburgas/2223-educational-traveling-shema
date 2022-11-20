#include <CaptchaSolver.hpp>

CaptchaSolver::CaptchaSolver()
{
	this->FinishScreen = LoadTexture((gameManager->getAssetPath() + "captcha-solver/finish-screen.png").c_str());
	std::random_shuffle(this->Words.begin(), this->Words.end());
}

CaptchaSolver::~CaptchaSolver()
{
	UnloadTexture(this->FinishScreen);
}

void CaptchaSolver::UpdateGame()
{
	while (this->NextWord < 10)
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawRectangle(GetScreenWidth() / 2 - 195, GetScreenHeight() / 2 - 10, 340, 100, LIGHTGRAY);
		DrawText(this->Words[this->NextWord].c_str(), GetScreenWidth() / 2 - 100, GetScreenHeight() / 2 - 300, 50, BLACK);

		this->ASCII = GetCharPressed();

		while (this->ASCII > 0)
		{
			// Only allow keys in range [32..125]
			if ((this->ASCII >= 32) && (this->ASCII <= 125) && (this->LetterCount < MaxLetters))
			{
				this->Text[this->LetterCount] = (char)this->ASCII;
				if (this->LetterCount != MaxLetters - 1)
				{
					this->Text[this->LetterCount + 1] = '_'; // Add _ to the next index of the array.
				}
				this->LetterCount++;
			}

			this->ASCII = GetCharPressed();  // Get ascii number of the next character
		}

		if (IsKeyPressed(KEY_BACKSPACE))
		{
			this->WrongCounter = 0;
			this->LetterCount--;
			if (this->LetterCount < 0)
			{
				this->LetterCount = 0;
			}
			this->Text[this->LetterCount] = '_';
			this->Text[this->LetterCount + 1] = NULL;
		}

		for (int i = 0; i < this->LetterCount; i++)
		{
			if (this->Text[i] != this->Words[this->NextWord][i] && this->Text[i] != '_')
			{
				this->Wrong = 1;
			}
		}

		if (this->Wrong)
		{
			if (this->Score != 0 && this->WrongCounter == 0)
			{
				this->WrongCounter = 1;
				this->Score--;
			}
			DrawText(this->Text, GetScreenWidth() / 2 - 150, GetScreenHeight() / 2, 80, RED);
		}
		else if (!this->Wrong && this->LetterCount == 5)
		{
			DrawText(this->Text, GetScreenWidth() / 2 - 150, GetScreenHeight() / 2, 80, GREEN);
			if (this->Delay > 0.8)
			{
				this->Delay = -1;
				this->NextWord++;
				this->Text[0] = '_';
				for (int i = 1; i < 5; i++)
				{
					this->Text[i] = NULL;
				}
				this->LetterCount = 0;
				this->Score++;
			}
			this->Delay+=GetFrameTime();
		}
		else
		{
			DrawText(this->Text, GetScreenWidth() / 2 - 150, GetScreenHeight() / 2, 80, BLACK);
		}

		this->Wrong = 0;

		DrawText("Income:", 20, 20, 40, BLACK);
		DrawText((std::to_string(this->Money[this->Score]) + "$").c_str(), 180, 22, 40, GREEN);

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

int CaptchaSolver::getPayout()
{
	return this->Money[this->Score];
}

