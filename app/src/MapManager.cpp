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
		DrawTextureEx(waypoints[i].unlocked ? this->UnlockedWaypoint : this->LockedWaypoint, waypoints[i].pos, 0, waypoints[i].scale, WHITE);
	}
}

MapManager::Country MapManager::isWaypointClicked()
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
MapManager::Country MapManager::isPortClicked()
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
Vector2 MapManager::getMapSize()
{
	return { this->mapWidth, this->mapHeight };
}

std::string MapManager::getChosenCountry()
{
	return this->chosenCountry;
}

void MapManager::setChosenCountry(std::string countryName)
{
	this->chosenCountry = countryName;
	unlockCountry(countryName);
}

void MapManager::unlockCountry(std::string countryName)
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