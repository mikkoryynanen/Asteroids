#include "Projectile.h"


Projectile::Projectile(Vector2 initialPosition, SDL_Texture* tex)
	: Entity(initialPosition.x, initialPosition.y, tex)
{
	//_stats = Stats::LoadStats();
	MovementSpeed = 50.f;
}

Projectile::~Projectile()
{
}

void Projectile::SetPosition(Vector2 newPosition)
{
	newPosition.x *= MovementSpeed;
	newPosition.y *= MovementSpeed;

	Entity::SetPosition(newPosition);
}

void Projectile::Update()
{
	SetPosition(Vector2(1, 0));
}
