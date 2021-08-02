#pragma once

#include "Entity.hpp"
//#include "Stats.cpp"

class Projectile : public Entity
{
public:
	Projectile() = delete;
	Projectile(Vector2 initialPosition, SDL_Texture* tex);
	~Projectile();

	void SetPosition(Vector2 newPosition) override;
	void Update() override;

private:
	//Stats _stats;
	float MovementSpeed;

};

