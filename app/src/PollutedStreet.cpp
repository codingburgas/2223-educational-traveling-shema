#include <raylib.h>
#include <vector>
#include <iostream>
#include <string>
#include <PollutedStreet.hpp>


PollutedStreet::PollutedStreet()
{
	// Loads the textures
	this->m_Background = LoadTexture("./assets/PollutedStreet/Background.png");
	this->m_FinishScreen = LoadTexture("./assets/PollutedStreet/FinishScreen.png");

	this->m_Rubbish1 = LoadTexture("./assets/PollutedStreet/rubbish.png");
	this->m_Rubbish2 = LoadTexture("./assets/PollutedStreet/rubbish2.png");
	this->m_Chips = LoadTexture("./assets/PollutedStreet/chips.png");
	this->m_Bin = LoadTexture("./assets/PollutedStreet/rubbish-bin.png");
	this->m_Food = LoadTexture("./assets/PollutedStreet/food.png");
	this->m_Food2 = LoadTexture("./assets/PollutedStreet/food2.png");
	this->m_Paper = LoadTexture("./assets/PollutedStreet/paper.png");

	for (int i = 0; i < 12; i++)
	{
		this->m_Bar[i] = LoadTexture((gameManager->GetAssetPath() + "PollutedStreet/bar" + std::to_string(i + 1) + ".png").c_str());
	}

	m_Rubbish = {
	{ {float(GetScreenWidth() / 2 - 150), float(GetScreenHeight() / 2 + 375)}, this->m_Rubbish2, 0, 0 },
	{ {float(GetScreenWidth() / 2 - 325), 919}, this->m_Paper, 0, 0 },
	{ {float(GetScreenWidth() / 2 - this->m_Rubbish1.width / 2 - 420), 950}, this->m_Rubbish1, 0, 0 },
	{ {350, 924}, this->m_Food, 0, 0 },
	{ {1700, 944}, this->m_Rubbish1, 0, 0 },
	{ {1200, 954}, this->m_Chips, 0, 0 },
	{ {1300, 990}, this->m_Food2, 0, 0 },
	{ {240, float(GetScreenHeight() - this->m_Bin.height + 30)}, this->m_Food2, 0, 0 },
	{ {904, 789}, this->m_Paper, 0, 0 },
	{ {1830, 724}, this->m_Chips, 0, 0 },
	{ {1449, 844}, this->m_Bin, 0, 0 },
	{ {1390, 779}, this->m_Food, 0, 0 },
	{ {719, 719}, this->m_Rubbish1, 0, 0 },
	{ {90, float(GetScreenHeight() / 2 + 270)}, this->m_Chips, 0, 0 },
	{ {100, float(GetScreenHeight() - this->m_Bin.height - 20)}, this->m_Bin, 0, 0 },
	{ {40, float(GetScreenHeight() / 2 + 190)}, this->m_Food, 0, 0 }
	};
}

PollutedStreet::~PollutedStreet()
{
	// Unloads the textures
	UnloadTexture(this->m_Background);
	UnloadTexture(this->m_FinishScreen);
	UnloadTexture(this->m_Rubbish1);
	UnloadTexture(this->m_Rubbish2);
	UnloadTexture(this->m_Chips);
	UnloadTexture(this->m_Bin);
	UnloadTexture(this->m_Food);
	UnloadTexture(this->m_Food2);
	UnloadTexture(this->m_Paper);
	
	for (int i = 0; i < 12; i++)
	{
		UnloadTexture(this->m_Bar[i]);
	}
}

void PollutedStreet::UpdateGame()
{
	// Updates the game
	BeginDrawing();
	ClearBackground(RAYWHITE);
	
	while (this->m_RemainingRubbish > 0)
	{
		this->m_MousePos = GetMousePosition();
		DrawTexture(this->m_Background, 0, 0, WHITE);

		for (size_t i = 0; i < this->m_Rubbish.size(); i++)
		{
			if (!this->m_Rubbish[i].cleaned)
			{
				DrawTexture(this->m_Rubbish[i].type, this->m_Rubbish[i].pos.x, this->m_Rubbish[i].pos.y, GRAY);
				if (this->m_MousePos.x >= this->m_Rubbish[i].pos.x && this->m_MousePos.x <= this->m_Rubbish[i].pos.x + this->m_Rubbish[i].type.width && this->m_MousePos.y >= this->m_Rubbish[i].pos.y - 20 && this->m_MousePos.y <= this->m_Rubbish[i].pos.y + this->m_Rubbish[i].type.height)
				{
					if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) this->m_Rubbish[i].clicked = 1;
				}

				if (IsKeyPressed(KEY_E) && this->m_Rubbish[i].clicked)
				{
					this->m_ePressed = 1;
					this->m_Rubbish[i].clicked = 0;

					if (this->m_BarPos >= 7 && this->m_BarPos <= 12)
					{
						this->m_Rubbish[i].cleaned = 1;
						this->m_RemainingRubbish--;
						this->m_BarPos = 0;
						this->m_ePressed = 0;
					}
					else
					{
						this->m_BarPos = 0;
						this->m_ePressed = 0;
					}
				}
			}
			if (this->m_Rubbish[i].clicked) DrawTexture(this->m_Bar[this->m_BarPos], 50, 50, WHITE);
		}

		if (!this->m_ePressed)
		{
			this->m_Delay += GetFrameTime();
			if (this->m_Delay >= 1)
			{
				this->m_Delay = 0;
				this->m_BarPos++;
				if (this->m_BarPos == 12) this->m_BarPos = 0;
			}
		}

		EndDrawing();
	}

	this->m_Payout = 400;

	gameManager->StartTimer(3);
	
	while (!gameManager->TimerEnded())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawTexture(this->m_FinishScreen, 0, 0, WHITE);
		DrawText("Congratulations!", GetScreenWidth() / 2 - 240, GetScreenHeight() / 2 - 250, 50, BLACK);
		DrawText("You have collected all the", GetScreenWidth() / 2 - 300, GetScreenHeight() / 2 - 100, 40, BLACK);
		DrawText("RUBBISH", GetScreenWidth() / 2 - 300, GetScreenHeight() / 2 - 50, 120, RED);
		EndDrawing();
	}

}

int PollutedStreet::GetPayout()
{
	return this->m_Payout;
}