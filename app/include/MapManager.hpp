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
	Texture2D waypoint = LoadTexture((gameManager->getAssetPath() + "Waypoint.png").c_str());
	Texture2D toggler = waypoint;
	Texture2D ship = LoadTexture((gameManager->getAssetPath() + "Ship.png").c_str());
	std::vector<Vector2> waypoints = { {350,50} , {430,220} , {600,580} , {480,535} , {820,400} , {940,350} , {830,650} , {1200,830} , {700,750} , {500,900} , 
		{350,915} , {760,620} , {740,665} , {1100,340} , {1200,750} , {1170,930} , {870,830} , {1300,660} , {1200,550} , {1030,600} , {1400,880} , {950,670} , 
		{950,730} , {800,750} , {955,775} , {1000,785} , {1100,810} , {1150,860} , {1110,880} , {1040,820} , {1090,855} , {1050,760} , {1050,700} , {1130,520} , 
		{1140,480} , {1150,435} , {1300,450} , {840,510} , {1290,710} };
	std::vector<float> scale = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.7, 0.75, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.75, 0.75, 1, 1, 0.75, 0.5, 0.5, 1, 0.75, 1, 0.75, 0.75, 1, 0.75, 0.75 };
	std::vector<Vector2> ports = { {430, 95}, {490, 250}, {645, 630}, {450, 590}, {800, 460}, {950, 510}, {820, 590}, {1310, 840}, {580, 685}, {470, 820}, 
		{350, 870}, {705, 650}, {730, 620}, {1060, 400}, {1310, 790}, {1210, 1000}, {915, 900}, {1430, 750}, {}, {1020, 550}, {1400, 840}, {}, {}, {}, {1045, 865}, {980, 840}, 
		{}, {}, {1110, 920}, {}, {}, {}, {1070, 530}, {1060, 480}, {1100, 450}, {820, 550}, {}
	};
	std::vector<float> portsScale = { 1, 1, 1, 1, 1, 1, 1, 0.8, 0.75, 1, 1, 0.75, 0.6, 1, 0.75, 1, 1,
		0.8, 0, 0.8, 1, 0, 0, 0, 0.65, 0.75, 0, 0, 0.75, 0, 0, 0, 0.75, 0.75, 0.75, 0.75, 0 };
	Vector2 m_mousePos = { 0, 0 };
	bool toggleWaypoints = true;
	bool togglePorts = false;
	const int mapWidth = 1920;
	const int mapHeight = 1080;
};
	/*
	Greenland - {350, 50}, 1, {430, 95}, 1
	Iceland - {430, 220}, 1, {490, 250}, 1
	England - {600, 580}, 1, {645, 630}, 1
	Ireland - {480, 535}, 1, {450, 590}, 1
	Norway - {820, 400}, 1, {800, 460}, 1
	Sweeden - {940, 350}, 1, {950, 510}, 1
	Germany - {830, 650}, 1, {820, 590}, 1
	Bulgaria - {1200, 830}, 1, {1310, 840}, 0.8
	France - {700, 750}, 1, {580, 685}, 0.75
	Spain - {500, 900}, 1, {470, 820}, 1
	Portugal - {350, 915}, 1, {350, 870}, 1
	Netherlands - {760, 620}, 0.7, {705, 650}, 0.75
	Belgium - {740, 665}, 0.75, {730, 620}, 0.6
	Finland - {1100, 340}, 1, {1060, 400}, 1
	Romania - {1200, 750}, 1, {1310, 790}, 0.75
	Greece - {1170, 930}, 1, {1210, 1000}, 1
	Italy - {870, 830}, 1, {915, 900}, 1
	Ukraine - {1300, 660}, 1, {1430, 750}, 0.8
	Belarus - {1200, 550}, 1, {}, 0
	Poland - {1030, 600}, 1, {1020, 550}, 0.8
	Turkey - {1400, 880}, 1, {1400, 840}, 1
	Czhech - {950, 670}, 1, {}, 0
	Austria - {950, 730}, 1, {}, 0
	Switzerland - {800, 750}, 1, {}, 0
	Slovenia - {955, 775}, 0.75, {1045, 865}, 0.65
	Croatia - {1000, 785}, 0.75, {980, 840}, 0.75
	Serbia - {1100, 810}, 1, {}, 0
	Macedonia - {1150, 860}, 1, {}, 0
	Albania - {1110, 880}, 0.75, {1110, 920}, 0.75
	Bosnia - {1040, 820}, 0.5, {}, 0
	Montenegro - {1090, 855}, 0.5, {}, 0
	Hungary - {1050, 760}, 1, {}, 0
	Slovakia - {1050, 700}, 1, {}, 0
	Lithuania - {1130, 520}, 1, {1070, 530}, 0.75
	Latvia - {1140, 480}, 1, {1060, 480}, 0.75
	Estonia - {1150, 435}, 1, {1100, 450}, 0.75
	Denmark - {1300, 450}, 1, {820, 550}, 0.75
	Moldova - {840, 510}, 0.75, {}, 0
	*/