#pragma once
#include <GameManager.hpp>
#include <Menu.hpp>
class MapManager
{
public:
	MapManager();
	~MapManager();

private:
	GameManager *gameManager = GameManager::getInstance();
	void DrawWaypoints(std::vector<Vector2> waypoints, std::vector<float> scale);
	void ToggleWaypoints();
	Texture2D waypoint = LoadTexture("./assets/Waypoint.png");
	Texture2D toggler = LoadTexture("./assets/Waypoint.png");
	std::vector<Vector2> waypoints = { {350,50} , {450,220} , {605,605} , {480,560} , {800,430} , {940,350} , {830,650} , {1200,830} , {700,750} , {500,900} , {350,915} , {750,625} , {730,660} , {1100,340} , {1200,750} , {1170,930} , {870,830} , {1300,660} , {1200,550} , {1030,600} , {1400,880} , {950,670} , {950,730} , {800,750} , {955,775} , {1000,785} , {1100,810} , {1150,860} , {1110,900} , {1040,830} , {1090,855} , {1050,760} , {1050,700} , {1130,520} , {1140,480} , {1135,435} , {1300,450} , {830,540} , {1290,710} };
	std::vector<float> scale = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.75, 0.75, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.75, 0.75, 1, 1, 0.75, 1, 0.5, 1, 0.75, 1, 0.75, 0.75, 1, 0.75, 0.75 };
	Vector2 m_mousePos = { 0, 0 };
	bool toggleWaypoints = true;
	const int mapWidth = 1920;
	const int mapHeight = 1080;
};