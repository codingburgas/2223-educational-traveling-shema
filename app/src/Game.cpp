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
		Texture2D YesButtonHover = LoadTexture((gameManager->getAssetPath() + "YesButtonHover.png").c_str());
		Texture2D NoButton = LoadTexture((gameManager->getAssetPath() + "NoButton.png").c_str());
		Texture2D NoButtonHover = LoadTexture((gameManager->getAssetPath() + "NoButtonHover.png").c_str());
		
		
		while (!chosen)
		{
			BeginDrawing();
			ClearBackground(BLUE);
			gameManager->Update();
			
			DrawRectangle(0, 0, gameManager->GetScreenSize().x, gameManager->GetScreenSize().y, Fade(BLACK, 0.5f));
			DrawTextureEx(ModalWindow, { gameManager->GetScreenSize().x / 2 - ModalWindow.width/2, gameManager->GetScreenSize().y / 2 - ModalWindow.height/2 }, 0, 1, WHITE);
			
			DrawTextEx(gameManager->impact, clickedCountry.c_str(), { gameManager->GetScreenSize().x / 2 - MeasureTextEx(gameManager->impact, (clickedCountry).c_str()  , 80, 1).x / 2, gameManager->GetScreenSize().y / 2 - 30}, 80, 1, RED);
			DrawTextEx(gameManager->impact, "?", {gameManager->GetScreenSize().x / 2 + MeasureTextEx(gameManager->impact, clickedCountry.c_str(), 80, 1).x / 2, gameManager->GetScreenSize().y / 2 - 30}, 80, 0, BLACK);
			SetMouseCursor(MOUSE_CURSOR_DEFAULT);
			DrawTexture(YesButton, 753, 657, WHITE);
			if (CheckCollisionPointRec(GetMousePosition(), {753, 657, float(YesButton.width), float(YesButton.height)}))
			{
				SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
				DrawTexture(YesButtonHover, 753, 657, WHITE);
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
				
			DrawTexture(NoButton, 1010, 657, WHITE);
			if (CheckCollisionPointRec(GetMousePosition(), { 1010, 657, float(NoButton.width), float(NoButton.height) }))
			{
				SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
				DrawTexture(NoButtonHover, 1010, 657, WHITE);
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
		this->ClickedCountryName = mapManager->IsWaypointClicked().name;
		this->ClickedCountryUnlocked = mapManager->IsWaypointClicked().unlocked;
		this->ClickedCountryPrice = mapManager->IsWaypointClicked().price;
	}
	if (!ClickedCountryName.empty())
	{
		DrawTexture(this->CountryHUDTexture, 0, 250, WHITE);
		DrawTextEx(gameManager->impact, TextToUpper(ClickedCountryName.c_str()), { 50, 290 }, 50, 2, BLACK);

		if (this->ClickedCountryUnlocked)
		{
			if (this->tickets >= 1 && mapManager->getPlayerCountry() != ClickedCountryName)
			{
				DrawTexture(this->TravelTicketButton, 50, 590, WHITE);
				if (CheckCollisionPointRec(GetMousePosition(), { 50, 590, float(TravelTicketButton.width), float(TravelTicketButton.height) }))
				{
					SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
					DrawTexture(this->TravelTicketButton, 50, 590, Fade(BLACK, 0.5f));
					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
					{
						this->tickets--;
						mapManager->TravelToCountry(ClickedCountryName);
					}
				}
			}
			else
			{
				DrawTexture(this->TravelTicketButtonLocked, 50, 590, WHITE);
			}

			if (balance >= 185 && mapManager->getPlayerCountry() != ClickedCountryName)
			{
				DrawTexture(this->TravelButton, 176, 590, WHITE);
				if (CheckCollisionPointRec(GetMousePosition(), { 176, 590, float(TravelButton.width), float(TravelButton.height) }))
				{
					SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
					DrawTexture(this->TravelButton, 176, 590, Fade(BLACK, 0.5f));
					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
					{
						this->balance -= 185;
						mapManager->TravelToCountry(ClickedCountryName);
					}
				}
			}
			else
			{
				DrawTexture(this->TravelButtonLocked, 176, 590, WHITE);
			}
			
			DrawTextEx(gameManager->impact, "Already unlocked", { 117, 658 }, 25, 1, GREEN);
			DrawTexture(this->Unlocked, 50, 685, WHITE);
		}
		else
		{
			if (balance >= ClickedCountryPrice)
			{
				DrawTexture(this->UnlockButton, 50, 685, WHITE);
				if (CheckCollisionPointRec(GetMousePosition(), { 50, 685, float(UnlockButton.width), float(UnlockButton.height) }))
				{
					SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
					DrawTexture(this->UnlockButtonHover, 50, 685, WHITE);
					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
					{
						this->balance -= ClickedCountryPrice;
						mapManager->UnlockCountry(ClickedCountryName);
					}
				}
			}
			else
			{
				DrawTexture(this->UnlockButtonLocked, 50, 685, WHITE);
			}
			DrawTextEx(gameManager->impact, std::to_string(ClickedCountryPrice).c_str(), { 117, 658 }, 25, 1, BLACK);
			DrawTexture(this->TravelTicketButtonLocked, 50, 590, WHITE);
			DrawTexture(this->TravelButtonLocked, 176, 590, WHITE);
		}
	}
}