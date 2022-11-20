#pragma once
#include <GameManager.hpp>
#include <MapManager.hpp>
#include <SeaMinigame.hpp>
#include <GetRich.hpp>
#include <CaptchaSolver.hpp>
#include <PollutedStreet.hpp>
#include <Hangman.hpp>
#include <GetRich.hpp>
#include <MailPackager.hpp>
#include <random>

class Game
{
public:
	Game();
	~Game();
private:
	GameManager* gameManager = GameManager::GetInstance();
	MapManager* mapManager = new MapManager();
	void ChooseCountryAnimation(bool displayText);
	void ChooseStartingCountry();
	bool chosen = false;
	void DrawCountryHUD();
	void DrawCurrentCountryHUD();
	std::string ClickedCountryName;
	bool ClickedCountryUnlocked;
	int ClickedCountryPrice;
	void LoadDynamicTextures();
	void showMissions();
	std::string currentCountry = mapManager->getPlayerCountry();
	std::vector<std::string> missions = { "Clean the sea", "Captcha solver", "Clean the street", "Get rich", "Hangman", "Mail packager" };

	int balance = 500;
	void PassiveIncome();
	float time = 0;

	int tickets = 1;

	Texture2D CountryHUDTexture;
	Texture2D CurrentCountryHUD;

	Texture2D Checkbox;
	Texture2D Checkmark;

	Texture2D UnlockButton;
	Texture2D UnlockButtonHover;
	Texture2D UnlockButtonLocked;
	Texture2D Unlocked;

	Texture2D TravelButton;
	Texture2D TravelButtonHover;
	Texture2D TravelButtonLocked;

	Texture2D TravelTicketButton;
	Texture2D TravelTicketButtonHover;
	Texture2D TravelTicketButtonLocked;

	Texture2D MissionContainer;
	Texture2D MissionContainerHover;
	Texture2D CompletedMission;

	bool FinishedMissions[3] = {0, 0, 0};
};