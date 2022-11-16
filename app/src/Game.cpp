#include <Game.hpp>

Game::Game()
{
	gameManager->LoadScene(gameManager->SCENE::GAME, { "Map.png" }, { {gameManager->getScreenSize().x / 2 - mapManager->getMapSize().x / 2, gameManager->getScreenSize().y / 2 - mapManager->getMapSize().y / 2} });
	for (int i = 0; i < 5; i++) i % 2 == 0 ? ChooseCountryAnimation(true) : ChooseCountryAnimation(false);
	while (gameManager->currentScene == gameManager->SCENE::GAME && !gameManager->getShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLUE);
		gameManager->Update();
		mapManager->UpdateMap();
		if (!this->isCountryChosen) DrawText("Choose a country!", gameManager->getScreenSize().x / 2 - MeasureText("Choose a country!", 60) / 2, 50, 60, RED);
		EndDrawing();
	}
}

Game::~Game()
{

}

void Game::ChooseCountryAnimation(bool displayText)
{
	gameManager->StartTimer(0.5);
	while (!gameManager->TimerEnded()) {
		BeginDrawing();
		ClearBackground(BLUE);
		gameManager->Update();
		if (displayText) {
			DrawRectangle(0, 0, gameManager->getScreenSize().x, gameManager->getScreenSize().y, Fade(BLACK, 0.5f));
			DrawText("Choose a country", gameManager->getScreenSize().x / 2 - MeasureText("Choose a country", 100) / 2, gameManager->getScreenSize().y / 2 - 20 / 2, 100, RED);
		} else DrawRectangle(0, 0, gameManager->getScreenSize().x, gameManager->getScreenSize().y, Fade(BLACK, 0.5f));
		EndDrawing();
	}
}