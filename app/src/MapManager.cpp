#include <MapManager.hpp>
#include <iostream>
MapManager::MapManager()
{
	gameManager->LoadScene(gameManager->SCENE::GAME, {"Map.png"}, {{gameManager->screenSize().x / 2 - this->mapWidth / 2, gameManager->screenSize().y / 2 - this->mapHeight / 2}});
	while (gameManager->currentScene == gameManager->SCENE::GAME && !gameManager->getShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLUE);
		this->m_mousePos = GetMousePosition();
		gameManager->Update();
		DrawTexture(this->toggler, 0, 300, WHITE);
		ToggleWaypoints();
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