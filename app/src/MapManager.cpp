#include <MapManager.hpp>
#include <iostream>
MapManager::MapManager()
{
	gameManager->LoadScene(gameManager->SCENE::GAME, {"Map.png"}, {{gameManager->getScreenSize().x / 2 - this->mapWidth / 2, gameManager->getScreenSize().y / 2 - this->mapHeight / 2}});
	while (gameManager->currentScene == gameManager->SCENE::GAME && !gameManager->getShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLUE);
		this->m_mousePos = GetMousePosition();
		gameManager->Update();
		DrawTexture(this->toggler, 0, 300, WHITE);
		DrawTexture(this->ship, 8, 370, WHITE);
		ToggleWaypoints();
		TogglePorts();
		EndDrawing();
	}
}

MapManager::~MapManager()
{
	
}

void MapManager::DrawWaypoints(std::vector<Vector2> waypoints, std::vector<float> scale)
{
	for (size_t i = 0; i < waypoints.size(); i++)
	{
		DrawTextureEx(this->waypoint, waypoints[i],0 , scale[i], WHITE);
		if (CheckCollisionPointRec(this->m_mousePos, { waypoints[i].x, waypoints[i].y, this->waypoint.width * scale[i], this->waypoint.height * scale[i] }))
		{
			SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
		}
	}
}

void MapManager::ToggleWaypoints() {
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
		DrawWaypoints(this->waypoints, this->scale);
	}
}

void MapManager::DrawPorts(std::vector<Vector2> ports, std::vector<float> portScale) {
	for (size_t i = 0; i < ports.size(); i++)
	{
		DrawTextureEx(this->ship, ports[i], 0, portScale[i], WHITE);
		if (CheckCollisionPointRec(this->m_mousePos, { ports[i].x, ports[i].y, this->toggler.width * portScale[i], this->toggler.height * portsScale[i] }))
		{
			SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
		}
	}
};

void MapManager::TogglePorts() {
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
		DrawPorts(this->ports, this->portsScale);
	}
}