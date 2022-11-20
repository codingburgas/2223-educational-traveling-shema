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
		this->balance = 5000000;
		gameManager->Update();
		mapManager->UpdateMap();
		this->PassiveIncome();
		this->DrawCountryHUD();
		this->DrawCurrentCountryHUD();
		EndDrawing();
		if (mapManager->getChosenCountry().empty()) {
			ChooseStartingCountry();
		}
		if (IsKeyPressed(257))
		{
			//SeaMinigame* seaMinigame = new SeaMinigame();
			//seaMinigame->UpdateGame();
			//delete seaMinigame;
			GetRich* getRich = new GetRich();
			getRich->UpdateGame();
			delete getRich;
		}
	}
}

Game::~Game()
{
	UnloadTexture(CountryHUDTexture);
	UnloadTexture(CurrentCountryHUD);
	UnloadTexture(Checkbox);
	UnloadTexture(Checkmark);
	UnloadTexture(UnlockButton);
	UnloadTexture(UnlockButtonHover);
	UnloadTexture(UnlockButtonLocked);
	UnloadTexture(Unlocked);
	UnloadTexture(TravelButton);
	UnloadTexture(TravelButtonHover);
	UnloadTexture(TravelButtonLocked);
	UnloadTexture(TravelTicketButton);
	UnloadTexture(TravelTicketButtonHover);
	UnloadTexture(TravelTicketButtonLocked);
	UnloadTexture(MissionContainer);
	UnloadTexture(MissionContainerHover);
	UnloadTexture(CompletedMission);
}

void Game::LoadDynamicTextures()
{
	this->CountryHUDTexture = LoadTexture((gameManager->getAssetPath() + "CountryHUD.png").c_str());
	this->CurrentCountryHUD = LoadTexture((gameManager->getAssetPath() + "CurrentCountryHUD.png").c_str());

	this->Checkbox = LoadTexture((gameManager->getAssetPath() + "Checkbox.png").c_str());
	this->Checkmark = LoadTexture((gameManager->getAssetPath() + "Checkmark.png").c_str());

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

	this->MissionContainer = LoadTexture((gameManager->getAssetPath() + "MissionContainer.png").c_str());
	this->MissionContainerHover = LoadTexture((gameManager->getAssetPath() + "MissionContainerHover.png").c_str());
	this->CompletedMission = LoadTexture((gameManager->getAssetPath() + "CompletedMission.png").c_str());
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
		}
		else DrawRectangle(0, 0, gameManager->GetScreenSize().x, gameManager->GetScreenSize().y, Fade(BLACK, 0.5f));
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
			DrawTextureEx(ModalWindow, { gameManager->GetScreenSize().x / 2 - ModalWindow.width / 2, gameManager->GetScreenSize().y / 2 - ModalWindow.height / 2 }, 0, 1, WHITE);

			DrawTextEx(gameManager->impact, clickedCountry.c_str(), { gameManager->GetScreenSize().x / 2 - MeasureTextEx(gameManager->impact, (clickedCountry).c_str()  , 80, 1).x / 2, gameManager->GetScreenSize().y / 2 - 30 }, 80, 1, RED);
			DrawTextEx(gameManager->impact, "?", { gameManager->GetScreenSize().x / 2 + MeasureTextEx(gameManager->impact, clickedCountry.c_str(), 80, 1).x / 2, gameManager->GetScreenSize().y / 2 - 30 }, 80, 0, BLACK);
			SetMouseCursor(MOUSE_CURSOR_DEFAULT);
			DrawTexture(YesButton, 753, 657, WHITE);
			if (CheckCollisionPointRec(GetMousePosition(), { 753, 657, float(YesButton.width), float(YesButton.height) }))
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

void Game::DrawCountryHUD()
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
			if (this->balance >= this->ClickedCountryPrice)
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
						this->ClickedCountryUnlocked = true;
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

void Game::DrawCurrentCountryHUD() {
	if (!mapManager->getPlayerCountry().empty()) {
		DrawTextureEx(this->CurrentCountryHUD, { gameManager->GetScreenSize().x - this->CurrentCountryHUD.width, 250 }, 0, 1, WHITE);
		DrawTextEx(gameManager->impact, TextToUpper(mapManager->getPlayerCountry().c_str()), { gameManager->GetScreenSize().x - 274, 290 }, 50, 2, BLACK);
		DrawTextEx(gameManager->impact, std::to_string(this->balance).c_str(), { gameManager->GetScreenSize().x - 240, 380 }, 25, 1, BLACK);
		this->showMissions();
		mapManager->TogglePorts(this->Checkbox, this->Checkmark, { float(this->Checkbox.width), float(this->Checkbox.height) }, { float(this->Checkmark.width), float(this->Checkmark.height) });
		mapManager->ToggleWaypoints(this->Checkbox, this->Checkmark, { float(this->Checkbox.width), float(this->Checkbox.height) }, { float(this->Checkmark.width), float(this->Checkmark.height) });
	}
}

void Game::PassiveIncome()
{
	this->time += GetFrameTime();
	if (this->time > 1)
	{
		this->balance++;
		this->time = 0;
	}
}

void Game::showMissions() {
	float missionHeight = 560;
	bool finishedMissions[3] = { 0, 0, 0 };
	if (!mapManager->getPlayerCountry().empty()) {
		std::cout << this->missions[0] << std::endl;
		if (this->currentCountry != mapManager->getPlayerCountry()) {
			this->currentCountry = mapManager->getPlayerCountry();
			auto rng = std::default_random_engine{};
			std::shuffle(std::begin(this->missions), std::end(this->missions), rng);
			missionHeight = 560;
		}
		for (size_t i = 0; i < 3; i++) {
			if (finishedMissions[i]) {
				DrawTextureEx(this->CompletedMission, { gameManager->GetScreenSize().x - this->MissionContainer.width - 50, missionHeight }, 0, 1, WHITE);
			}
			else {
				DrawTextureEx(this->MissionContainer, { gameManager->GetScreenSize().x - this->MissionContainer.width - 50, missionHeight }, 0, 1, WHITE);
				if (CheckCollisionPointRec(GetMousePosition(), { gameManager->GetScreenSize().x - this->MissionContainer.width - 50, missionHeight, float(this->MissionContainer.width), float(this->MissionContainer.height) })) {
					SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
					DrawTextureEx(this->MissionContainerHover, { gameManager->GetScreenSize().x - this->MissionContainer.width - 50, missionHeight }, 0, 1, WHITE);
				}
			}
			DrawTextEx(gameManager->impact, this->missions[i].c_str(), { gameManager->GetScreenSize().x - this->MissionContainer.width - 45, missionHeight }, 25, 1, WHITE);
			missionHeight += 40;
		}
	}
}