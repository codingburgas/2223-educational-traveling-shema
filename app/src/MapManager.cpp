#include <MapManager.hpp>

MapManager::MapManager()
{
}

MapManager::~MapManager()
{

}

void MapManager::UpdateMap()
{	
	this->m_mousePos = GetMousePosition();
	ToggleWaypoints();
	TogglePorts();
}

void MapManager::DrawWaypoints(std::vector<Country> waypoints)
{
	for (size_t i = 0; i < waypoints.size(); i++)
	{
		if (this->chosenCountry.empty()) DrawTextureEx(this->waypoint, waypoints[i].pos, 0, waypoints[i].scale, WHITE);
		else DrawTextureEx(waypoints[i].unlocked ? this->UnlockedWaypoint : this->LockedWaypoint, waypoints[i].pos, 0, waypoints[i].scale, WHITE);
	}
}

MapManager::Country MapManager::IsWaypointClicked()
{
	for (size_t i = 0; i < waypoints.size(); i++)
	{
		if (CheckCollisionPointRec(this->m_mousePos, { waypoints[i].pos.x, waypoints[i].pos.y, this->waypoint.width * waypoints[i].scale, this->waypoint.height * waypoints[i].scale }))
		{
			SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				return waypoints[i];
			}
		}
	}
	return Country{};
}

void MapManager::ToggleWaypoints() 
{
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

void MapManager::DrawPorts(std::vector<Country> ports) 
{
	for (size_t i = 0; i < ports.size(); i++)
	{
		DrawTextureEx(this->ship, ports[i].pos, 0, ports[i].scale, WHITE);
	}
}
MapManager::Country MapManager::IsPortClicked()
{
	for (size_t i = 0; i < ports.size(); i++)
	{
		if (CheckCollisionPointRec(this->m_mousePos, { ports[i].pos.x, ports[i].pos.y, this->ship.width * ports[i].scale, this->ship.height * ports[i].scale }))
		{
			SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				return ports[i];
			}
		}
	}
	return Country{};
}

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
Vector2 MapManager::GetMapSize()
{
	return { this->mapWidth, this->mapHeight };
}

std::string MapManager::GetChosenCountry()
{
	return this->chosenCountry;
}

void MapManager::SetChosenCountry(std::string countryName, Vector2 pos)
{
	this->chosenCountry = countryName;
	UnlockCountry(countryName);
	playerCountry = chosenCountry;
	playerPos = pos;
}

void MapManager::UnlockCountry(std::string countryName)
{
	for (size_t i = 0; i < waypoints.size(); i++)
	{
		if (waypoints[i].name == countryName)
		{
			waypoints[i].unlocked = 1;
		}
	}
	for (size_t i = 0; i < ports.size(); i++)
	{
		if (ports[i].name == countryName)
		{
			ports[i].unlocked = 1;
		}
	}
}

void MapManager::TravelToCountry()
{
	if (!this->IsWaypointClicked().name.empty())
	{
		for (size_t i = 0; i < this->waypoints.size(); i++)
		{
			if (this->waypoints[i].name == this->IsWaypointClicked().name && this->waypoints[i].unlocked && this->waypoints[i].name!=playerCountry)
			{
				Texture2D Bus = LoadTexture((gameManager->getAssetPath() + "bus.png").c_str());
				Vector2 BusPos = { gameManager->GetScreenSize().x / 2 - MeasureText("Traveling...", 150) / 2,  gameManager->GetScreenSize().y / 2 };
				gameManager->StartTimer(3);
				HideCursor();
				while (!gameManager->TimerEnded()) 
				{
					BeginDrawing();
					ClearBackground(BLACK);
					DrawText("Traveling...", gameManager->GetScreenSize().x / 2 - MeasureText("Traveling...", 150) / 2, gameManager->GetScreenSize().y/2 - 150, 150, WHITE);
					double time = GetTime();
					while ((GetTime() - time) <= 0.01)
					{
						DrawTextureEx(Bus, BusPos, 0, 0.3, WHITE);
					}
					BusPos.x += 4.5;
					EndDrawing();
				}
				this->playerCountry = waypoints[i].name;
				this->playerPos = waypoints[i].pos;
				ShowCursor();
				UnloadTexture(Bus);
			}
		}
	}
}