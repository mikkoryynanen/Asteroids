#pragma once

#include <algorithm>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "Constants.hpp"
#include "Vector2.h"

class Entity
{
public:
	Entity(float x, float y, SDL_Texture* tex);
	~Entity();

	SDL_Texture* GetTexture() const;
	SDL_Rect GetCurrentFrame() const;
	Vector2 GetCurrentPosition() const;

	virtual void SetPosition(Vector2 newPosition);
	virtual void Update();
	
protected:
	Vector2 _vec;
	SDL_Rect _currentFrame;
	SDL_Texture* _texture;
};

