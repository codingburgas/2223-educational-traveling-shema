#include <MapManager.hpp>
#include <iostream>
MapManager::MapManager()
{
	gameManager->LoadScene(gameManager->SCENE::GAME, {"Map.png"}, {{gameManager->screenSize().x / 2 - this->mapWidth / 2, gameManager->screenSize().y / 2 - this->mapHeight / 2}});
	while (gameManager->currentScene == gameManager->SCENE::GAME && !gameManager->getShouldClose())
	{
		ClearBackground(BLUE);
		gameManager->Update();
	}
	std::cout << gameManager->currentScene;
}

MapManager::~MapManager()
{
	
}