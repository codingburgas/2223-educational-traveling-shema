#include <raylib.h>
#include "Menu.h"

using namespace std;

Menu::Menu(int width, int height, std::string title)
{
	InitWindow(width, height, title.c_str());
	SetWindowState(FLAG_VSYNC_HINT);
}

Menu::~Menu() noexcept
{
	CloseWindow();
}

bool Menu::GameShouldClose() const
{
	return WindowShouldClose();
}