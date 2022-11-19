#pragma once
#include <iostream>
#include <GameManager.hpp>

class MapManager
{
private:
	struct Country
	{
		std::string name;
		Vector2 pos;
		float scale;
		bool unlocked;
	};
public:
	MapManager();
	~MapManager();
	Vector2 GetMapSize();
	void UpdateMap();
	std::string GetChosenCountry();
	void SetChosenCountry(std::string countryName, Vector2 pos);
	Country IsWaypointClicked();
	Country IsPortClicked();
	void UnlockCountry(std::string countryName);
	void TravelToCountry(std::string destination);
	std::string getPlayerCountry();
private:
	GameManager* gameManager = GameManager::GetInstance();
	void DrawWaypoints(std::vector<Country> waypoints);
	void DrawPorts(std::vector<Country> ports);
	void ToggleWaypoints();
	void TogglePorts();
	Texture2D waypoint = LoadTexture((gameManager->getAssetPath() + "Waypoint.png").c_str());
	Texture2D LockedWaypoint = LoadTexture((gameManager->getAssetPath() + "LockedWaypoint.png").c_str());
	Texture2D UnlockedWaypoint = LoadTexture((gameManager->getAssetPath() + "UnlockedWaypoint.png").c_str());
	Texture2D ship = LoadTexture((gameManager->getAssetPath() + "Ship.png").c_str());
	std::vector<Country> waypoints = { {"Greenland", {350,50} , 1, 1}, {"Iceland", {430,220} , 1, 0} , {"England", {600,580} , 1, 0} , {"Ireland", {480,535} , 1, 0} , {"Norway", {820,400} , 1, 0} , {"Sweden", {940,350} , 1, 0} , {"Germany", {830,650} , 1, 0} , {"Bulgaria", {1200,830} , 1, 0} , {"France", {700,750} , 1, 0} , {"Spain", {500,900} , 1, 0} ,
		{"Portugal", {350,915} , 1, 0} , {"Netherlands", {760,620} , 0.7, 0} , {"Belgium", {740,665} , 0.75, 0} , {"Finland", {1100,340} , 1, 0} , {"Romania", {1200,750} , 1, 0} , {"Greece", {1170,930} , 1, 0} , {"Italy", {870,830} , 1, 0} , {"Ukraine", {1300,660} , 1, 0} , {"Belarus", {1200,550} , 1, 0} , {"Poland", {1030,600} , 1, 0} , {"Turkey", {1400,910} , 1, 0} , {"Czechia", {950,670} , 1, 0} ,
		{"Austria", {950,730} , 1, 0} , {"Switzerland", {800,750} , 1, 0} , {"Slovenia", {955,775} , 0.75, 0} , {"Croatia", {1000,785} , 0.75, 0} , {"Serbia", {1100,810} , 1, 0} , {"Macedonia", {1150,860} , 1, 0} , {"Albania", {1110,880} , 0.75, 0} , {"Bosnia", {1040,820} , 0.75, 0} , {"Montenegro", {1090,855} , 0.5, 0} , {"Hungary", {1050,760} , 0.5, 0} , {"Slovakia", {1050,700} , 1, 0} , {"Lithuania", {1130,520} , 0.75, 0} ,
		{"Latvia", {1140,480} , 0.75, 0} , {"Estonia", {1150,435} , 0.75, 0} , {"Russia", {1300,450} , 1, 0} , {"Denmark", {840,510} , 1, 0} , {"Moldova", {1290,710} , 0.75, 0} };
	std::vector<Country> ports = { {"Greenland", {430,95} , 1, 0} , {"Iceland", {490,250} , 1, 0} , {"England", {645,630} , 1, 0} , {"Ireland", {450,590} , 1, 0} , {"Norway", {800,460} , 1, 0} , {"Sweden", {950,510} , 1, 0} , {"Germany", {820,590} , 1, 0} , {"Bulgaria", {1310,840}, 0.8, 0 } , {"France", {580,685} , 0.75, 0 } , {"Spain", {470,820}, 1, 0} ,
		{"Portugal", {350,870}, 1, 0}, {"Netherlands", {730,620} , 0.6, 0 }, {"Belgium", {705,650} , 0.75, 0 }, {"Finland", {1060,400} , 1, 0} , {"Romania", {1310,790} , 0.75, 0 } , {"Greece", {1210,1000} , 1, 0} , {"Italy", {915,900} , 1, 0} , {"Ukraine", {1430,750} , 0.8, 0 } , {"Belarus", {0,0} , 0, 0 } , {"Poland", {1020,550} , 0.8, 0 } , {"Turkey", {1400,840} , 1, 0} , {"Czechia", {0,0} , 0, 0 } , {"Austria", {0,0} , 0, 0 } , {"Switzerland", {0,0} , 0, 0 } ,
		{"Bosnia", {1045,865} , 0.65, 0 } , {"Croatia", {980,840} , 0.75, 0 } , {"Serbia", {0,0} , 0, 0 } , {"Macedonia", {0,0} , 0, 0 } , {"Albania", {1110,940} , 0.75, 0 } , {"Slovenia", {0,0} , 0, 0 } , {"Montenegro", {0,0} , 0, 0 } , {"Hungary", {0,0} , 0, 0 } , {"Lithuania", {1070,530} , 0.75, 0 } , {"Latvia", {1060,480} , 0.75, 0 } , {"Estonia", {1100,450} , 0.75, 0 } , {"Denmark", {820,550} , 0.75, 0 } , {"Denmark", {0,0} , 0, 0 } 
	};
	Vector2 m_mousePos = { 0, 0 };
	bool toggleWaypoints = true;
	bool togglePorts = false;
	const float mapWidth = 1920;
	const float mapHeight = 1080;
	std::string chosenCountry;
	std::string playerCountry;
	Vector2 playerPos;
};