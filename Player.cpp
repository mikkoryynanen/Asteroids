#include "Player.h"

Player::Player(float x, float y, SDL_Texture* tex)
	: Entity(x, y, tex)
{
	_stats = Stats::LoadStats();
}

Player::~Player()
{
}

void Player::Shoot()
{
}

void Player::SetPosition(Vector2 newPosition)
{
	newPosition.x *= _stats.MovementSpeed;
	newPosition.y *= _stats.MovementSpeed;



	//if (currentPosition.x <= 0 || currentPosition.y <= 0 /*||
	//	newPosition.x > Constants::Width || newPosition.y > Constants::Height*/)
	//{
	//	newPosition.x = 0.1f;
	//	//return;
	//}

	Entity::SetPosition(newPosition);
}