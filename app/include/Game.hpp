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
#include <Menu.hpp>

class Game
{
public:
	Game();
	~Game();
private:
	GameManager* gameManager = GameManager::GetInstance();
	MapManager* mapManager = new MapManager();
	std::vector<std::string> missions = { "Clean the sea", "Captcha solver", "Clean the street", "Get rich", "Hangman", "Mail packager" };
	std::string currentCountry = mapManager->getPlayerCountry();
	std::string ClickedCountryName;
	void ChooseCountryAnimation(bool displayText);
	void ChooseStartingCountry();
	void DrawCountryHUD();
	void DrawCurrentCountryHUD();
	void LoadDynamicTextures();
	void showMissions();
	void PassiveIncome();
	
	int tickets = 1;
	int ClickedCountryPrice;
	int balance = 500;
	float time = 0;
	
	bool FinishedMissions[3] = {0, 0, 0};
	bool ClickedCountryUnlocked;
	bool chosen = false;



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

};