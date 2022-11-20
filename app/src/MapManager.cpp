#include <MapManager.hpp>

MapManager::MapManager()
{
}

MapManager::~MapManager()
{

}

void MapManager::UpdateMap()
{
	// Updates the map
	this->m_MousePos = GetMousePosition();
	if (this->getChosenCountry().empty()) DrawWaypoints(this->m_Waypoints);
}

void MapManager::DrawWaypoints(std::vector<COUNTRY> waypoints)
{
	// Draws the waypoints
	for (size_t i = 0; i < waypoints.size(); i++)
	{
		if (this->m_ChosenCountry.empty()) DrawTextureEx(this->m_Waypoint, waypoints[i].pos, 0, waypoints[i].scale, WHITE);
		else DrawTextureEx(waypoints[i].unlocked ? this->m_UnlockedWaypoint : this->m_LockedWaypoint, waypoints[i].pos, 0, waypoints[i].scale, WHITE);
	}
}

MapManager::COUNTRY MapManager::IsWaypointClicked()
{
	// Checks if a waypoint was clicked
	for (size_t i = 0; i < m_Waypoints.size(); i++)
	{
		if (CheckCollisionPointRec(this->m_MousePos, { this->m_Waypoints[i].pos.x, this->m_Waypoints[i].pos.y, this->m_Waypoint.width * this->m_Waypoints[i].scale, this->m_Waypoint.height * this->m_Waypoints[i].scale }))
		{
			SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) return this->m_Waypoints[i];
		}
	}
	return COUNTRY{};
}

void MapManager::ToggleWaypoints(Texture2D checkbox, Texture2D checkmark, Vector2 checkboxSize, Vector2 checkmarkSize)
{
	// Toggles the waypoints
	DrawTextureEx(checkbox, { gameManager->GetScreenSize().x - 65, 416 }, 0, 1, WHITE);
	if (CheckCollisionPointRec(GetMousePosition(), { gameManager->GetScreenSize().x - 65, 416, float(checkboxSize.x), float(checkboxSize.y) }))
	{
		SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			this->m_ToggleWaypoints = !this->m_ToggleWaypoints;
		}
	}
	if (this->m_ToggleWaypoints)
	{
		DrawWaypoints(this->m_Waypoints);
		DrawTextureEx(checkmark, { gameManager->GetScreenSize().x - 65, 416 }, 0, 1, WHITE);
	}
}

void MapManager::DrawPorts(std::vector<COUNTRY> ports)
{
	// Draws the ports
	for (size_t i = 0; i < ports.size(); i++)
	{
		DrawTextureEx(this->m_Ship, ports[i].pos, 0, ports[i].scale, WHITE);
	}
}
MapManager::COUNTRY MapManager::IsPortClicked()
{
	// Checks if a port was clicked
	for (size_t i = 0; i < m_Ports.size(); i++)
	{
		if (CheckCollisionPointRec(this->m_MousePos, { this->m_Ports[i].pos.x, this->m_Ports[i].pos.y, this->m_Ship.width * this->m_Ports[i].scale, this->m_Ship.height * this->m_Ports[i].scale }))
		{
			SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				return m_Ports[i];
			}
		}
	}
	return COUNTRY{};
}

void MapManager::TogglePorts(Texture2D checkbox, Texture2D checkmark, Vector2 checkboxSize, Vector2 checkmarkSize) {
	// Toggles the ports
	DrawTextureEx(checkbox, { gameManager->GetScreenSize().x - 65, 447 }, 0, 1, WHITE);
	if (CheckCollisionPointRec(GetMousePosition(), { gameManager->GetScreenSize().x - 65, 447, float(checkboxSize.x), float(checkboxSize.y) }))
	{
		SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			this->m_TogglePorts = !this->m_TogglePorts;
		}
	}
	if (this->m_TogglePorts)
	{
		DrawPorts(this->m_Ports);
		DrawTextureEx(checkmark, { gameManager->GetScreenSize().x - 65, 447 }, 0, 1, WHITE);
	}
}
Vector2 MapManager::GetMapSize()
{
	return { this->c_MapWidth, this->c_MapHeight };
}

std::string MapManager::getChosenCountry()
{
	return this->m_ChosenCountry;
}

void MapManager::SetChosenCountry(std::string countryName, Vector2 pos)
{
	// Sets the chosen country
	this->m_ChosenCountry = countryName;
	UnlockCountry(countryName);
	this->m_PlayerCountry = this->m_ChosenCountry;
	this->m_PlayerPos = pos;
}

void MapManager::UnlockCountry(std::string countryName)
{
	// Unlocks the country
	for (size_t i = 0; i < this->m_Waypoints.size(); i++)
	{
		if (this->m_Waypoints[i].name == countryName)
		{
			this->m_Waypoints[i].unlocked = 1;
			this->m_UnlockedCountries++;
		}
	}
	for (size_t i = 0; i < this->m_Ports.size(); i++)
	{
		if (this->m_Ports[i].name == countryName)
		{
			this->m_Ports[i].unlocked = 1;
		}
	}
}

void MapManager::TravelToCountry(std::string destination)
{
	// Travels to the country
	for (size_t i = 0; i < this->m_Waypoints.size(); i++)
	{
		if (this->m_Waypoints[i].name == destination && this->m_Waypoints[i].name != this->m_PlayerCountry)
		{
			Texture2D Bus = LoadTexture((gameManager->GetAssetPath() + "Game/bus.png").c_str());
			Texture2D Plane = LoadTexture((gameManager->GetAssetPath() + "Game/plane.png").c_str());
			Vector2 VehiclePos = { gameManager->GetScreenSize().x / 2 - MeasureTextEx(gameManager->m_Impact, "Traveling...", 150, 1).x / 2,  gameManager->GetScreenSize().y / 2 };
			gameManager->StartTimer(3);
			HideCursor();
			while (VehiclePos.x <= gameManager->GetScreenSize().x / 2 + MeasureTextEx(gameManager->m_Impact, "Traveling...", 150, 1).x / 3)
			{
				BeginDrawing();
				ClearBackground(BLACK);
				DrawTextEx(gameManager->m_Impact, "Traveling...", { gameManager->GetScreenSize().x / 2 - MeasureTextEx(gameManager->m_Impact, "Traveling...", 150, 1).x / 2, gameManager->GetScreenSize().y / 2 - 150 }, 150, 1, WHITE);
				if (this->m_Waypoints[i].name == "Greenland" || this->m_Waypoints[i].name == "Iceland" || this->m_Waypoints[i].name == "Ireland" || this->m_PlayerCountry == "Greenland" || this->m_PlayerCountry == "Iceland" || this->m_PlayerCountry == "Ireland") DrawTextureEx(Plane, VehiclePos, 0, 0.3, WHITE);
				else DrawTextureEx(Bus, VehiclePos, 0, 0.3, WHITE);
				VehiclePos.x += 200 * GetFrameTime();
				EndDrawing();
			}
			this->m_PlayerCountry = this->m_Waypoints[i].name;
			this->m_PlayerPos = this->m_Waypoints[i].pos;
			ShowCursor();
			UnloadTexture(Bus);
			UnloadTexture(Plane);
		}
	}
}

std::string MapManager::getPlayerCountry()
{
	// Returns the player's country
	return this->m_PlayerCountry;
}

int MapManager::GetUnlockedCountries()
{
	// Returns the amount of unlocked countries
	return this->m_UnlockedCountries;
}

int MapManager::GetCountriesSize()
{
	// Returns the amount of countries
	return this->m_Waypoints.size();
}

void MapManager::UnlockAllWaypoints()
{
	if (IsKeyPressed(KEY_K)) {
		for (size_t i = 0; i < this->m_Waypoints.size(); i++)
		{
			this->m_Waypoints[i].unlocked = 1;
		}
		this->m_UnlockedCountries = this->m_Waypoints.size();
	}
}