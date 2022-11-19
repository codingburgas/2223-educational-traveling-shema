#include <Game.hpp>

Game::Game()
{
	gameManager->LoadScene(gameManager->SCENE::GAME, { "Map.png" }, { {gameManager->GetScreenSize().x / 2 - mapManager->GetMapSize().x / 2, gameManager->GetScreenSize().y / 2 - mapManager->GetMapSize().y / 2} });
	LoadDynamicTextures();
	this->CountryHUDTexture = LoadTexture((gameManager->getAssetPath() + "CountryHUD.png").c_str());
	for (int i = 0; i < 5; i++) i % 2 == 0 ? ChooseCountryAnimation(true) : ChooseCountryAnimation(false);
	while (gameManager->currentScene == gameManager->SCENE::GAME && !gameManager->GetShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLUE);
		gameManager->Update();
		mapManager->UpdateMap();
		this->DrawHUD();
		EndDrawing();
		if (mapManager->GetChosenCountry().empty()) ChooseStartingCountry();
		if (IsKeyPressed(257))
		{
			SeaMinigame* seaMinigame = new SeaMinigame();
			seaMinigame->UpdateGame();
			delete seaMinigame;
		}
	}
}

Game::~Game()
{

}

void Game::LoadDynamicTextures()
{
	this->CountryHUDTexture = LoadTexture((gameManager->getAssetPath() + "CountryHUD.png").c_str());
	
	this->UnlockButton = LoadTexture((gameManager->getAssetPath() + "UnlockButton.png").c_str());
	this->UnlockButtonHover = LoadTexture((gameManager->getAssetPath() + "UnlockButtonHover.png").c_str());
	this->UnlockButtonLocked = LoadTexture((gameManager->getAssetPath() + "UnlockButtonLocked.png").c_str());
	this->Unlocked = LoadTexture((gameManager->getAssetPath() + "Unlocked.png").c_str());
	
	this->TravelButton = LoadTexture((gameManager->getAssetPath() + "TravelButton.png").c_str());
	this->TravelButtonHover = LoadTexture((gameManager->getAssetPath() + "TravelButtonHover.png").c_str());
	this->TravelButtonLocked = LoadTexture((gameManager->getAssetPath() + "TravelButtonLocked.png").c_str());
	
	this->TravelTicketButton = LoadTexture((gameManager->getAssetPath() + "TravelTicketButton.png").c_str());
	this->TravelTicketButtonHover = LoadTexture((gameManager->getAssetPath() + "TravelTicketButtonHover.png").c_str());
	this->TravelTicketButtonLocked = LoadTexture((gameManager->getAssetPath() + "TravelTicketButtonLocked.png").c_str());

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
	BeginDrawing();
	ClearBackground(BLUE);
	DrawText("Choose a country!", gameManager->GetScreenSize().x / 2 - MeasureText("Choose a country!", 60) / 2, 50, 60, RED);
	gameManager->StartTimer(0.1);
	if (!mapManager->IsWaypointClicked().name.empty() && !chosen)
	{
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
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && gameManager->TimerEnded())
				{
					mapManager->SetChosenCountry(mapManager->IsWaypointClicked().name, mapManager->IsWaypointClicked().pos);
					UnloadTexture(ModalWindow);
					UnloadTexture(YesButton);
					UnloadTexture(NoButton);
					chosen = true;
					break;
				}
			}
			
			DrawTextureEx(NoButton, { gameManager->GetScreenSize().x / 2 + NoButton.width - 50, gameManager->GetScreenSize().y / 2 + NoButton.height + 50 }, 0, 2, WHITE);
			if (CheckCollisionPointRec(GetMousePosition(), { gameManager->GetScreenSize().x / 2 + NoButton.width - 50, gameManager->GetScreenSize().y / 2 + NoButton.height + 50, float(NoButton.width * 2), float(NoButton.height * 2) }))
			{
				SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
				DrawTextureEx(NoButton, { gameManager->GetScreenSize().x / 2 + NoButton.width - 50, gameManager->GetScreenSize().y / 2 + NoButton.height + 50 }, 0, 2, Fade(BLACK, 0.5f));
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && gameManager->TimerEnded())
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

void Game::DrawHUD()
{
	if (!mapManager->IsWaypointClicked().name.empty())
	{
		this->CountryHUD = mapManager->IsWaypointClicked().name;
		this->CountryHUDUnlocked = mapManager->IsWaypointClicked().unlocked;
	}
	if (!CountryHUD.empty())
	{
		DrawTexture(this->CountryHUDTexture, 0, 250, WHITE);
		DrawTextEx(gameManager->impact, TextToUpper(CountryHUD.c_str()), { 50, 290 }, 50, 2, BLACK);

		if (this->CountryHUDUnlocked)
		{
			if (this->tickets >= 1 && mapManager->getPlayerCountry() != CountryHUD)
			{
				DrawTexture(this->TravelTicketButton, 50, 590, WHITE);
				//check if hovered
				if (CheckCollisionPointRec(GetMousePosition(), { 50, 590, float(TravelTicketButton.width), float(TravelTicketButton.height) }))
				{
					SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
					DrawTexture(this->TravelTicketButton, 50, 590, Fade(BLACK, 0.5f));
					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && gameManager->TimerEnded())
					{
						this->tickets--;
						mapManager->TravelToCountry(CountryHUD);
					}
				}
			}
			else
			{
				DrawTexture(this->TravelTicketButtonLocked, 50, 590, WHITE);
			}

			if (balance >= 185 && mapManager->getPlayerCountry() != CountryHUD)
			{
				DrawTexture(this->TravelButton, 176, 590, WHITE);
				if (CheckCollisionPointRec(GetMousePosition(), { 176, 590, float(TravelButton.width), float(TravelButton.height) }))
				{
					SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
					DrawTexture(this->TravelButton, 176, 590, Fade(BLACK, 0.5f));
					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && gameManager->TimerEnded())
					{
						this->balance -= 185;
						mapManager->TravelToCountry(CountryHUD);
					}
				}
			}
			else
			{
				DrawTexture(this->TravelButtonLocked, 176, 590, WHITE);
			}
			DrawTexture(this->Unlocked, 50, 685, WHITE);
		}
		else
		{
			DrawTexture(this->UnlockButton, 50, 685, WHITE);
			DrawTexture(this->TravelTicketButtonLocked, 50, 590, WHITE);
			DrawTexture(this->TravelButtonLocked, 176, 590, WHITE);
		}
	}
}