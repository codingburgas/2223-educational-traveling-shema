#include <Game.hpp>

Game::Game()
{
	// Loads the given scene using the method from the game manager instance
	gameManager->LoadScene(gameManager->SCENE::GAME, { "Game/Map.png" }, { {gameManager->GetScreenSize().x / 2 - mapManager->GetMapSize().x / 2, gameManager->GetScreenSize().y / 2 - mapManager->GetMapSize().y / 2} });
	LoadDynamicTextures();
	this->m_CountryHUDTexture = LoadTexture((gameManager->GetAssetPath() + "Game/CountryHUD.png").c_str());
	for (int i = 0; i < 5; i++) i % 2 == 0 ? ChooseCountryAnimation(true) : ChooseCountryAnimation(false);
	while (gameManager->CurrentScene == gameManager->SCENE::GAME && !gameManager->GetShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLUE);
		gameManager->Update();
		mapManager->UpdateMap();
		this->PassiveIncome();
		this->DrawCountryHUD();
		this->DrawCurrentCountryHUD();
		mapManager->UnlockAllWaypoints();
		EndDrawing();
		if (mapManager->getChosenCountry().empty()) ChooseStartingCountry();
		
		// If escape is pressed, the player will be returned to the main menu
		if (IsKeyPressed(KEY_ESCAPE))
		{
			delete this;
			Menu* menu = new Menu();
			break;
		}

		// If the player has no more countries, the game will end
		if (mapManager->GetUnlockedCountries() == mapManager->GetCountriesSize()) {
			this->GameOver();
			delete this;
			Menu* menu = new Menu();
			break;
		}
	}
}

Game::~Game()
{
	// Unloads all the textures used in the game
	UnloadTexture(this->m_CountryHUDTexture);
	UnloadTexture(this->m_CurrentCountryHUD);
	UnloadTexture(this->m_Checkbox);
	UnloadTexture(this->m_Checkmark);
	UnloadTexture(this->m_UnlockButton);
	UnloadTexture(this->m_UnlockButtonHover);
	UnloadTexture(this->m_UnlockButtonLocked);
	UnloadTexture(this->m_Unlocked);
	UnloadTexture(this->m_TravelButton);
	UnloadTexture(this->m_TravelButtonHover);
	UnloadTexture(this->m_TravelButtonLocked);
	UnloadTexture(this->m_TravelTicketButton);
	UnloadTexture(this->m_TravelTicketButtonHover);
	UnloadTexture(this->m_TravelTicketButtonLocked);
	UnloadTexture(this->m_MissionContainer);
	UnloadTexture(this->m_MissionContainerHover);
	UnloadTexture(this->m_CompletedMission);
	UnloadTexture(this->m_LockedMissionContainer);
	UnloadTexture(this->m_FinishScreen);
}

void Game::LoadDynamicTextures()
{
	// Loads all the textures used in the game
	this->m_CountryHUDTexture = LoadTexture((gameManager->GetAssetPath() + "Game/CountryHUD.png").c_str());
	this->m_CurrentCountryHUD = LoadTexture((gameManager->GetAssetPath() + "Game/CurrentCountryHUD.png").c_str());

	this->m_Checkbox = LoadTexture((gameManager->GetAssetPath() + "Game/Checkbox.png").c_str());
	this->m_Checkmark = LoadTexture((gameManager->GetAssetPath() + "Game/Checkmark.png").c_str());

	this->m_UnlockButton = LoadTexture((gameManager->GetAssetPath() + "Game/UnlockButton.png").c_str());
	this->m_UnlockButtonHover = LoadTexture((gameManager->GetAssetPath() + "Game/UnlockButtonHover.png").c_str());
	this->m_UnlockButtonLocked = LoadTexture((gameManager->GetAssetPath() + "Game/UnlockButtonLocked.png").c_str());
	this->m_Unlocked = LoadTexture((gameManager->GetAssetPath() + "Game/Unlocked.png").c_str());

	this->m_TravelButton = LoadTexture((gameManager->GetAssetPath() + "Game/TravelButton.png").c_str());
	this->m_TravelButtonHover = LoadTexture((gameManager->GetAssetPath() + "Game/TravelButtonHover.png").c_str());
	this->m_TravelButtonLocked = LoadTexture((gameManager->GetAssetPath() + "Game/TravelButtonLocked.png").c_str());

	this->m_TravelTicketButton = LoadTexture((gameManager->GetAssetPath() + "Game/TravelTicketButton.png").c_str());
	this->m_TravelTicketButtonHover = LoadTexture((gameManager->GetAssetPath() + "Game/TravelTicketButtonHover.png").c_str());
	this->m_TravelTicketButtonLocked = LoadTexture((gameManager->GetAssetPath() + "Game/TravelTicketButtonLocked.png").c_str());

	this->m_MissionContainer = LoadTexture((gameManager->GetAssetPath() + "Game/MissionContainer.png").c_str());
	this->m_MissionContainerHover = LoadTexture((gameManager->GetAssetPath() + "Game/MissionContainerHover.png").c_str());
	this->m_CompletedMission = LoadTexture((gameManager->GetAssetPath() + "Game/CompletedMission.png").c_str());
	this->m_LockedMissionContainer = LoadTexture((gameManager->GetAssetPath() + "Game/LockedMissionContainer.png").c_str());
	this->m_FinishScreen = LoadTexture((gameManager->GetAssetPath() + "Game/FinishScreen.png").c_str());
}

void Game::ChooseCountryAnimation(bool displayText)
{
	// Displays the animation for choosing a country
	gameManager->StartTimer(0.5);
	while (!gameManager->TimerEnded())
	{
		BeginDrawing();
		ClearBackground(BLUE);
		gameManager->Update();
		if (displayText)
		{
			DrawRectangle(0, 0, gameManager->GetScreenSize().x, gameManager->GetScreenSize().y, Fade(BLACK, 0.5f));
			DrawTextEx(gameManager->m_Impact, "Choose a country!", { gameManager->GetScreenSize().x / 2 - MeasureTextEx(gameManager->m_Impact, "Choose a country!", 100, 1).x / 2, gameManager->GetScreenSize().y / 2 - 20 / 2 }, 100, 1, RED);
		}
		else DrawRectangle(0, 0, gameManager->GetScreenSize().x, gameManager->GetScreenSize().y, Fade(BLACK, 0.5f));
		EndDrawing();
	}
}

void Game::ChooseStartingCountry()
{
	// Displays the animation for choosing a starting country
	BeginDrawing();
	ClearBackground(BLUE);
	DrawTextEx(gameManager->m_Impact, "Choose a country!", { gameManager->GetScreenSize().x / 2 - MeasureTextEx(gameManager->m_Impact, "Choose a country!", 100, 1).x / 2 }, 100, 1, RED);
	gameManager->StartTimer(0.1);
	if (!mapManager->IsWaypointClicked().name.empty() && !this->m_Chosen)
	{
		std::string clickedCountry = mapManager->IsWaypointClicked().name;

		Texture2D ModalWindow = LoadTexture((gameManager->GetAssetPath() + "Game/CountryModal.png").c_str());
		Texture2D YesButton = LoadTexture((gameManager->GetAssetPath() + "Game/YesButton.png").c_str());
		Texture2D YesButtonHover = LoadTexture((gameManager->GetAssetPath() + "Game/YesButtonHover.png").c_str());
		Texture2D NoButton = LoadTexture((gameManager->GetAssetPath() + "Game/NoButton.png").c_str());
		Texture2D NoButtonHover = LoadTexture((gameManager->GetAssetPath() + "Game/NoButtonHover.png").c_str());

		// Displays the modal window
		while (!this->m_Chosen)
		{
			BeginDrawing();
			ClearBackground(BLUE);
			gameManager->Update();

			DrawRectangle(0, 0, gameManager->GetScreenSize().x, gameManager->GetScreenSize().y, Fade(BLACK, 0.5f));
			DrawTextureEx(ModalWindow, { gameManager->GetScreenSize().x / 2 - ModalWindow.width / 2, gameManager->GetScreenSize().y / 2 - ModalWindow.height / 2 }, 0, 1, WHITE);

			DrawTextEx(gameManager->m_Impact, clickedCountry.c_str(), { gameManager->GetScreenSize().x / 2 - MeasureTextEx(gameManager->m_Impact, (clickedCountry).c_str()  , 80, 1).x / 2, gameManager->GetScreenSize().y / 2 - 30 }, 80, 1, RED);
			DrawTextEx(gameManager->m_Impact, "?", { gameManager->GetScreenSize().x / 2 + MeasureTextEx(gameManager->m_Impact, clickedCountry.c_str(), 80, 1).x / 2, gameManager->GetScreenSize().y / 2 - 30 }, 80, 0, BLACK);
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
					this->m_Chosen = true;
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
	// Draws the HUD for the country
	if (!mapManager->IsWaypointClicked().name.empty())
	{
		this->m_ClickedCountryName = mapManager->IsWaypointClicked().name;
		this->m_ClickedCountryUnlocked = mapManager->IsWaypointClicked().unlocked;
		this->m_ClickedCountryPrice = mapManager->IsWaypointClicked().price;
	}
	if (!m_ClickedCountryName.empty())
	{
		DrawTexture(this->m_CountryHUDTexture, 0, 250, WHITE);
		DrawTextEx(gameManager->m_Impact, TextToUpper(m_ClickedCountryName.c_str()), { 50, 290 }, 50, 2, BLACK);
		this->ShowClickedCountryMissions();

		// Checks if the clicked country is unlocked
		if (this->m_ClickedCountryUnlocked)
		{
			if (this->m_Tickets >= 1 && mapManager->getPlayerCountry() != this->m_ClickedCountryName)
			{
				DrawTexture(this->m_TravelTicketButton, 50, 590, WHITE);
				if (CheckCollisionPointRec(GetMousePosition(), { 50, 590, float(this->m_TravelTicketButton.width), float(this->m_TravelTicketButton.height) }))
				{
					SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
					DrawTexture(this->m_TravelTicketButton, 50, 590, Fade(BLACK, 0.5f));
					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
					{
						this->m_Tickets--;
						mapManager->TravelToCountry(this->m_ClickedCountryName);
					}
				}
			}
			else DrawTexture(this->m_TravelTicketButtonLocked, 50, 590, WHITE); // If it is not unlocked then it will display the locked texture

			// If the country is unlocked and the player has enough tickets then it will display the travel button
			if (this->m_Balance >= 185 && mapManager->getPlayerCountry() != this->m_ClickedCountryName)
			{
				DrawTexture(this->m_TravelButton, 176, 590, WHITE);
				if (CheckCollisionPointRec(GetMousePosition(), { 176, 590, float(this->m_TravelButton.width), float(this->m_TravelButton.height) }))
				{
					SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
					DrawTexture(this->m_TravelButton, 176, 590, Fade(BLACK, 0.5f));
					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
					{
						this->m_Balance -= 185;
						mapManager->TravelToCountry(this->m_ClickedCountryName);
					}
				}
			}
			else DrawTexture(this->m_TravelButtonLocked, 176, 590, WHITE);

			DrawTextEx(gameManager->m_Impact, "Already unlocked", { 117, 658 }, 25, 1, GREEN);
			DrawTexture(this->m_Unlocked, 50, 685, WHITE);
		}
		else
		{
			if (this->m_Balance >= this->m_ClickedCountryPrice)
			{
				DrawTexture(this->m_UnlockButton, 50, 685, WHITE);
				if (CheckCollisionPointRec(GetMousePosition(), { 50, 685, float(this->m_UnlockButton.width), float(this->m_UnlockButton.height) }))
				{
					SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
					DrawTexture(this->m_UnlockButtonHover, 50, 685, WHITE);
					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
					{
						this->m_Balance -= this->m_ClickedCountryPrice;
						mapManager->UnlockCountry(this->m_ClickedCountryName);
						this->m_ClickedCountryUnlocked = true;
					}
				}
			}
			else DrawTexture(this->m_UnlockButtonLocked, 50, 685, WHITE);

			DrawTextEx(gameManager->m_Impact, std::to_string(this->m_ClickedCountryPrice).c_str(), { 117, 658 }, 25, 1, BLACK);
			DrawTexture(this->m_TravelTicketButtonLocked, 50, 590, WHITE);
			DrawTexture(this->m_TravelButtonLocked, 176, 590, WHITE);
		}
	}
}

void Game::DrawCurrentCountryHUD() {
	if (!mapManager->getPlayerCountry().empty())
	{
		DrawTextureEx(this->m_CurrentCountryHUD, { gameManager->GetScreenSize().x - this->m_CurrentCountryHUD.width, 250 }, 0, 1, WHITE);
		DrawTextEx(gameManager->m_Impact, TextToUpper(mapManager->getPlayerCountry().c_str()), { gameManager->GetScreenSize().x - 274, 290 }, 50, 2, BLACK);
		DrawTextEx(gameManager->m_Impact, std::to_string(this->m_Balance).c_str(), { gameManager->GetScreenSize().x - 240, 380 }, 25, 1, BLACK);
		DrawTextEx(gameManager->m_Impact, std::to_string(this->m_Tickets).c_str(), { gameManager->GetScreenSize().x - 80, 380 }, 25, 1, BLACK);
		this->ShowMissions();
		mapManager->TogglePorts(this->m_Checkbox, this->m_Checkmark, { float(this->m_Checkbox.width), float(this->m_Checkbox.height) }, { float(this->m_Checkmark.width), float(this->m_Checkmark.height) });
		mapManager->ToggleWaypoints(this->m_Checkbox, this->m_Checkmark, { float(this->m_Checkbox.width), float(this->m_Checkbox.height) }, { float(this->m_Checkmark.width), float(this->m_Checkmark.height) });
	}
}

void Game::PassiveIncome()
{
	this->m_Time += GetFrameTime();
	if (this->m_Time > 1)
	{
		this->m_Balance++;
		this->m_Time = 0;
	}
	if (IsKeyDown(KEY_S) && IsKeyDown(KEY_H) && IsKeyDown(KEY_E) && IsKeyDown(KEY_M) && IsKeyDown(KEY_A))
	{
		this->m_Balance += 1000;
		this->m_Tickets += 100;
	}
}

void Game::ShowMissions() {
	float missionHeight = 560;
	if (!mapManager->getPlayerCountry().empty())
	{
		if (this->m_CurrentCountry != mapManager->getPlayerCountry())
		{
			this->m_CurrentCountry = mapManager->getPlayerCountry();
			auto rng = std::default_random_engine{};
			std::shuffle(std::begin(this->m_Missions), std::end(this->m_Missions), rng);
			missionHeight = 560;
			m_FinishedMissions[0] = 0;
			m_FinishedMissions[1] = 0;
			m_FinishedMissions[2] = 0;
		}
		for (size_t i = 0; i < 3; i++)
		{
			if (m_FinishedMissions[i]) DrawTextureEx(this->m_CompletedMission, { gameManager->GetScreenSize().x - this->m_MissionContainer.width - 50, missionHeight }, 0, 1, WHITE);
			else {
				DrawTextureEx(this->m_MissionContainer, { gameManager->GetScreenSize().x - this->m_MissionContainer.width - 50, missionHeight }, 0, 1, WHITE);
				if (CheckCollisionPointRec(GetMousePosition(), { gameManager->GetScreenSize().x - this->m_MissionContainer.width - 50, missionHeight, float(this->m_MissionContainer.width), float(this->m_MissionContainer.height) })) {
					SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
					DrawTextureEx(this->m_MissionContainerHover, { gameManager->GetScreenSize().x - this->m_MissionContainer.width - 50, missionHeight }, 0, 1, WHITE);
					if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
					{
						if (m_Missions[i] == "Clean the sea")
						{
							SeaMinigame* seaMinigame = new SeaMinigame();
							seaMinigame->UpdateGame();
							m_Balance += seaMinigame->GetPayout();
							delete seaMinigame;
							m_FinishedMissions[i] = true;
							if (rand() % 6 == 1) m_Tickets++;
						}
						else if (m_Missions[i] == "Captcha solver")
						{
							CaptchaSolver* captchaSolver = new CaptchaSolver();
							captchaSolver->UpdateGame();
							m_Balance += captchaSolver->GetPayout();
							delete captchaSolver;
							m_FinishedMissions[i] = true;
							if (rand() % 6 == 1) m_Tickets++;
						}
						else if (m_Missions[i] == "Clean the street")
						{
							PollutedStreet* pollutedStreet = new PollutedStreet();
							pollutedStreet->UpdateGame();
							m_Balance += pollutedStreet->GetPayout();
							delete pollutedStreet;
							m_FinishedMissions[i] = true;
							if (rand() % 6 == 1) m_Tickets++;
						}
						else if (m_Missions[i] == "Get rich")
						{
							GetRich* getRich = new GetRich();
							getRich->UpdateGame();
							m_Balance += getRich->GetPayout();
							delete getRich;
							m_FinishedMissions[i] = true;
							if (rand() % 6 == 1) m_Tickets++;
						}
						else if (m_Missions[i] == "Hangman")
						{
							Hangman* hangman = new Hangman();
							hangman->UpdateGame();
							m_Balance += hangman->GetPayout();
							delete hangman;
							m_FinishedMissions[i] = true;
							if (rand() % 6 == 1) m_Tickets++;
						}
						else if (m_Missions[i] == "Mail packager")
						{
							MailPackager* mailPackager = new MailPackager();
							mailPackager->UpdateGame();
							m_Balance += mailPackager->GetPayout();
							delete mailPackager;
							m_FinishedMissions[i] = true;
							if (rand() % 6 == 1) m_Tickets++;
						}
					}
				}
			}
			DrawTextEx(gameManager->m_Impact, this->m_Missions[i].c_str(), { gameManager->GetScreenSize().x - this->m_MissionContainer.width - 45, missionHeight }, 25, 1, WHITE);
			missionHeight += 40;
		}
	}
}

void Game::ShowClickedCountryMissions()
{
	float MissionHeight = 400;
	MissionHeight = 400;

	for (size_t i = 0; i < 3; i++)
	{
		DrawTextureEx(this->m_LockedMissionContainer, { 50, MissionHeight }, 0, 1, WHITE);
		DrawTextEx(gameManager->m_Impact, "HIDDEN MISSION", { 55, MissionHeight }, 25, 1, WHITE);
		MissionHeight += 40;
	}
}

void Game::GameOver()
{
	gameManager->StartTimer(5);
	while (!gameManager->TimerEnded()) {
		BeginDrawing();
		ClearBackground(BLUE);
		gameManager->Update();
		DrawTextureEx(this->m_FinishScreen, { gameManager->GetScreenSize().x / 2 - this->m_FinishScreen.width / 2, gameManager->GetScreenSize().y / 2 - this->m_FinishScreen.height / 2 }, 0, 1, WHITE);
		EndDrawing();
	}
}