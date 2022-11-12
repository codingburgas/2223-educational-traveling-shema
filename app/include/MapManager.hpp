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
	const int mapWidth = 1920;
	const int mapHeight = 1080;
};