#include <MapManager.hpp>
#include <iostream>
MapManager::MapManager()
{
	gameManager->LoadScene(gameManager->SCENE::GAME, {"Map.png"}, {{gameManager->screenSize().x / 2 - this->mapWidth / 2, gameManager->screenSize().y / 2 - this->mapHeight / 2}});
	Texture2D waypoint = LoadTexture("./assets/Waypoint.png");
	while (gameManager->currentScene == gameManager->SCENE::GAME && !gameManager->getShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLUE);
		gameManager->Update();
		DrawWaypoints(waypoint);
		EndDrawing();
	}
}

MapManager::~MapManager()
{
	
}

void MapManager::DrawWaypoints(Texture2D waypoint)
{
	ClearBackground(BLUE);
	DrawTexture(waypoint, 350, 50, WHITE); // Greenland
	DrawTexture(waypoint, 450, 220, WHITE); // Iceland
	DrawTexture(waypoint, 605, 605, WHITE); // England
	DrawTexture(waypoint, 480, 560, WHITE); // Ireland
	DrawTexture(waypoint, 800, 430, WHITE); // Norway
	DrawTexture(waypoint, 940, 350, WHITE); // Sweden
	DrawTexture(waypoint, 830, 650, WHITE); // Germany
	DrawTexture(waypoint, 1200, 830, WHITE); // Bulgaria
	DrawTexture(waypoint, 700, 750, WHITE); // France
	DrawTexture(waypoint, 500, 900, WHITE); // Spain
	DrawTexture(waypoint, 350, 915, WHITE); // Portugal 
	DrawTextureEx(waypoint, { 750, 625 }, 0, 0.75, WHITE); // Netherlands
	DrawTextureEx(waypoint, { 730, 660 }, 0, 0.75, WHITE); // Belgium
	DrawTexture(waypoint, 1100, 340, WHITE); // Finland
	DrawTexture(waypoint, 1200, 750, WHITE); // Romania
	DrawTexture(waypoint, 1170, 930, WHITE); // Greece
	DrawTexture(waypoint, 870, 830, WHITE); // Italy
	DrawTexture(waypoint, 1300, 660, WHITE); // Ukraine
	DrawTexture(waypoint, 1200, 550, WHITE); // Belarus
	DrawTexture(waypoint, 1030, 600, WHITE); // Poland
	DrawTexture(waypoint, 1400, 880, WHITE); // Turkey
	DrawTexture(waypoint, 950, 670, WHITE); // Czech R
	DrawTexture(waypoint, 950, 730, WHITE); // Austria
	DrawTexture(waypoint, 800, 750, WHITE); // Switzerland
	DrawTextureEx(waypoint, { 955, 775 }, 0, 0.75, WHITE); // Slovenia
	DrawTextureEx(waypoint, { 1000, 785 }, 0, 0.75, WHITE); // Croatia
	DrawTexture(waypoint, 1100, 810, WHITE); // Serbia
	DrawTexture(waypoint, 1150, 860, WHITE); // Macedonia
	DrawTextureEx(waypoint, { 1110, 900 }, 0, 0.75, WHITE); // Albania
	DrawTexture(waypoint, 1040, 830, WHITE); // Bosnia
	DrawTextureEx(waypoint, { 1090, 855 }, 0, 0.5, WHITE); // Montenegro
	DrawTexture(waypoint, 1050, 760, WHITE); // Hungary
	DrawTextureEx(waypoint, { 1050, 700 }, 0, 0.75, WHITE); // Slovakia
	DrawTexture(waypoint, 1130, 520, WHITE); // Lithuania
	DrawTextureEx(waypoint, { 1140, 480 }, 0, 0.75, WHITE); // Latvia
	DrawTextureEx(waypoint, { 1135, 435 }, 0, 0.75, WHITE); // Estonia
	DrawTexture(waypoint, 1300, 450, WHITE); // Russia
	DrawTextureEx(waypoint, { 830, 540 }, 0, 0.75, WHITE); // Denmark
	DrawTextureEx(waypoint, { 1290, 710 }, 0, 0.75, WHITE); // Moldova





}