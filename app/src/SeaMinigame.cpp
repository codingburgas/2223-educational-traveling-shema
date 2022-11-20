#include <SeaMinigame.hpp>

SeaMinigame::SeaMinigame()
{
	RandomizeRubbish();
	HideCursor();
}

SeaMinigame::~SeaMinigame()
{
	UnloadTexture(this->m_Waves);
	UnloadTexture(this->m_Bag);
	UnloadTexture(this->m_Can);
	UnloadTexture(this->m_Bottle);
	UnloadTexture(this->m_Hook);
	UnloadTexture(this->m_Rope);
}


void SeaMinigame::RandomizeRubbish()
{
	for (int i = 0; i < 20; i++)
	{
		this->m_RubbishArray[i].type = rand() % 3 + 1;
	}

	for (int i = 0; i < 20; i++)
	{
		this->m_RubbishArray[i].x = rand() % 1820 + 1;
		this->m_RubbishArray[i].y = rand() % 450 + 450;
		for (int j = 0; j < i; j++)
		{
			while (abs(this->m_RubbishArray[i].x - this->m_RubbishArray[j].x) < 100)
			{
				this->m_RubbishArray[i].x = rand() % 1820 + 1;
			}
			while (abs(this->m_RubbishArray[i].y - this->m_RubbishArray[j].y) < 100)
			{
				this->m_RubbishArray[i].y = rand() % 450 + 450;
			}
		}
	}
}

void SeaMinigame::UpdateGame()
{
	while (this->m_RemainingRubbish > 0)
	{
		BeginDrawing();
		ClearBackground(BLACK);
		DrawTexture(this->m_Waves, 0, 0, WHITE);
		
		m_MousePos = GetMousePosition();

		DrawTexture(this->m_Rope, this->m_MousePos.x - 29, this->m_MousePos.y - this->m_Rope.height - 10, RAYWHITE);
		DrawTexture(this->m_Hook, this->m_MousePos.x - 20, this->m_MousePos.y - 25, RAYWHITE);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			for (int i = 0; i < 20; i++)
			{
				if ((this->m_MousePos.x >= this->m_RubbishArray[i].x && this->m_MousePos.x <= this->m_RubbishArray[i].x + 65) && (this->m_MousePos.y >= this->m_RubbishArray[i].y && this->m_MousePos.y <= this->m_RubbishArray[i].y + 55) && !this->m_RubbishArray[i].isClicked && !this->m_RubbishArray[i].isCleaned && !this->m_Carrying)
				{
					SetMousePosition(this->m_RubbishArray[i].x + 20, this->m_RubbishArray[i].y + 20);
					this->m_RubbishArray[i].isClicked = 1;
					this->m_Carrying = 1;
					break;
				}
				else if ((this->m_MousePos.x >= 0 && this->m_MousePos.x <= 1920) && (this->m_MousePos.y >= 0 && this->m_MousePos.y <= 345))
				{
					for (int j = 0; j < 20; j++)
					{
						if (this->m_RubbishArray[j].isClicked == 1)
						{
							this->m_RubbishArray[j].isClicked = 0;
							this->m_RubbishArray[j].isCleaned = 1;
							this->m_RemainingRubbish--;
							break;
						}
					}
					this->m_Carrying = 0;
					break;
				}
			}


		}
		for (int i = 0; i < 20; i++)
		{
			if (this->m_RubbishArray[i].isClicked && !this->m_RubbishArray[i].isCleaned)
			{
				switch (this->m_RubbishArray[i].type)
				{
				case 1:
					DrawTexture(this->m_Bag, this->m_MousePos.x - 25, this->m_MousePos.y - 15, RAYWHITE);
					break;
				case 2:
					DrawTexture(this->m_Can, this->m_MousePos.x - 25, this->m_MousePos.y, RAYWHITE);
					break;
				default:
					DrawTexture(this->m_Bottle, this->m_MousePos.x - 25, this->m_MousePos.y, RAYWHITE);
					break;

				}
			}
			else if (!this->m_RubbishArray[i].isClicked && !this->m_RubbishArray[i].isCleaned)
			{
				switch (this->m_RubbishArray[i].type)
				{
				case 1:
					DrawTexture(this->m_Bag, this->m_RubbishArray[i].x, this->m_RubbishArray[i].y, RAYWHITE);
					break;
				case 2:
					DrawTexture(this->m_Can, this->m_RubbishArray[i].x, this->m_RubbishArray[i].y, RAYWHITE);
					break;
				default:
					DrawTexture(this->m_Bottle, this->m_RubbishArray[i].x, this->m_RubbishArray[i].y, RAYWHITE);
					break;

				}
			}
		}
		EndDrawing();
	}
	this->gameManager->StartTimer(3);
	this->m_Payout = 350;
	while (!gameManager->TimerEnded())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawTexture(this->m_Waves, 0, 0, WHITE);
		DrawRectangle(0, 0, 1920, 1080, Fade(BLACK, 0.5f));
		DrawText("Congratulations!", gameManager->GetScreenSize().x / 2 - MeasureText("Congratulations!", 60) / 2, gameManager->GetScreenSize().y/2 - 80, 60, RED);
		DrawText("You've cleaned the sea!", gameManager->GetScreenSize().x / 2 - MeasureText("You've cleaned the sea!", 60) / 2, gameManager->GetScreenSize().y/2 - 20, 60, RED);
		EndDrawing();
	}
	ShowCursor();
}

int SeaMinigame::GetPayout()
{
	return this->m_Payout;
}