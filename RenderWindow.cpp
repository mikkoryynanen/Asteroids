#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* title, int width, int height)
	: window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		std::cerr << "Window failed to init. Error " << SDL_GetError() << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer == NULL)
	{
		std::cerr << "Renderer failed to init. Error " << SDL_GetError() << std::endl;
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

RenderWindow::~RenderWindow()
{
	SDL_DestroyWindow(window);
}

SDL_Texture* RenderWindow::LoadTexture(const char* filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, filePath);

	if (texture == NULL)
	{
		std::cerr << "Failed to load texture. Error " << SDL_GetError() << std::endl;
	}

	return texture;
}

const int RenderWindow::GetRefreshRate() const
{
	int displayIndex = SDL_GetWindowDisplayIndex(window);

	SDL_DisplayMode mode;
	SDL_GetDisplayMode(displayIndex, 0, &mode);

	return mode.refresh_rate;
}

void RenderWindow::Clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::Render(Entity& entity)
{
	SDL_Rect src;
	src.x = entity.GetCurrentFrame().x;
	src.y = entity.GetCurrentFrame().y;
	src.w = entity.GetCurrentFrame().w;
	src.h = entity.GetCurrentFrame().h;

	SDL_Rect dst;
	dst.x = entity.GetCurrentPosition().x;
	dst.y = entity.GetCurrentPosition().y;
	dst.w = entity.GetCurrentFrame().w;
	dst.h = entity.GetCurrentFrame().h;

	SDL_RenderCopy(renderer, entity.GetTexture(), &src, &dst);
}

void RenderWindow::Display()
{
	SDL_RenderPresent(renderer);
}
