#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Entity.hpp"

class RenderWindow
{
public:
	RenderWindow(const char* title, int width, int height);	
	~RenderWindow();

	SDL_Texture* LoadTexture(const char* filePath);
	const int GetRefreshRate() const;

	void Clear();
	void Render(Entity& entity);
	void Display();
	

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

};