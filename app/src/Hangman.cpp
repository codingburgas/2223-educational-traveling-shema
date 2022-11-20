#include <Hangman.hpp>

Hangman::Hangman()
{
	// Loads all the textures
	this->m_Rope = LoadTexture((gameManager->GetAssetPath() + "Hangman/rope.png").c_str());
	this->m_Background = LoadTexture((gameManager->GetAssetPath() + "Hangman/Background.png").c_str());
	this->m_FinishScreen = LoadTexture((gameManager->GetAssetPath() + "Hangman/finishScreen.png").c_str());
	this->m_BodyParts[0] = LoadTexture((gameManager->GetAssetPath() + "Hangman/head.png").c_str());
	this->m_BodyParts[1] = LoadTexture((gameManager->GetAssetPath() + "Hangman/body.png").c_str());
	this->m_BodyParts[2] = LoadTexture((gameManager->GetAssetPath() + "Hangman/lHand.png").c_str());
	this->m_BodyParts[3] = LoadTexture((gameManager->GetAssetPath() + "Hangman/rHand.png").c_str());
	this->m_BodyParts[4] = LoadTexture((gameManager->GetAssetPath() + "Hangman/rHand.png").c_str());
	this->m_BodyParts[5] = LoadTexture((gameManager->GetAssetPath() + "Hangman/lHand.png").c_str());
	
	for (int i = 0; i < this->m_Length; i++)
	{
		this->m_WordConvertor += '_';
	}
}

Hangman::~Hangman()
{
	// Unloads all the textures
	UnloadTexture(this->m_Rope);
	UnloadTexture(this->m_FinishScreen);
	UnloadTexture(this->m_Background);
	for (int i = 0; i < 6; i++)
	{
		UnloadTexture(this->m_BodyParts[i]);
	}
}

void Hangman::UpdateGame()
{
	// Displays the background
	while (!this->m_FlagEnd && this->m_CounterBodyParts < 6)
	{
		BeginDrawing();
		ClearBackground(BEIGE);
		DrawTexture(this->m_Background, 0, 0, WHITE);

		this->m_Key = GetCharPressed();

		while (this->m_Key >= 97 && this->m_Key <= 122 && this->m_Alphabet[m_Key - 97] == 0)
		{
			for (int i = 0; i < this->m_Length; i++)
			{
				this->m_Alphabet[this->m_Key - 97] = 1;

				if (this->m_Key == this->m_CopyWord[i])
				{
					this->m_WordConvertor[i] = this->m_CopyWord[i];
					this->m_Counter++;
					this->m_CorrectLetters++;
				}
			}

			if (this->m_CorrectLetters == 0)
			{
				this->m_BodyPartsPrint[this->m_CounterBodyParts] = 1;
				this->m_CounterBodyParts++;
			}

			this->m_Key = GetCharPressed();
			this->m_CorrectLetters = 0;
		}

		if (this->m_Counter == this->m_Length)
		{
			this->m_FlagEnd = true;
		}

		DrawTexture(this->m_Rope, 100, 200, BEIGE);

		for (int i = 0; i < 6; i++)
		{
			if (this->m_BodyPartsPrint[i])
			{
				if (i == 0)
				{
					this->x = 425;
					this->y = 335;
				}
				if (i == 1)
				{
					this->x = 485;
					this->y = 445;
				}
				if (i == 2)
				{
					this->x = 412;
					this->y = 440;
				}
				if (i == 3)
				{
					this->x = 475;
					this->y = 432;
				}
				if (i == 4)
				{
					this->x = 385;
					this->y = 628;
				}
				if (i == 5)
				{
					this->x = 486;
					this->y = 639;
				}

				DrawTexture(this->m_BodyParts[i], this->x, this->y, WHITE);
			}
		}
		DrawText(this->m_WordConvertor.c_str(), GetScreenWidth() / 2 + 150, GetScreenHeight() / 2 - 50, 50, BLACK);
		DrawText("Guesses:", GetScreenWidth() / 2 + 30, GetScreenHeight() / 2 + 150, 40, BLACK);

		for (int i = 0; i < 26; i++)
		{
			if (this->m_Alphabet[i] == 1 && this->m_LetterCounter[i] == 0)
			{
				this->m_LetterCounter[i] = 1;
				this->m_Letter += ' ';
				this->m_Letter += char(i + 97);
			}
		}

		DrawText(this->m_Letter.c_str(), GetScreenWidth() / 2 + 240, GetScreenHeight() / 2 + 150, 40, BLACK);

		EndDrawing();
	}

	gameManager->StartTimer(3);
	while (!gameManager->TimerEnded())
	{
		if (this->m_FlagEnd)
		{
			BeginDrawing();
			ClearBackground(BEIGE);
			DrawTexture(m_FinishScreen, 0, 0, WHITE);
			DrawText("Congratulations!", GetScreenWidth() / 2 - 170, GetScreenHeight() / 2 - 150, 45, BLACK);
			DrawText("You've won 200 $!", GetScreenWidth() / 2 - 245, GetScreenHeight() / 2, 60, BLACK);
			EndDrawing();
			this->m_Payout = 200;
		}

		if (this->m_CounterBodyParts == 6)
		{
			BeginDrawing();
			ClearBackground(BEIGE);
			DrawTexture(m_FinishScreen, 0, 0, WHITE);
			DrawText("Failed!", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2 - 150, 60, BLACK);
			DrawText("You've lost!", GetScreenWidth() / 2 - 205, GetScreenHeight() / 2, 70, BLACK);
			EndDrawing();
		}
	}
}

int Hangman::GetPayout()
{
	return this->m_Payout;
}