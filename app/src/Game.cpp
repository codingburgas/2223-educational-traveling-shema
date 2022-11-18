#include <Game.hpp>

Game::Game()
{
	gameManager->LoadScene(gameManager->SCENE::GAME, { "Map.png" }, { {gameManager->GetScreenSize().x / 2 - mapManager->GetMapSize().x / 2, gameManager->GetScreenSize().y / 2 - mapManager->GetMapSize().y / 2} });
	for (int i = 0; i < 5; i++) i % 2 == 0 ? ChooseCountryAnimation(true) : ChooseCountryAnimation(false);
	while (gameManager->currentScene == gameManager->SCENE::GAME && !gameManager->GetShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLUE);
		gameManager->Update();
		mapManager->UpdateMap();
		if (mapManager->GetChosenCountry().empty()) ChooseStartingCountry();
		EndDrawing();
	}
}

Game::~Game()
{

}

void Game::ChooseCountryAnimation(bool displayText)
{
	gameManager->StartTimer(0.5);
	while (!gameManager->TimerEnded()) {
		BeginDrawing();
		ClearBackground(BLUE);
		gameManager->Update();
		if (displayText) {
			DrawRectangle(0, 0, gameManager->GetScreenSize().x, gameManager->GetScreenSize().y, Fade(BLACK, 0.5f));
			DrawText("Choose a country", gameManager->GetScreenSize().x / 2 - MeasureText("Choose a country", 100) / 2, gameManager->GetScreenSize().y / 2 - 20 / 2, 100, RED);
		} else DrawRectangle(0, 0, gameManager->GetScreenSize().x, gameManager->GetScreenSize().y, Fade(BLACK, 0.5f));
		EndDrawing();
	}
}

void Game::ChooseStartingCountry()
{
	DrawText("Choose a country!", gameManager->GetScreenSize().x / 2 - MeasureText("Choose a country!", 60) / 2, 50, 60, RED);
	if (!mapManager->IsWaypointClicked().name.empty())
	{
		bool chosen = false;
		std::string clickedCountry = mapManager->IsWaypointClicked().name;
		std::cout << clickedCountry;
		
		Texture2D ModalWindow = LoadTexture((gameManager->getAssetPath() + "CountryModal.png").c_str());
		Texture2D YesButton = LoadTexture((gameManager->getAssetPath() + "YesButton.png").c_str());
		Texture2D NoButton = LoadTexture((gameManager->getAssetPath() + "NoButton.png").c_str());
		
		while (!chosen)
		{
			BeginDrawing();
			ClearBackground(BLUE);
			gameManager->Update();
			
			DrawRectangle(0, 0, gameManager->GetScreenSize().x, gameManager->GetScreenSize().y, Fade(BLACK, 0.5f));
			DrawTextureEx(ModalWindow, { gameManager->GetScreenSize().x / 2 - ModalWindow.width, gameManager->GetScreenSize().y / 2 - ModalWindow.height }, 0, 2, WHITE);
			
			DrawText("Are you sure you\n want to choose", gameManager->GetScreenSize().x / 2 - MeasureText("Are you sure you want to choose", 60) / 4 - 20, gameManager->GetScreenSize().y / 2 - 180, 60, BLACK);
			DrawText(clickedCountry.c_str(), gameManager->GetScreenSize().x / 2 - MeasureText(clickedCountry.c_str(), 60) / 2, gameManager->GetScreenSize().y / 2, 60, RED);
			
			
			SetMouseCursor(MOUSE_CURSOR_DEFAULT);
			DrawTextureEx(YesButton, { gameManager->GetScreenSize().x / 2 - YesButton.width * 3 + 50, gameManager->GetScreenSize().y / 2 + YesButton.height + 50 }, 0, 2, WHITE);
			if (CheckCollisionPointRec(GetMousePosition(), {gameManager->GetScreenSize().x / 2 - YesButton.width * 3 + 50, gameManager->GetScreenSize().y / 2 + YesButton.height + 50, float(YesButton.width * 2), float(YesButton.height * 2)}))
			{
				SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
				DrawTextureEx(YesButton, {gameManager->GetScreenSize().x / 2 - YesButton.width * 3 + 50, gameManager->GetScreenSize().y / 2 + YesButton.height + 50}, 0, 2, Fade(BLACK, 0.5f));
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					mapManager->SetChosenCountry(mapManager->IsWaypointClicked().name);
					UnloadTexture(ModalWindow);
					UnloadTexture(YesButton);
					UnloadTexture(NoButton);
					chosen = true;
				}
			}
			
			DrawTextureEx(NoButton, { gameManager->GetScreenSize().x / 2 + NoButton.width - 50, gameManager->GetScreenSize().y / 2 + NoButton.height + 50 }, 0, 2, WHITE);
			if (CheckCollisionPointRec(GetMousePosition(), { gameManager->GetScreenSize().x / 2 + NoButton.width - 50, gameManager->GetScreenSize().y / 2 + NoButton.height + 50, float(NoButton.width * 2), float(NoButton.height * 2) }))
			{
				SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
				DrawTextureEx(NoButton, { gameManager->GetScreenSize().x / 2 + NoButton.width - 50, gameManager->GetScreenSize().y / 2 + NoButton.height + 50 }, 0, 2, Fade(BLACK, 0.5f));
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					UnloadTexture(ModalWindow);
					UnloadTexture(YesButton);
					UnloadTexture(NoButton);
					break;
				}
			}
			
			EndDrawing();
		}
	}
}