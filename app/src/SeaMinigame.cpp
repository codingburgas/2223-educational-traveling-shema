#include <SeaMinigame.hpp>

SeaMinigame::SeaMinigame()
{
	srand(time(NULL));
	
	RandomizeRubbish();

	HideCursor();
}

SeaMinigame::~SeaMinigame()
{
	UnloadTexture(waves);
	UnloadTexture(bag);
	UnloadTexture(can);
	UnloadTexture(bottle);
	UnloadTexture(hook);
	UnloadTexture(rope);
}


void SeaMinigame::RandomizeRubbish()
{
	for (int i = 0; i < 20; i++)
	{
		rubbishArray[i].type = rand() % 3 + 1;
	}

	for (int i = 0; i < 20; i++)
	{
		rubbishArray[i].x = rand() % 1820 + 1;
		rubbishArray[i].y = rand() % 450 + 450;
		for (int j = 0; j < i; j++)
		{
			while (abs(rubbishArray[i].x - rubbishArray[j].x) < 100)
			{
				rubbishArray[i].x = rand() % 1820 + 1;
			}
			while (abs(rubbishArray[i].y - rubbishArray[j].y) < 100)
			{
				rubbishArray[i].y = rand() % 450 + 450;
			}
		}
	}
}

void SeaMinigame::UpdateGame()
{
	while (RemainingRubbish > 0)
	{
		BeginDrawing();
		ClearBackground(BLACK);
		DrawTexture(waves, 0, 0, WHITE);
		
		MousePos = GetMousePosition();

		DrawTexture(rope, MousePos.x - 29, MousePos.y - rope.height - 10, RAYWHITE);
		DrawTexture(hook, MousePos.x - 20, MousePos.y - 25, RAYWHITE);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			for (int i = 0; i < 20; i++)
			{
				if ((MousePos.x >= rubbishArray[i].x && MousePos.x <= rubbishArray[i].x + 65) && (MousePos.y >= rubbishArray[i].y && MousePos.y <= rubbishArray[i].y + 55) && !rubbishArray[i].isClicked && !rubbishArray[i].isCleaned && !carrying)
				{
					SetMousePosition(rubbishArray[i].x + 20, rubbishArray[i].y + 20);
					rubbishArray[i].isClicked = 1;
					carrying = 1;
					break;
				}
				else if ((MousePos.x >= 0 && MousePos.x <= 1920) && (MousePos.y >= 0 && MousePos.y <= 345))
				{
					for (int j = 0; j < 20; j++)
					{
						if (rubbishArray[j].isClicked == 1)
						{
							rubbishArray[j].isClicked = 0;
							rubbishArray[j].isCleaned = 1;
							RemainingRubbish--;
							break;
						}
					}
					carrying = 0;
					break;
				}
			}


		}
		for (int i = 0; i < 20; i++)
		{
			if (rubbishArray[i].isClicked && !rubbishArray[i].isCleaned)
			{
				switch (rubbishArray[i].type)
				{
				case 1:
					DrawTexture(bag, MousePos.x - 25, MousePos.y - 15, RAYWHITE);
					break;
				case 2:
					DrawTexture(can, MousePos.x - 25, MousePos.y, RAYWHITE);
					break;
				default:
					DrawTexture(bottle, MousePos.x - 25, MousePos.y, RAYWHITE);
					break;

				}
			}
			else if (!rubbishArray[i].isClicked && !rubbishArray[i].isCleaned)
			{
				switch (rubbishArray[i].type)
				{
				case 1:
					DrawTexture(bag, rubbishArray[i].x, rubbishArray[i].y, RAYWHITE);
					break;
				case 2:
					DrawTexture(can, rubbishArray[i].x, rubbishArray[i].y, RAYWHITE);
					break;
				default:
					DrawTexture(bottle, rubbishArray[i].x, rubbishArray[i].y, RAYWHITE);
					break;

				}
			}
		}
		EndDrawing();
	}
	gameManager->StartTimer(3);

	while (!gameManager->TimerEnded())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawTexture(waves, 0, 0, WHITE);
		DrawRectangle(0, 0, 1920, 1080, Fade(BLACK, 0.5f));
		DrawText("Congratulations!", gameManager->GetScreenSize().x / 2 - MeasureText("Congratulations!", 60) / 2, gameManager->GetScreenSize().y/2 - 80, 60, RED);
		DrawText("You've cleaned the sea!", gameManager->GetScreenSize().x / 2 - MeasureText("You've cleaned the sea!", 60) / 2, gameManager->GetScreenSize().y/2 - 20, 60, RED);
		EndDrawing();
	}
	ShowCursor();
	GameWon = true;
}
bool SeaMinigame::IsGameWon()
{
	return GameWon;
}