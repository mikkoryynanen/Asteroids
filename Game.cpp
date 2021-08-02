#include "Game.h"


Game::Game()
	: window(RenderWindow("Game", Constants::Width, Constants::Height))
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
	{
		std::cerr << "SDL init failed " << SDL_GetError() << std::endl;
	}

	if (!IMG_Init(IMG_INIT_PNG))
	{
		std::cerr << "SDL_image init failed " << SDL_GetError() << std::endl;
	}

	windowRefreshRate = window.GetRefreshRate();

	SDL_Texture* playerTexture = window.LoadTexture("res/gfx/player.png");
	player = new Player(Constants::Width / 4, Constants::Height / 2, playerTexture);
	entities.push_back(player);

	Update();
}

Game::~Game()
{
	delete player;
}

void Game::Update()
{
	SDL_Event e;
	const float timeStep = 0.01f;
	float accumulator = 0.0f;
	float currentTime = Utils::HireTimeInSeconds();

	while (IsGameRunning())
	{
		int startTicks = SDL_GetTicks();
		float newTime = Utils::HireTimeInSeconds();
		float frameTime = newTime - currentTime;

		currentTime = newTime;
		accumulator += frameTime;

		while (accumulator >= timeStep)
		{
			while (SDL_PollEvent(&e))
			{
				switch (e.type)
				{
				case SDL_QUIT:
					isRunning = false;
					break;
				}
			}

			const Uint8* keyStates = SDL_GetKeyboardState(NULL);
			bool isKeyPressed = false;
			if (keyStates[SDL_SCANCODE_RIGHT] || keyStates[SDL_SCANCODE_D])
			{
				isKeyPressed = true;
				player->SetPosition(Vector2(1 * timeStep, 0));
			}
			if (keyStates[SDL_SCANCODE_LEFT] || keyStates[SDL_SCANCODE_A])
			{
				isKeyPressed = true;
				player->SetPosition(Vector2(-1 * timeStep, 0));
			}
			if (keyStates[SDL_SCANCODE_UP] || keyStates[SDL_SCANCODE_W])
			{
				isKeyPressed = true;
				player->SetPosition(Vector2(0, -1 * timeStep));
			}
			if (keyStates[SDL_SCANCODE_DOWN] || keyStates[SDL_SCANCODE_S])
			{
				isKeyPressed = true;
				player->SetPosition(Vector2(0, 1 * timeStep));
			}

			if (keyStates[SDL_SCANCODE_SPACE])
			{
				SDL_Texture* tex = window.LoadTexture("res/gfx/player.png");
				Projectile* proj = new Projectile(Vector2(player->GetCurrentPosition()), tex);
				entities.push_back(proj);
			}

			accumulator -= timeStep;
		}

		// gets the percentage 
		const float alpha = accumulator / timeStep;

		//std::cout << "Time: " << Utils::HireTimeInSeconds() << std::endl;

		window.Clear();

		for (Entity* e : entities)
		{
			e->Update();
			window.Render(*e);
		}

		window.Display();

		int frameTicks = SDL_GetTicks() - startTicks;
		int rate = 1000 / GetWindowRefreshRate();
		if (frameTicks < rate)
		{
			SDL_Delay(GetWindowRefreshRate() - frameTicks);
		}
	}

	SDL_Quit();
}

void Game::AddEntity(Entity& entity)
{
	entities.push_back(&entity);
}
