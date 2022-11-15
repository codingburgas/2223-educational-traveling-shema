#include <MapManager.hpp>
#include <iostream>
MapManager::MapManager()
{
	gameManager->LoadScene(gameManager->SCENE::GAME, { "Map.png" }, { {gameManager->getScreenSize().x / 2 - this->mapWidth / 2, gameManager->getScreenSize().y / 2 - this->mapHeight / 2} });
	while (gameManager->currentScene == gameManager->SCENE::GAME && !gameManager->getShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLUE);
		this->m_mousePos = GetMousePosition();
		gameManager->Update();
		ToggleWaypoints();
		TogglePorts();
		EndDrawing();
	}
}

MapManager::~MapManager()
{

}

void MapManager::DrawWaypoints(std::vector<Coordinate> waypoints)
{
	for (size_t i = 0; i < waypoints.size(); i++)
	{
		DrawTextureEx(this->waypoint, waypoints[i].pos, 0, waypoints[i].scale, WHITE);
		if (CheckCollisionPointRec(this->m_mousePos, { waypoints[i].pos.x, waypoints[i].pos.y, this->waypoint.width * waypoints[i].scale, this->waypoint.height * waypoints[i].scale }))
		{
			SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
		}
	}
}

void MapManager::ToggleWaypoints() {
	DrawTexture(this->waypoint, 0, 300, WHITE);
	if (CheckCollisionPointRec(this->m_mousePos, { 0, 300, 50, 50 }))
	{
		SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			this->toggleWaypoints = !this->toggleWaypoints;
		}
	}
	if (this->toggleWaypoints)
	{
		DrawWaypoints(this->waypoints);
	}
}

void MapManager::DrawPorts(std::vector<Coordinate> ports) {
	for (size_t i = 0; i < ports.size(); i++)
	{
		DrawTextureEx(this->ship, ports[i].pos, 0, ports[i].scale, WHITE);
		if (CheckCollisionPointRec(this->m_mousePos, { ports[i].pos.x, ports[i].pos.y, this->ship.width * ports[i].scale, this->ship.height * ports[i].scale }))
		{
			SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
		}
	}
};

void MapManager::TogglePorts() {
	DrawTexture(this->ship, 8, 370, WHITE);
	if (CheckCollisionPointRec(this->m_mousePos, { 8, 370, 40, 40 }))
	{
		SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			this->togglePorts = !this->togglePorts;
		}
	}
	if (this->togglePorts)
	{
		DrawPorts(this->ports);
	}
}