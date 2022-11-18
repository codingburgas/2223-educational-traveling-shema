#pragma once
#include <GameManager.hpp>
#include <MapManager.hpp>

class Game
{
public:
	Game();
	~Game();
private:
	GameManager *gameManager = GameManager::GetInstance();
	MapManager *mapManager = new MapManager();
	void ChooseCountryAnimation(bool displayText);
	void ChooseStartingCountry();
};