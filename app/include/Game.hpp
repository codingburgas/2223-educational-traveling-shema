#pragma once
#include <GameManager.hpp>
#include <MapManager.hpp>

class Game
{
public:
	Game();
	~Game();
private:
	GameManager *gameManager = GameManager::getInstance();
	MapManager *mapManager = new MapManager();
	
};