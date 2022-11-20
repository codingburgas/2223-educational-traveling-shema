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
	if(this->getChosenCountry().empty()) {
		DrawWaypoints(this->waypoints);
	}
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

void MapManager::ToggleWaypoints(Texture2D checkbox, Texture2D checkmark, Vector2 checkboxSize, Vector2 checkmarkSize)
{
	DrawTextureEx(checkbox, { gameManager->GetScreenSize().x - 65, 416 }, 0, 1, WHITE);
	if (CheckCollisionPointRec(GetMousePosition(), { gameManager->GetScreenSize().x - 65, 416, float(checkboxSize.x), float(checkboxSize.y) }))
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
		DrawTextureEx(checkmark, { gameManager->GetScreenSize().x - 65, 416 }, 0, 1, WHITE);
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

void MapManager::TogglePorts(Texture2D checkbox, Texture2D checkmark, Vector2 checkboxSize, Vector2 checkmarkSize) {
	DrawTextureEx(checkbox, { gameManager->GetScreenSize().x - 65, 447 }, 0, 1, WHITE);
	if (CheckCollisionPointRec(GetMousePosition(), { gameManager->GetScreenSize().x - 65, 447, float(checkboxSize.x), float(checkboxSize.y) }))
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
		DrawTextureEx(checkmark, { gameManager->GetScreenSize().x - 65, 447 }, 0, 1, WHITE);
	}
}
Vector2 MapManager::GetMapSize()
{
	return { this->mapWidth, this->mapHeight };
}

std::string MapManager::getChosenCountry()
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

void MapManager::TravelToCountry(std::string destination)
{
	for (size_t i = 0; i < this->waypoints.size(); i++)
	{
		if (this->waypoints[i].name == destination && this->waypoints[i].name != playerCountry)
		{
			Texture2D Bus = LoadTexture((gameManager->getAssetPath() + "bus.png").c_str());
			Texture2D Plane = LoadTexture((gameManager->getAssetPath() + "plane.png").c_str());
			Vector2 VehiclePos = { gameManager->GetScreenSize().x / 2 - MeasureText("Traveling...", 150) / 2,  gameManager->GetScreenSize().y / 2 };
			gameManager->StartTimer(3);
			HideCursor();
			while (VehiclePos.x <= gameManager->GetScreenSize().x / 2 + MeasureText("Traveling...", 150) / 3)
			{
				BeginDrawing();
				ClearBackground(BLACK);
				DrawText("Traveling...", gameManager->GetScreenSize().x / 2 - MeasureText("Traveling...", 150) / 2, gameManager->GetScreenSize().y / 2 - 150, 150, WHITE);
				if (waypoints[i].name == "Greenland" || waypoints[i].name == "Iceland" || waypoints[i].name == "Ireland" || playerCountry == "Greenland" || playerCountry == "Iceland" || playerCountry == "Ireland") DrawTextureEx(Plane, VehiclePos, 0, 0.3, WHITE);
				else DrawTextureEx(Bus, VehiclePos, 0, 0.3, WHITE);
				VehiclePos.x += 200 * GetFrameTime();
				EndDrawing();
			}
			this->playerCountry = waypoints[i].name;
			this->playerPos = waypoints[i].pos;
			ShowCursor();
			UnloadTexture(Bus);
			UnloadTexture(Plane);
		}
	}
}

std::string MapManager::getPlayerCountry()
{
	return this->playerCountry;
}