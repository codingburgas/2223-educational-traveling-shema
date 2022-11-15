#pragma once
#include <iostream>
#include <GameManager.hpp>

class MapManager
{
public:
	MapManager();
	~MapManager();
	Vector2 getMapSize();
	void UpdateMap();
private:
	struct Country
	{
		std::string name;
		Vector2 pos;
		float scale;
	};
	GameManager* gameManager = GameManager::getInstance();
	void DrawWaypoints(std::vector<Country> waypoints);
	void DrawPorts(std::vector<Country> ports);
	void ToggleWaypoints();
	void TogglePorts();
	Texture2D waypoint = LoadTexture((gameManager->getAssetPath() + "Waypoint.png").c_str());
	Texture2D ship = LoadTexture((gameManager->getAssetPath() + "Ship.png").c_str());
	std::vector<Country> waypoints = { {"Greenland", {350,50} , 1}, {"Iceland", {430,220} , 1} , {"England", {600,580} , 1} , {"Ireland", {480,535} , 1} , {"Norway", {820,400} , 1} , {"Sweden", {940,350} , 1} , {"Germany", {830,650} , 1} , {"Bulgaria", {1200,830} , 1} , {"France", {700,750} , 1} , {"Spain", {500,900} , 1} ,
		{"Portugal", {350,915} , 1} , {"The Netherlands", {760,620} , 0.7} , {"Belgium", {740,665} , 0.75} , {"Finland", {1100,340} , 1} , {"Romania", {1200,750} , 1} , {"Greece", {1170,930} , 1} , {"Italy", {870,830} , 1} , {"Ukraine", {1300,660} , 1} , {"Belarus", {1200,550} , 1} , {"Poland", {1030,600} , 1} , {"Turkey", {1400,880} , 1} , {"Czech Republic", {950,670} , 1} ,
		{"Austria", {950,730} , 1} , {"Switzerland", {800,750} , 1} , {"Slovenia", {955,775} , 0.75} , {"Croatia", {1000,785} , 0.75} , {"Serbia", {1100,810} , 1} , {"North Macedonia", {1150,860} , 1} , {"Albania", {1110,880} , 1} , {"Bosnia and Herzegovina", {1040,820} , 0.75} , {"Montenegro", {1090,855} , 0.5} , {"Hungary", {1050,760} , 0.5} , {"Slovakia", {1050,700} , 1} , {"Lithuania", {1130,520} , 0.75} ,
		{"Latvia", {1140,480} , 0.75} , {"Estonia", {1150,435} , 1} , {"Russia", {1300,450} , 0.75} , {"Denmark", {840,510} , 1} , {"Moldova", {1290,710} , 0.75} };
	std::vector<Country> ports = { {"Greenland", {430,95} , 1 } , {"Iceland", {490,250} , 1 } , {"England", {645,630} , 1 } , {"Ireland", {450,590} , 1 } , {"Norway", {800,460} , 1 } , {"Sweden", {950,510} , 1 } , {"Germany", {820,590} , 1 } , {"Bulgaria", {1310,840} , 0.8 } , {"France", {580,685} , 0.75 } , {"Spain", {470,820} , 1 } ,
		{"Portugal", {350,870} , 1 } , {"Belgium", {705,650} , 0.75 } , {"The Netherlands", {730,620} , 0.6 } , {"Finland", {1060,400} , 1 } , {"Romania", {1310,790} , 0.75 } , {"Greece", {1210,1000} , 1 } , {"Italy", {915,900} , 1 } , {"Ukraine", {1430,750} , 0.8 } , {"Belarus", {0,0} , 0 } , {"Poland", {1020,550} , 0.8 } , {"Turkey", {1400,840} , 1 } , {"Czech Republic", {0,0} , 0 } , {"Austria", {0,0} , 0 } , {"Switzerland", {0,0} , 0 } ,
		{"Bosnia and Herzegovina", {1045,865} , 0.65 } , {"Croatia", {980,840} , 0.75 } , {"Serbia", {0,0} , 0 } , {"North Macedonia", {0,0} , 0 } , {"Albania", {1110,920} , 0.75 } , {"Slovenia", {0,0} , 0 } , {"Montenegro", {0,0} , 0 } , {"Hungary", {0,0} , 0 } , {"Lithuania", {1070,530} , 0.75 } , {"Latvia", {1060,480} , 0.75 } , {"Estonia", {1100,450} , 0.75 } , {"Denmark", {820,550} , 0.75 } , {"Denmark", {0,0} , 0 } 
	};
	Vector2 m_mousePos = { 0, 0 };
	bool toggleWaypoints = true;
	bool togglePorts = false;
	const float mapWidth = 1920;
	const float mapHeight = 1080;
};