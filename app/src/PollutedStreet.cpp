#include <raylib.h>
#include <vector>
#include <iostream>
#include <string>
#include <PollutedStreet.hpp>


PollutedStreet::PollutedStreet()
{
	Background = LoadTexture("./assets/PollutedStreet/Background.png");
	FinishScreen = LoadTexture("./assets/PollutedStreet/FinishScreen.png");

	Rubbish1 = LoadTexture("./assets/PollutedStreet/rubbish.png");
	Rubbish2 = LoadTexture("./assets/PollutedStreet/rubbish2.png");
	Chips = LoadTexture("./assets/PollutedStreet/chips.png");
	Bin = LoadTexture("./assets/PollutedStreet/rubbish-bin.png");
	Food = LoadTexture("./assets/PollutedStreet/food.png");
	Food2 = LoadTexture("./assets/PollutedStreet/food2.png");
	Paper = LoadTexture("./assets/PollutedStreet/paper.png");

	for (int i = 0; i < 12; i++)
	{
		Bar[i] = LoadTexture((gameManager->getAssetPath() + "PollutedStreet/bar" + std::to_string(i + 1) + ".png").c_str());
	}

	Rubbish = {
	{ {float(GetScreenWidth() / 2 - 150), float(GetScreenHeight() / 2 + 375)}, Rubbish2, 0, 0 },
	{ {float(GetScreenWidth() / 2 - 325), 919}, Paper, 0, 0 },
	{ {float(GetScreenWidth() / 2 - Rubbish1.width / 2 - 420), 950}, Rubbish1, 0, 0 },
	{ {350, 924}, Food, 0, 0 },
	{ {1700, 944}, Rubbish1, 0, 0 },
	{ {1200, 954}, Chips, 0, 0 },
	{ {1300, 990}, Food2, 0, 0 },
	{ {240, float(GetScreenHeight() - Bin.height + 30)}, Food2, 0, 0 },
	{ {904, 789}, Paper, 0, 0 },
	{ {1830, 724}, Chips, 0, 0 },
	{ {1449, 844}, Bin, 0, 0 },
	{ {1390, 779}, Food, 0, 0 },
	{ {719, 719}, Rubbish1, 0, 0 },
	{ {90, float(GetScreenHeight() / 2 + 270)}, Chips, 0, 0 },
	{ {100, float(GetScreenHeight() - Bin.height - 20)}, Bin, 0, 0 },
	{ {40, float(GetScreenHeight() / 2 + 190)}, Food, 0, 0 }
	};
}

PollutedStreet::~PollutedStreet()
{
	UnloadTexture(Background);
	UnloadTexture(FinishScreen);
	UnloadTexture(Rubbish1);
	UnloadTexture(Rubbish2);
	UnloadTexture(Chips);
	UnloadTexture(Bin);
	UnloadTexture(Food);
	UnloadTexture(Food2);
	UnloadTexture(Paper);
	
	for (int i = 0; i < 12; i++)
	{
		UnloadTexture(Bar[i]);
	}
}

void PollutedStreet::UpdateGame()
{

	BeginDrawing();
	ClearBackground(RAYWHITE);
	
	while (RemainingRubbish > 0)
	{
		MousePos = GetMousePosition();
		DrawTexture(Background, 0, 0, WHITE);

		for (size_t i = 0; i < Rubbish.size(); i++)
		{
			if (!Rubbish[i].cleaned)
			{
				DrawTexture(Rubbish[i].type, Rubbish[i].pos.x, Rubbish[i].pos.y, GRAY);
				if (MousePos.x >= Rubbish[i].pos.x && MousePos.x <= Rubbish[i].pos.x + Rubbish[i].type.width && MousePos.y >= Rubbish[i].pos.y - 20 && MousePos.y <= Rubbish[i].pos.y + Rubbish[i].type.height)
				{
					if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
					{
						Rubbish[i].clicked = 1;
					}
				}

				if (IsKeyPressed(KEY_E) && Rubbish[i].clicked)
				{
					ePressed = 1;
					Rubbish[i].clicked = 0;

					if (BarPos >= 7 && BarPos <= 12)
					{
						Rubbish[i].cleaned = 1;
						RemainingRubbish--;
						BarPos = 0;
						ePressed = 0;
					}
					else
					{
						BarPos = 0;
						ePressed = 0;
					}
				}
			}
			if (Rubbish[i].clicked)
			{
				DrawTexture(Bar[BarPos], 50, 50, WHITE);
			}
		}

		if (!ePressed)
		{
			Delay += GetFrameTime();
			if (Delay >= 1)
			{
				Delay = 0;
				BarPos++;
				if (BarPos == 12)
				{
					BarPos = 0;
				}
			}
		}

		EndDrawing();
	}

	Payout = 400;

	gameManager->StartTimer(3);
	
	while (!gameManager->TimerEnded())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawTexture(FinishScreen, 0, 0, WHITE);
		DrawText("Congratulations!", GetScreenWidth() / 2 - 240, GetScreenHeight() / 2 - 250, 50, BLACK);
		DrawText("You have collected all the", GetScreenWidth() / 2 - 300, GetScreenHeight() / 2 - 100, 40, BLACK);
		DrawText("RUBBISH", GetScreenWidth() / 2 - 300, GetScreenHeight() / 2 - 50, 120, RED);
		EndDrawing();
	}

}

int PollutedStreet::getPayout()
{
	return Payout;
}