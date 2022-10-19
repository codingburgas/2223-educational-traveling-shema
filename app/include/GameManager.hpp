#pragma once
#include "raylib.h"

class GameManager 
{
public:
	GameManager();
	~GameManager();
	void Update();
	bool getShouldClose();

private:
	int screenWidth = 800;
	int screenHeight = 450;
	bool shouldClose = WindowShouldClose();
};