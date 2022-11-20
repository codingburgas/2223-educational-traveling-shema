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
	// Gets the Game manager instance
	GameManager* gameManager = GameManager::GetInstance();
	// Gets the Map manager instance
	MapManager* mapManager = new MapManager();
	std::vector<std::string> m_Missions = { "Clean the sea", "Captcha solver", "Clean the street", "Get rich", "Hangman", "Mail packager" };
	std::string m_CurrentCountry = mapManager->getPlayerCountry();
	std::string m_ClickedCountryName;
	void ChooseCountryAnimation(bool displayText);
	void ChooseStartingCountry();
	void DrawCountryHUD();
	void DrawCurrentCountryHUD();
	void LoadDynamicTextures();
	void ShowMissions();
	void ShowClickedCountryMissions();
	void PassiveIncome();
	void GameOver();
	
	int m_Tickets = 1;
	int m_ClickedCountryPrice;
	int m_Balance = 500;
	float m_Time = 0;
	
	bool m_FinishedMissions[3] = {0, 0, 0};
	bool m_ClickedCountryUnlocked;
	bool m_Chosen = false;

	Texture2D m_CountryHUDTexture;
	Texture2D m_CurrentCountryHUD;

	Texture2D m_Checkbox;
	Texture2D m_Checkmark;

	Texture2D m_UnlockButton;
	Texture2D m_UnlockButtonHover;
	Texture2D m_UnlockButtonLocked;
	Texture2D m_Unlocked;

	Texture2D m_TravelButton;
	Texture2D m_TravelButtonHover;
	Texture2D m_TravelButtonLocked;

	Texture2D m_TravelTicketButton;
	Texture2D m_TravelTicketButtonHover;
	Texture2D m_TravelTicketButtonLocked;

	Texture2D m_MissionContainer;
	Texture2D m_MissionContainerHover;
	Texture2D m_CompletedMission;
	Texture2D m_LockedMissionContainer;

	Texture2D m_FinishScreen;
};