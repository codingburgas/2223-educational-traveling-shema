#include <Game.hpp>

Game::Game()
{
	gameManager->LoadScene(gameManager->SCENE::GAME, { "Map.png" }, { {gameManager->getScreenSize().x / 2 - mapManager->getMapSize().x / 2, gameManager->getScreenSize().y / 2 - mapManager->getMapSize().y / 2}});
	while (gameManager->currentScene == gameManager->SCENE::GAME && !gameManager->getShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLUE);
		gameManager->Update();
		mapManager->UpdateMap();
		
		EndDrawing();
	}
}

Game::~Game()
{
	
}