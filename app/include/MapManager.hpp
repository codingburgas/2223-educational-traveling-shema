#pragma once
#include <GameManager.hpp>
#include <Menu.hpp>
class MapManager
{
public:
	MapManager();
	~MapManager();

private:
	GameManager *gameManager = GameManager::getInstance();
	
};