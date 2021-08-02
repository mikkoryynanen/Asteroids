#pragma once

#include "Entity.hpp"
#include "Stats.cpp"

class Player : public Entity
{
public:
	Player() = delete;
	Player(float x, float y, SDL_Texture* tex);
	~Player();

	void Shoot();
	void SetPosition(Vector2 newPosition) override;
	

private:
	Stats _stats;
};

