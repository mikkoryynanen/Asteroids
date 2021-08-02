#pragma once

#include <vector>

#include "RenderWindow.hpp"
#include "Utils.h"
#include "Player.h"
#include "Projectile.h"
#include "Constants.hpp"

class Game
{
public:
	Game();
	~Game();

	void Update();
	void AddEntity(Entity& entity);

	const RenderWindow GetWindow() const
	{
		return window;
	}

	const int GetWindowRefreshRate() const
	{
		return windowRefreshRate;
	}

	const bool IsGameRunning() const
	{
		return isRunning;
	}

private:
	RenderWindow window;
	int windowRefreshRate;
	bool isRunning = true;

	Player* player;

	std::vector<Entity*> entities;
};

