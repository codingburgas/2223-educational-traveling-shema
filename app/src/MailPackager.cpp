#include <MailPackager.hpp>

MailPackager::MailPackager()
{
	this->Packages[0] = LoadTexture((gameManager->getAssetPath() + "MailPackager/PackageFront.png").c_str());
	this->Packages[1] = LoadTexture((gameManager->getAssetPath() + "MailPackager/PackageFrontStamp.png").c_str());
	this->Packages[2] = LoadTexture((gameManager->getAssetPath() + "MailPackager/PackageBack.png").c_str());
	this->Packages[3] = LoadTexture((gameManager->getAssetPath() + "MailPackager/PackageBackStamp.png").c_str());

	this->Letters[0] = LoadTexture((gameManager->getAssetPath() + "MailPackager/LetterFront.png").c_str());
	this->Letters[1] = LoadTexture((gameManager->getAssetPath() + "MailPackager/LetterFrontStamp.png").c_str());
	this->Letters[2] = LoadTexture((gameManager->getAssetPath() + "MailPackager/LetterBack.png").c_str());
	this->Letters[3] = LoadTexture((gameManager->getAssetPath() + "MailPackager/LetterBackStamp.png").c_str());

	this->Background = LoadTexture((gameManager->getAssetPath() + "MailPackager/Background.png").c_str());
	this->FinishScreen = LoadTexture((gameManager->getAssetPath() + "MailPackager/FinishScreen.png").c_str());
}
MailPackager::~MailPackager()
{
	for (int i = 0; i < 4; i++)
	{
		UnloadTexture(this->Packages[i]);
		UnloadTexture(this->Letters[i]);
	}
	UnloadTexture(this->Background);
	UnloadTexture(this->FinishScreen);
}

void MailPackager::UpdateGame()
{

	const char* money[11] = { " 0$ ", "40$", "80$", "120$", "160$", "200$", "240$", "280$", "320$", "360$", "400$" };
	
	while (this->MailsLeft > 0)
	{
		MousePos = GetMousePosition();
		BeginDrawing();
		ClearBackground(BROWN);

		DrawTexture(this->Background, 0, 0, WHITE);
		DrawText(money[this->Score], GetScreenWidth() / 2 - 50, 50, 50, GREEN);

		if (this->NextMail)
		{
			this->MailType = rand() % 2; // random number from 0 to 1
			this->Front = rand() % 2;
			this->Back = rand() % 2 + 2; // random number from 2 to 3
			this->NextMail = 0;
			this->MailsLeft--;
		}

		if (this->Idle)
		{
			this->LetterPos.x = GetScreenWidth() / 2 - 80;
			this->LetterPos.y = 300;
		}
		else
		{
			this->LetterPos.x = MousePos.x - 65;
			this->LetterPos.y = MousePos.y - 30;
		}

		if (this->MailType && this->MailsLeft != 0)
		{
			DrawTexture(this->Side ? this->Packages[this->Front] : this->Packages[this->Back], this->LetterPos.x, this->LetterPos.y, WHITE);
		}
		else if (this->MailsLeft != 0)
		{
			DrawTexture(this->Side ? this->Letters[this->Front] : this->Letters[this->Back], this->LetterPos.x, this->LetterPos.y, WHITE);
		}

		if (IsKeyPressed(KEY_F))
		{
			this->Side = !this->Side;
		}

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && MousePos.x >= GetScreenWidth() / 2 - 80 && MousePos.x <= GetScreenWidth() / 2 + 50 && MousePos.y >= 300 && MousePos.y <= 400)
		{
			this->Idle = 0;
		}

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !this->Idle && MousePos.x >= GetScreenWidth() / 2 - 550 && MousePos.x <= GetScreenWidth() / 2 - 400 && MousePos.y >= 150 && MousePos.y <= 300 && this->MailsLeft != 0)
		{
			if (this->MailType == 0)
			{
				this->Score++;
			}
			else
			{
				if (this->Score != 0)
				{
					this->Score--;
				}
			}
			this->NextMail = 1;
			this->Idle = 1;
		}

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !this->Idle && MousePos.x >= GetScreenWidth() / 2 + 340 && MousePos.x <= GetScreenWidth() / 2 + 500 && MousePos.y >= 150 && MousePos.y <= 300 && this->MailsLeft != 0)
		{
			if (this->MailType == 1)
			{
				this->Score++;
			}
			else
			{
				if (this->Score != 0)
				{
					this->Score--;
				}
			}
			this->NextMail = 1;
			this->Idle = 1;
		}

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !this->Idle && MousePos.x >= GetScreenWidth() / 2 - 50 && MousePos.x <= GetScreenWidth() / 2 + 150 && MousePos.y >= 670 && MousePos.y <= 850 && this->MailsLeft != 0)
		{
			if (this->Front == 0 && this->Back == 2)
			{
				this->Score++;
			}
			else
			{
				if (this->Score != 0)
				{
					this->Score--;
				}
			}
			this->NextMail = 1;
			this->Idle = 1;
		}

		EndDrawing();
	}
	gameManager->StartTimer(3);
	while (!gameManager->TimerEnded())
	{
		BeginDrawing();
		ClearBackground(BROWN);
		DrawTexture(this->FinishScreen, 0, 0, WHITE);
		DrawText("Congratulations", GetScreenWidth() / 2 - 320, 80, 80, BLACK);
		DrawText("You have won", GetScreenWidth() / 2 - 175, 250, 50, BLACK);
		if (this->Score == 1 || this->Score == 2)
		{
			DrawText(money[this->Score], GetScreenWidth() / 2 - 180, 350, 200, GREEN);
		}
		else if (this->Score == 0)
		{
			DrawText(money[this->Score], GetScreenWidth() / 2 - 200, 350, 200, GREEN);
		}
		else
		{
			DrawText(money[this->Score], GetScreenWidth() / 2 - 240, 350, 200, GREEN);
		}
		EndDrawing();
	}
}