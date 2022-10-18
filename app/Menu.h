#pragma once
#include <string>

class Menu
{
public:
	Menu(int width, int height, std::string title);
	~Menu() noexcept;

	bool GameShouldClose() const;
};