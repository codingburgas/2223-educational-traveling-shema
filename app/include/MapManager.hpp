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
	void TogglePorts();
	void DrawPorts(std::vector<Vector2> ports, std::vector<float> scale);
	Texture2D waypoint = LoadTexture("./assets/Waypoint.png");
	Texture2D toggler = LoadTexture("./assets/Waypoint.png");
	Texture2D ship = LoadTexture("./assets/Ship.png");
	/* Greenland, Iceland, England, Ireland, Norway, Sweeden, Germany, Bulgaria, France, Spain, Portugal, Netherlands, 
	Belgium, Finland, Romania, Greece, Italy, Ukraine, Belarus, Poland, Turkey, Czhech, Austria, Switzerland, Slovenia, Croatia, Serbia, 
	Macedonia, Albania, Bosnia, Montenegro, Hungary, Slovakia, Lithuania, Latvia, Estonia, Denmark, Moldova */

	//DO SLOVENIQ SUM
	std::vector<Vector2> waypoints = { {350,50} , {430,220} , {600,580} , {480,535} , {820,400} , {940,350} , {830,650} , {1200,830} , {700,750} , {500,900} , 
		{350,915} , {760,620} , {740,665} , {1100,340} , {1200,750} , {1170,930} , {870,830} , {1300,660} , {1200,550} , {1030,600} , {1400,880} , {950,670} , 
		{950,730} , {800,750} , {955,775} , {1000,785} , {1100,810} , {1150,860} , {1110,880} , {1040,820} , {1090,855} , {1050,760} , {1050,700} , {1130,520} , 
		{1140,480} , {1150,435} , {1300,450} , {840,510} , {1290,710} };
	std::vector<float> scale = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.7, 0.75, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.75, 0.75, 1, 1, 0.75, 0.5, 0.5, 1, 0.75, 1, 0.75, 0.75, 1, 0.75, 0.75 };
	std::vector<Vector2> ports = { {430, 95}, {490, 250}, {645, 630}, {450, 590}, {800, 460}, {950, 510}, {820, 590}, {1310, 840}, {580, 685}, {470, 820}, 
		{350, 870}, {705, 650}, {730, 620}, {1060, 400}, {1310, 790}, {1210, 1000}, {915, 900}, {1430, 750}, {}, {1020, 550}, {1400, 840}, {}, {}, {}, {1045, 865}, {980, 840}, 
		{}, {}, {1110, 920}, {}, {}, {}, {1070, 530}, {1060, 480}, {1100, 450}, {820, 550}, {}
	};
	std::vector<float> portsScale = { 1, 1, 1, 1, 1, 1, 1, 0.8, 0.75, 1, 1, 0.75, 0.6, 1, 0.75, 1, 1, 0.8, 0, 0.8, 1, 0, 0, 0, 0.65, 0.75, 0, 0, 0.75, 0, 0, 0, 0.75, 0.75, 0.75, 0.75, 0 };
	Vector2 m_mousePos = { 0, 0 };
	bool toggleWaypoints = true;
	bool togglePorts = false;
	const int mapWidth = 1920;
	const int mapHeight = 1080;
};