#include <Game.hpp>

Game::Game()
{
	gameManager->LoadScene(gameManager->SCENE::GAME, { "Map.png" }, { {gameManager->getScreenSize().x / 2 - mapManager->getMapSize().x / 2, gameManager->getScreenSize().y / 2 - mapManager->getMapSize().y / 2} });
	for (int i = 0; i < 5; i++) i % 2 == 0 ? ChooseCountryAnimation(true) : ChooseCountryAnimation(false);
	while (gameManager->currentScene == gameManager->SCENE::GAME && !gameManager->getShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLUE);
		gameManager->Update();
		mapManager->UpdateMap();
		if (mapManager->getChosenCountry().empty()) ChooseStartingCountry();
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
			DrawRectangle(0, 0, gameManager->getScreenSize().x, gameManager->getScreenSize().y, Fade(BLACK, 0.5f));
			DrawText("Choose a country", gameManager->getScreenSize().x / 2 - MeasureText("Choose a country", 100) / 2, gameManager->getScreenSize().y / 2 - 20 / 2, 100, RED);
		} else DrawRectangle(0, 0, gameManager->getScreenSize().x, gameManager->getScreenSize().y, Fade(BLACK, 0.5f));
		EndDrawing();
	}
}

void Game::ChooseStartingCountry()
{
	DrawText("Choose a country!", gameManager->getScreenSize().x / 2 - MeasureText("Choose a country!", 60) / 2, 50, 60, RED);
	if (!mapManager->isWaypointClicked().name.empty())
	{
		bool chosen = false;
		std::string clickedCountry = mapManager->isWaypointClicked().name;
		std::cout << clickedCountry;
		
		Texture2D ModalWindow = LoadTexture((gameManager->getAssetPath() + "CountryModal.png").c_str());
		Texture2D YesButton = LoadTexture((gameManager->getAssetPath() + "YesButton.png").c_str());
		Texture2D NoButton = LoadTexture((gameManager->getAssetPath() + "NoButton.png").c_str());
		
		while (!chosen)
		{
			BeginDrawing();
			ClearBackground(BLUE);
			gameManager->Update();
			
			DrawRectangle(0, 0, gameManager->getScreenSize().x, gameManager->getScreenSize().y, Fade(BLACK, 0.5f));
			DrawTextureEx(ModalWindow, { gameManager->getScreenSize().x / 2 - ModalWindow.width, gameManager->getScreenSize().y / 2 - ModalWindow.height }, 0, 2, WHITE);
			
			DrawText("Are you sure you\n want to choose", gameManager->getScreenSize().x / 2 - MeasureText("Are you sure you want to choose", 60) / 4 - 20, gameManager->getScreenSize().y / 2 - 180, 60, BLACK);
			DrawText(clickedCountry.c_str(), gameManager->getScreenSize().x / 2 - MeasureText(clickedCountry.c_str(), 60) / 2, gameManager->getScreenSize().y / 2, 60, RED);
			
			
			SetMouseCursor(MOUSE_CURSOR_DEFAULT);
			DrawTextureEx(YesButton, { gameManager->getScreenSize().x / 2 - YesButton.width * 3 + 50, gameManager->getScreenSize().y / 2 + YesButton.height + 50 }, 0, 2, WHITE);
			if (CheckCollisionPointRec(GetMousePosition(), {gameManager->getScreenSize().x / 2 - YesButton.width * 3 + 50, gameManager->getScreenSize().y / 2 + YesButton.height + 50, float(YesButton.width * 2), float(YesButton.height * 2)}))
			{
				SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
				DrawTextureEx(YesButton, {gameManager->getScreenSize().x / 2 - YesButton.width * 3 + 50, gameManager->getScreenSize().y / 2 + YesButton.height + 50}, 0, 2, Fade(BLACK, 0.5f));
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					mapManager->setChosenCountry(mapManager->isWaypointClicked().name);
					UnloadTexture(ModalWindow);
					UnloadTexture(YesButton);
					UnloadTexture(NoButton);
					chosen = true;
				}
			}
			
			DrawTextureEx(NoButton, { gameManager->getScreenSize().x / 2 + NoButton.width - 50, gameManager->getScreenSize().y / 2 + NoButton.height + 50 }, 0, 2, WHITE);
			if (CheckCollisionPointRec(GetMousePosition(), { gameManager->getScreenSize().x / 2 + NoButton.width - 50, gameManager->getScreenSize().y / 2 + NoButton.height + 50, float(NoButton.width * 2), float(NoButton.height * 2) }))
			{
				SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
				DrawTextureEx(NoButton, { gameManager->getScreenSize().x / 2 + NoButton.width - 50, gameManager->getScreenSize().y / 2 + NoButton.height + 50 }, 0, 2, Fade(BLACK, 0.5f));
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