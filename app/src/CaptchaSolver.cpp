#include <CaptchaSolver.hpp>

CaptchaSolver::CaptchaSolver()
{
	this->m_FinishScreen = LoadTexture((gameManager->GetAssetPath() + "captcha-solver/finish-screen.png").c_str());
	this->m_Background = LoadTexture((gameManager->GetAssetPath() + "captcha-solver/background.png").c_str());
	std::random_shuffle(this->m_Words.begin(), this->m_Words.end());
}

CaptchaSolver::~CaptchaSolver()
{
	// Unloads the textures
	UnloadTexture(this->m_Background);
	UnloadTexture(this->m_FinishScreen);
}

void CaptchaSolver::UpdateGame()
{
	while (this->m_NextWord < 10)
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawTexture(this->m_Background, 0, 0, WHITE);
		DrawRectangle(GetScreenWidth() / 2 - 195, GetScreenHeight() / 2 - 10, 340, 100, LIGHTGRAY);
		DrawText(this->m_Words[this->m_NextWord].c_str(), GetScreenWidth() / 2 - 100, GetScreenHeight() / 2 - 300, 50, WHITE);

		this->m_ASCII = GetCharPressed();

		while (this->m_ASCII > 0)
		{
			// Only allow keys in range [32..125]
			if ((this->m_ASCII >= 32) && (this->m_ASCII <= 125) && (this->m_LetterCount < m_MaxLetters))
			{
				this->m_Text[this->m_LetterCount] = (char)this->m_ASCII;
				if (this->m_LetterCount != m_MaxLetters - 1)
				{
					this->m_Text[this->m_LetterCount + 1] = '_'; // Add _ to the next index of the array.
				}
				this->m_LetterCount++;
			}

			this->m_ASCII = GetCharPressed();  // Get ascii number of the next character
		}

		if (IsKeyPressed(KEY_BACKSPACE))
		{
			this->m_WrongCounter = 0;
			this->m_LetterCount--;
			if (this->m_LetterCount < 0)
			{
				this->m_LetterCount = 0;
			}
			this->m_Text[this->m_LetterCount] = '_';
			this->m_Text[this->m_LetterCount + 1] = NULL;
		}

		for (int i = 0; i < this->m_LetterCount; i++)
		{
			if (this->m_Text[i] != this->m_Words[this->m_NextWord][i] && this->m_Text[i] != '_')
			{
				this->m_Wrong = 1;
			}
		}

		if (this->m_Wrong)
		{
			if (this->m_Score != 0 && this->m_WrongCounter == 0)
			{
				this->m_WrongCounter = 1;
				this->m_Score--;
			}
			DrawText(this->m_Text, GetScreenWidth() / 2 - 150, GetScreenHeight() / 2, 80, RED);
		}
		else if (!this->m_Wrong && this->m_LetterCount == 5)
		{
			DrawText(this->m_Text, GetScreenWidth() / 2 - 150, GetScreenHeight() / 2, 80, GREEN);
			if (this->m_Delay > 0.8)
			{
				this->m_Delay = -1;
				this->m_NextWord++;
				this->m_Text[0] = '_';
				for (int i = 1; i < 5; i++)
				{
					this->m_Text[i] = NULL;
				}
				this->m_LetterCount = 0;
				this->m_Score++;
			}
			this->m_Delay += GetFrameTime();
		}
		else
		{
			DrawText(this->m_Text, GetScreenWidth() / 2 - 150, GetScreenHeight() / 2, 80, BLACK);
		}

		this->m_Wrong = 0;

		DrawText("Income:", 20, 20, 40, BLACK);
		DrawText((std::to_string(this->c_Money[this->m_Score]) + "$").c_str(), 180, 22, 40, GREEN);

		EndDrawing();
	}

	gameManager->StartTimer(3);
	while (!gameManager->TimerEnded())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawTexture(this->m_FinishScreen, 0, 0, WHITE);
		DrawText("Congratulations!", GetScreenWidth() / 2 - 320, GetScreenHeight() / 2 - 300, 80, BLACK);
		DrawText("You have filled successfuly all the", GetScreenWidth() / 2 - 350, GetScreenHeight() / 2 - 125, 40, BLACK);
		DrawText("CAPTCHAS", GetScreenWidth() / 2 - 415, GetScreenHeight() / 2 - 50, 150, GRAY);
		DrawText("CAPTCHAS", GetScreenWidth() / 2 - 420, GetScreenHeight() / 2 - 50, 150, YELLOW);
		EndDrawing();
	}
}

int CaptchaSolver::GetPayout()
{
	return this->c_Money[this->m_Score];
}

