#include <MailPackager.hpp>

MailPackager::MailPackager()
{
	// Loads all the textures
	this->m_Packages[0] = LoadTexture((gameManager->GetAssetPath() + "MailPackager/PackageFront.png").c_str());
	this->m_Packages[1] = LoadTexture((gameManager->GetAssetPath() + "MailPackager/PackageFrontStamp.png").c_str());
	this->m_Packages[2] = LoadTexture((gameManager->GetAssetPath() + "MailPackager/PackageBack.png").c_str());
	this->m_Packages[3] = LoadTexture((gameManager->GetAssetPath() + "MailPackager/PackageBackStamp.png").c_str());

	this->m_Letters[0] = LoadTexture((gameManager->GetAssetPath() + "MailPackager/LetterFront.png").c_str());
	this->m_Letters[1] = LoadTexture((gameManager->GetAssetPath() + "MailPackager/LetterFrontStamp.png").c_str());
	this->m_Letters[2] = LoadTexture((gameManager->GetAssetPath() + "MailPackager/LetterBack.png").c_str());
	this->m_Letters[3] = LoadTexture((gameManager->GetAssetPath() + "MailPackager/LetterBackStamp.png").c_str());

	this->m_Background = LoadTexture((gameManager->GetAssetPath() + "MailPackager/Background.png").c_str());
	this->m_FinishScreen = LoadTexture((gameManager->GetAssetPath() + "MailPackager/FinishScreen.png").c_str());
}
MailPackager::~MailPackager()
{
	// Unloads all the textures
	for (int i = 0; i < 4; i++)
	{
		UnloadTexture(this->m_Packages[i]);
		UnloadTexture(this->m_Letters[i]);
	}
	UnloadTexture(this->m_Background);
	UnloadTexture(this->m_FinishScreen);
}

void MailPackager::UpdateGame()
{
	// Displays the background
	while (this->m_MailsLeft > 0)
	{
		this->m_MousePos = GetMousePosition();
		BeginDrawing();
		ClearBackground(BROWN);

		DrawTexture(this->m_Background, 0, 0, WHITE);
		DrawText((std::to_string(m_Money[this->m_Score]) + "$").c_str(), GetScreenWidth() / 2 - 50, 50, 50, GREEN);

		if (this->m_NextMail)
		{
			this->m_MailType = rand() % 2; // random number from 0 to 1
			this->m_Front = rand() % 2;
			this->m_Back = rand() % 2 + 2; // random number from 2 to 3
			this->m_NextMail = 0;
			this->m_MailsLeft--;
		}

		if (this->m_Idle)
		{
			this->m_LetterPos.x = GetScreenWidth() / 2 - 80;
			this->m_LetterPos.y = 300;
		}
		else
		{
			this->m_LetterPos.x = this->m_MousePos.x - 65;
			this->m_LetterPos.y = this->m_MousePos.y - 30;
		}

		if (this->m_MailType && this->m_MailsLeft != 0)
		{
			DrawTexture(this->m_Side ? this->m_Packages[this->m_Front] : this->m_Packages[this->m_Back], this->m_LetterPos.x, this->m_LetterPos.y, WHITE);
		}
		else if (this->m_MailsLeft != 0)
		{
			DrawTexture(this->m_Side ? this->m_Letters[this->m_Front] : this->m_Letters[this->m_Back], this->m_LetterPos.x, this->m_LetterPos.y, WHITE);
		}

		if (IsKeyPressed(KEY_F))
		{
			this->m_Side = !this->m_Side;
		}

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && this->m_MousePos.x >= GetScreenWidth() / 2 - 80 && this->m_MousePos.x <= GetScreenWidth() / 2 + 50 && this->m_MousePos.y >= 300 && this->m_MousePos.y <= 400)
		{
			this->m_Idle = 0;
		}

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !this->m_Idle && this->m_MousePos.x >= GetScreenWidth() / 2 - 550 && this->m_MousePos.x <= GetScreenWidth() / 2 - 400 && this->m_MousePos.y >= 150 && this->m_MousePos.y <= 300 && this->m_MailsLeft != 0)
		{
			if (this->m_MailType == 0)
			{
				this->m_Score++;
			}
			else
			{
				if (this->m_Score != 0)
				{
					this->m_Score--;
				}
			}
			this->m_NextMail = 1;
			this->m_Idle = 1;
		}

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !this->m_Idle && this->m_MousePos.x >= GetScreenWidth() / 2 + 340 && this->m_MousePos.x <= GetScreenWidth() / 2 + 500 && this->m_MousePos.y >= 150 && this->m_MousePos.y <= 300 && this->m_MailsLeft != 0)
		{
			if (this->m_MailType == 1)
			{
				this->m_Score++;
			}
			else
			{
				if (this->m_Score != 0)
				{
					this->m_Score--;
				}
			}
			this->m_NextMail = 1;
			this->m_Idle = 1;
		}

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !this->m_Idle && this->m_MousePos.x >= GetScreenWidth() / 2 - 50 && this->m_MousePos.x <= GetScreenWidth() / 2 + 150 && this->m_MousePos.y >= 670 && this->m_MousePos.y <= 850 && this->m_MailsLeft != 0)
		{
			if (this->m_Front == 0 && this->m_Back == 2)
			{
				this->m_Score++;
			}
			else
			{
				if (this->m_Score != 0)
				{
					this->m_Score--;
				}
			}
			this->m_NextMail = 1;
			this->m_Idle = 1;
		}

		EndDrawing();
	}
	this->m_Payout = this->m_Money[this->m_Score];
	gameManager->StartTimer(3);
	while (!gameManager->TimerEnded())
	{
		BeginDrawing();
		ClearBackground(BROWN);
		DrawTexture(this->m_FinishScreen, 0, 0, WHITE);
		DrawText("Congratulations", GetScreenWidth() / 2 - 320, 80, 80, BLACK);
		DrawText("You have won", GetScreenWidth() / 2 - 175, 250, 50, BLACK);
		if (this->m_Score == 1 || this->m_Score == 2)
		{
			DrawText((std::to_string(this->m_Money[this->m_Score]) + "$").c_str(), GetScreenWidth() / 2 - 180, 350, 200, GREEN);
		}
		else if (this->m_Score == 0)
		{
			DrawText((std::to_string(this->m_Money[this->m_Score]) + "$").c_str(), GetScreenWidth() / 2 - 200, 350, 200, GREEN);
		}
		else
		{
			DrawText((std::to_string(this->m_Money[this->m_Score]) + "$").c_str(), GetScreenWidth() / 2 - 240, 350, 200, GREEN);
		}
		EndDrawing();
	}
}

int MailPackager::GetPayout()
{
	return this->m_Payout;
}