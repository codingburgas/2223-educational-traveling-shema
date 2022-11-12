#include <MapManager.hpp>
#include <iostream>
MapManager::MapManager()
{
	gameManager->LoadScene(gameManager->SCENE::GAME, {"Map.png"}, {{0,0}});
	while (gameManager->currentScene == gameManager->SCENE::GAME && !gameManager->getShouldClose())
	{
		ClearBackground(BLUE);
		gameManager->Update();
	}
	std::cout << gameManager->currentScene;
}